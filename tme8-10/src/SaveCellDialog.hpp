#include <QDialog>
#include <QLineEdit>

class SaveCellDialog : public QDialog {

    Q_OBJECT ; 
    
    public :

    SaveCellDialog( QWidget* parent=NULL); 
    bool run (QString& name); 

    const QString getCellName() const ; 

    protected: 

    QlineEdit* lineEdit_; 
     

}
