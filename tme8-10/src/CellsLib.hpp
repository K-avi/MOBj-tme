#ifndef CELL_LIB_HPP
#define CELL_LIB_HPP

#include <QWidget>
#include <qpushbutton.h>
#include "CellsModel.hpp"
#include "CellViewer.hpp"
#include "Symbol.hpp"
#include <QTableView>

namespace Netlist{
    class CellsLib : public QWidget {
        Q_OBJECT

        public : 
            CellsLib(QWidget* parent = NULL, CellViewer* cellViewer = NULL);
            void setCellViewer(CellViewer*);
            int getSelectedRow() const;
            inline CellsModel* getBaseModel(){return baseModel_;}

            static void showCells(CellViewer*);

        public slots: 
            void load();
        
        private :   
            CellsModel* baseModel_;
            CellViewer* cellViewer_;
            QTableView* view_;
            QPushButton* load_;
    };
}

#endif 