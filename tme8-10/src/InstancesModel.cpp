#include "InstancesModel.hpp"

InstancesModel::InstancesModel(QObject *parent)
    : QAbstractTableModel(parent), cell_(NULL) { }

InstancesModel::~InstancesModel() { }

void InstancesModel::setCell(Cell *cell) {
    emit layoutAboutToBeChanged();
    cell_ = cell;
    emit layoutChanged();
}

int InstancesModel::rowCount(const QModelIndex &parent) const {
    return (cell_) ? cell_->getInstances().size() : 0;
}

int InstancesModel::columnCount(const QModelIndex &parent) const {
    return 2;
}

QVariant InstancesModel::data(const QModelIndex &index, int role) const {
    if (!cell_ || !index.isValid()) return QVariant();
    
    if (role == Qt::DisplayRole) {
        int row = index.row();
        switch (index.column()) {
            case 0: return cell_->getInstances()[row]->getName().c_str();
            case 1: return cell_->getInstances()[row]->getMasterCell()->getName().c_str();
        }
    }
    return QVariant();
}

QVariant InstancesModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (orientation == Qt::Vertical) return QVariant();
    if (role != Qt::DisplayRole) return QVariant();
    
    switch (section) {
        case 0: return "Instance";
        case 1: return "MasterCell";
    }
    return QVariant();
}

Cell *InstancesModel::getModel(int row) {
    if (!cell_) return NULL;
    if (row >= (int)cell_->getInstances().size()) return NULL;
    return cell_->getInstances()[row]->getMasterCell();
}

class InstancesWidget : public QWidget {
    Q_OBJECT

public:
    InstancesWidget(QWidget *parent = NULL);
    void setCellViewer(CellViewer *);
    int getSelectedRow() const;
    inline void setCell(Cell *);

public slots:
    void load();

private:
    CellViewer *cellViewer_;
    InstancesModel *baseModel_;
    QTableView *view_;
    QPushButton *load_;
};

InstancesWidget::InstancesWidget(QWidget *parent)
    : QWidget(parent), cellViewer_(NULL), baseModel_(new InstancesModel(this)),
      view_(new QTableView(this)), load_(new QPushButton(this)) {

    setAttribute(Qt::WA_QuitOnClose, false);
    setAttribute(Qt::WA_DeleteOnClose, false);
    setContextMenuPolicy(Qt::ActionsContextMenu);

    view_->setShowGrid(false);
    view_->setAlternatingRowColors(true);
    view_->setSelectionBehavior(QAbstractItemView::SelectRows);
    view_->setSelectionMode(QAbstractItemView::SingleSelection);
    view_->setSortingEnabled(true);
    view_->setModel(baseModel_);  // Associate the model.

    QHeaderView *horizontalHeader = view_->horizontalHeader();
    horizontalHeader->setDefaultAlignment(Qt::AlignHCenter);
    horizontalHeader->setMinimumSectionSize(300);
    horizontalHeader->setStretchLastSection(true);

    QHeaderView *verticalHeader = view_->verticalHeader();
    verticalHeader->setVisible(false);

    load_->setText("Load");
    connect(load_, SIGNAL(clicked()), this, SLOT(load()));
}

int InstancesWidget::getSelectedRow() const {
    QModelIndexList selecteds = view_->selectionModel()->selection().indexes();
    if (selecteds.empty()) return -1;
    return selecteds.first().row();
}

void InstancesWidget::load() {
    int selectedRow = getSelectedRow();
    if (selectedRow < 0) return;
    cellViewer_->setCell(baseModel_->getModel(selectedRow));
}

