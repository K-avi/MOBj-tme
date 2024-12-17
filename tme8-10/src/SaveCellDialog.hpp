#include <QDialog>
#include <QLineEdit>

namespace Netlist{

class SaveCellDialog : public QDialog {

    Q_OBJECT 
    
    public :

    SaveCellDialog( QWidget* parent=NULL); 
    void setCellName(const QString &name);
    bool run (QString& name); 

    const QString getCellName() const ; 

    protected: 

    QLineEdit* lineEdit_; 

};

}