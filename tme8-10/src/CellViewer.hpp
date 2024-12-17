#include <QMainWindow>
#include <cstddef>
#include "SaveCellDialog.hpp"
#include "CellWidget.hpp"
#include "Cell.hpp"

namespace Netlist {


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

        private : 
        CellWidget* cellWidget_;
        SaveCellDialog* saveCellDialog_;

    };
}