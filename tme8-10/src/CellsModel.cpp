#include "CellsModel.hpp"
#include "Cell.hpp"
#include <iostream>
#include <QAbstractTableModel>
#include <iostream>

using namespace std;

namespace Netlist{ 
CellsModel::CellsModel(QObject *parent, std::vector<Cell*>* cells)
    : QAbstractTableModel(parent), cells_(Cell::getAllCells()) {
}

CellsModel::~CellsModel() { }

void CellsModel::setCells(std::vector<Cell*>& cells) {

    //cout << "cell ptr is : " << cell << endl;
    emit layoutAboutToBeChanged();
    cells_ = cells;
    emit layoutChanged();
}

int CellsModel::rowCount(const QModelIndex &parent) const {
    return cells_.size();
}

int CellsModel::columnCount(const QModelIndex &parent) const {
    return 1;
}

QVariant CellsModel::data(const QModelIndex &index, int role) const {
    if (!cells_.size() || !index.isValid()){
       // cout << "invalid data" << endl;
         return QVariant();
    }
    
    if (role == Qt::DisplayRole) {
        //cout << "in data" << endl;
        int row = index.row();
        return cells_[row]->getName().c_str();
    }
    return QVariant();
}

QVariant CellsModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (orientation == Qt::Vertical) return QVariant();
    if (role != Qt::DisplayRole) return QVariant();
    
    return "Cell";
}

Cell* CellsModel::getModel(int row) {
    if (!cells_.size()) return NULL;
    if (row >= (int)cells_.size()) return NULL;
    return cells_[row];
}

void CellsModel::updateDatas() {
    emit layoutAboutToBeChanged();
    cells_ = Cell::getAllCells();
    emit layoutChanged();
}


/*
Cell *CellsModel::getModel(int row) {
    if (!cells_) return NULL;
    if (row >= (int)cell_->getCells().size()) return NULL;
    return cell_->getCells()[row]->getMasterCell();
}*/

}
