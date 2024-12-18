#include "InstancesWidget.hpp"
#include <QHeaderView>
#include <qlineedit.h>
#include <qt5/QtCore/qvariant.h>
//#include <qt5/QtWidgets/qmenu.h>
#include <qtableview.h>
#include <qwidget.h>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "CellViewer.hpp"
#include "CellWidget.hpp"
#include "InstancesModel.hpp"
#include "Symbol.hpp"

#include <iostream>

using namespace std;
namespace Netlist {
InstancesWidget::InstancesWidget(QWidget *parent, CellViewer* cellViewer)
    : QWidget(parent), cellViewer_(NULL), baseModel_(new InstancesModel(this)),
      view_(new QTableView(this)), load_(new QPushButton(this)) {
    

    //cout << "base model cell : " << baseModel_->getModel(0) << endl;
    //cout << "base model row count : " << baseModel_->rowCount() << endl;
    //cout << "base model column count : " << baseModel_->columnCount() << endl;

    cellViewer_ = cellViewer;
    setWindowTitle(tr("Instances"));
    
    setAttribute(Qt::WA_QuitOnClose, false);
    setAttribute(Qt::WA_DeleteOnClose, false);
    setContextMenuPolicy(Qt::ActionsContextMenu);

    view_->setShowGrid(false);
    view_->setAlternatingRowColors(true);
    view_->setSelectionBehavior(QAbstractItemView::SelectRows);
    view_->setSelectionMode(QAbstractItemView::SingleSelection);
    view_->setSortingEnabled(true);
    view_->setModel(baseModel_);  // Associate the model.
    view_->resizeColumnsToContents();
    view_->setColumnWidth(1, 25);

    //add elements to the table

    QHeaderView *horizontalHeader = view_->horizontalHeader();
    horizontalHeader->setDefaultAlignment(Qt::AlignHCenter);
    horizontalHeader->setMinimumSectionSize(100);
    horizontalHeader->setStretchLastSection(true);

    horizontalHeader->setSectionResizeMode(0, QHeaderView::Stretch);

    QHeaderView *verticalHeader = view_->verticalHeader();
    verticalHeader->setVisible(false);
    /*
    QLineEdit * lineEdit_ = new QLineEdit();
    lineEdit_->setMinimumWidth(100);
    lineEdit_->setMinimumHeight(100);*/


    load_->setText("Load");
    load_->setDefault(true);

    //interne
    QHBoxLayout *hLayout = new QHBoxLayout();
    hLayout->addStretch();
    hLayout->addWidget(load_);
    hLayout->addStretch();

    QFrame *separator = new QFrame();
    separator->setFrameShape(QFrame::HLine);
    separator->setFrameShadow(QFrame::Sunken);

    
    //externe
    QVBoxLayout *vLayout = new QVBoxLayout();
    vLayout->setSizeConstraint(QLayout::SetFixedSize);
    vLayout->addWidget(view_);
    //vLayout->addWidget(label);
    //vLayout->addWidget(lineEdit_);
    vLayout->addLayout(hLayout);

    setLayout(vLayout);
    

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
    cout << "selected row is : " << selectedRow << endl;
    
    cellViewer_->setCell(baseModel_->getModel(selectedRow));
}

void InstancesWidget::showI(CellWidget* parent, CellViewer* cellViewer, Cell *cell) {

    InstancesWidget * iwig = new InstancesWidget(NULL, cellViewer);
    iwig->setWindowTitle(tr("Open Cell"));
    iwig->setVisible(true);
    iwig->baseModel_->setCell(cell);
    iwig->activateWindow();
    
    iwig->show();
}//TODO

void InstancesWidget::setCellViewer(CellViewer*c){
    cellViewer_= c;
}



}
