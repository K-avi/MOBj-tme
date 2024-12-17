#include "CellViewer.hpp"
#include <QMenuBar>
#include <qt5/QtCore/qobjectdefs.h>
#include <qwidget.h>
#include <iostream>
#include "OpenCellDialog.hpp"

using namespace Netlist;
using namespace std; 
namespace Netlist{

CellViewer::CellViewer(QWidget* parent)
    : QMainWindow(parent)
    , cellWidget_(NULL)
    , saveCellDialog_(NULL)
{   


    cellWidget_ = new CellWidget();
    saveCellDialog_ = new SaveCellDialog(this);
    setCentralWidget(cellWidget_);

    QMenu* fileMenu = menuBar()->addMenu("&File");
  //  QAction* action = fileMenu->addAction("&Save As...", this);
    QAction* action = fileMenu->addAction("&Save As...");

    action->setStatusTip("Save to disk (rename) the current cell");
    action->setShortcut(QKeySequence("CTRL+S"));
    action->setVisible(true);
    fileMenu->addAction(action);

    connect(action, SIGNAL(triggered()), this, SLOT(saveCell()));


    action = new QAction("Open", this);
    action->setStatusTip("Open a cell");
    action->setShortcut(QKeySequence("CTRL+O"));
    action->setVisible(true);
    fileMenu->addAction(action);
    connect(action, SIGNAL(triggered()), this, SLOT(openCell()));


    action = new QAction("Quit", this);
    action->setStatusTip("Exit the Netlist Viewer");
    action->setShortcut(QKeySequence("CTRL+Q"));
    action->setVisible(true);
    fileMenu->addAction(action);
    connect(action, SIGNAL(triggered()), this, SLOT(quit()));

    

    setWindowTitle("CellViewer");
}

void CellViewer::quit(){
    close();
}

void CellViewer::openCell()
{
    QString cellName;
    if(OpenCellDialog::run(cellName))
    {
        Cell* cell = Cell::find(cellName.toStdString());
        if(cell == NULL)
        {
            cell = Cell::load(cellName.toStdString());
        }
        if(cell != NULL)
        {
            setCell(cell);
        }
    }
}

Cell* CellViewer::getCell() const
{
    return cellWidget_->getCell();
}

void CellViewer::setCell(Cell* cell)
{
    cellWidget_->setCell(cell);
}

void CellViewer::saveCell()
{
    Cell* cell = getCell();
    if(cell == NULL){
        cout << "CellViewer::saveCell() : getCell() a renvoye null" << endl;
        return;
    }

    QString cellName = cell->getName().c_str();
    if(saveCellDialog_->run(cellName))
    {
        cell->setName(cellName.toStdString());
        cell->save(cellName.toStdString());
    }else{
        cout << "CellViewer::saveCell() : saveCellDialog_->run() a renvoye faux" << endl;
    }
}

}