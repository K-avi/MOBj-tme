#ifndef CELLS_MODEL_HPP
#define CELLS_MODEL_HPP

#include <QAbstractTableModel>
#include <vector>
#include "Cell.hpp"

namespace Netlist {


class CellsModel : public QAbstractTableModel {
    Q_OBJECT

public:
    CellsModel(QObject *parent = NULL, std::vector<Cell*>* cells = NULL);
    ~CellsModel();
    void setCells(std::vector<Cell*>&);
    Cell *getModel(int row);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

    public slots :
    void updateDatas();


private:
    std::vector<Cell*>& cells_; 
};

}

#endif 