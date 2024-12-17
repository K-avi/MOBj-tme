#ifndef OPENCELLDIALOG_H
#define OPENCELLDIALOG_H

#include <QDialog>
#include <QLineEdit>


namespace Netlist{

class OpenCellDialog : public QDialog {

    Q_OBJECT 
    
    public :

    OpenCellDialog( QWidget* parent=NULL); 
    static bool run (QString& name){
        OpenCellDialog* cell = new OpenCellDialog(NULL);

        int dialogResult = cell->exec();
        name = cell->getCellName();

        delete cell ; 
        return (dialogResult == Accepted);
    }

    const QString getCellName() const; 
    void setCellName(const QString&); 

    protected: 

    QLineEdit* lineEdit_; 
     

};

}

#endif 