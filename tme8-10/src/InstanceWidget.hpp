#ifndef INSTANCE_WIDGET_H
#define INSTANCE_WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QTableView>
#include <qt5/QtCore/qobjectdefs.h>
#include "InstanceModel.hpp"
#include "CellViewer.hpp"

namespace Netlist {

    class InstanceWidget : public QWidget{
        Q_OBJECT 

        public: 
            InstanceWidget (QWidget* parent=NULL);
            void setCellViewer(CellViewer*);
            int getSelectedRow() const; 
            inline void setCell(Cell*);

        public slots: 
            void load(); 

        private : 
            CellViewer* cellViewer_; 
            InstancesModel* baseModel_; 
            QTableView* view_; 
            QPushButton* load_;
    };
}

#endif 