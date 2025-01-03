#ifndef CELL_VIEWER_H
#define CELL_VIEWER_H

#include <QMainWindow>
#include <cstddef>
#include "SaveCellDialog.hpp"
#include "CellWidget.hpp"
#include "Cell.hpp"


namespace Netlist {

    class CellsLib;
    class CellViewer : public QMainWindow
    {
    Q_OBJECT
    

    public:
        CellViewer(QWidget* parent = NULL);

        //virtual ~CellViewer(); 
        //~CellViewer(); 

        void setCell(Netlist::Cell*); 
        Cell* getCell() const;
        

        public slots :
        void saveCell();
        void quit();
        void openCell();
        void showInstancesWidget();
        void showCells();
        void updateData();

        signals :
        void cellLoaded();
       


        private : 
        CellWidget* cellWidget_;
        SaveCellDialog* saveCellDialog_;
        //InstancesWidget* instanceWidget_;
        CellsLib* cellsLib_;

    };
}

#endif
