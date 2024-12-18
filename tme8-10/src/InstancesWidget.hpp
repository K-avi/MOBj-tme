#ifndef INSTANCE_WIDGET_H
#define INSTANCE_WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QTableView>
#include <qdialog.h>
#include <qt5/QtCore/qobjectdefs.h>
#include "CellWidget.hpp"
#include "InstancesModel.hpp"
#include "CellViewer.hpp"
#include <QDialog>
#include <qwidget.h>

namespace Netlist {

    class InstancesWidget : public QWidget{ 
        Q_OBJECT 

        public: 
            InstancesWidget (QWidget* parent=NULL, CellViewer* cellViewer=NULL);
            void setCellViewer(CellViewer*);
            int getSelectedRow() const; 
            inline void setCell(Cell*);

        public slots: 
            void load(); 
            static void showI(CellWidget* parent, CellViewer* cellViewer, Cell* cell);

        private : 
            CellViewer* cellViewer_; 
            InstancesModel* baseModel_; 
            QTableView* view_; 
            QPushButton* load_;
    };
}

#endif 
