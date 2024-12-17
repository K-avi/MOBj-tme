// -*- explicit-buffer-name: "CellWidget.cpp<M1-MOBJ/8-10>" -*-

#include  <QResizeEvent>
#include  <QPainter>
#include  <QPen>
#include  <QBrush>
#include  <QFont>
#include  <QApplication>
#include  "CellWidget.hpp"
#include  "Term.hpp"
#include  "Instance.hpp"
#include  "Symbol.hpp"
#include  "Shape.hpp"
#include  "Cell.hpp"
#include  "Line.hpp"
#include  "Node.hpp"
#include  "Net.hpp"


namespace Netlist {

  using namespace std;


  ostream& operator<< ( ostream& o, const QRect& rect )
  {
    o << "<QRect x:" << rect.x()
      <<       " y:" << rect.y()
      <<       " w:" << rect.width()
      <<       " h:" << rect.height() << ">";
    return o;
  }


  ostream& operator<< ( ostream& o, const QPoint& p )
  { o << "<QRect x:" << p.x() << " y:" << p.y() << ">"; return o; }



  CellWidget::CellWidget(QWidget *parent)
    : QWidget(parent), cell_(NULL), viewport_(Box(0, 0, 500, 500)) {

        setAttribute(Qt::WA_OpaquePaintEvent);
        setAttribute(Qt::WA_NoSystemBackground);
        setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding); // X and Y direction.
        setFocusPolicy(Qt::StrongFocus);
        setMouseTracking(true);
    }



  CellWidget::~CellWidget ()
  { }


  void  CellWidget::setCell ( Cell* cell )
  {
    cell_ = cell;
    repaint();
  }

  
  QSize CellWidget::minimumSizeHint() const {
    return QSize(500, 500);
  }

  void CellWidget::resizeEvent(QResizeEvent *event) {
      const QSize &size = event->size();

      // Assume the resize is always done by drawing the bottom right corner.
      viewport_.setX2(viewport_.getX1() + size.width());
      viewport_.setY1(viewport_.getY2() - size.height());

      std::cerr << "CellWidget::resizeEvent() viewport_: " << viewport_ << std::endl;
  }


  void  CellWidget::paintEvent ( QPaintEvent* event )
  {
    QFont  bigFont = QFont( "URW Bookman L", 36 );

    QString cellName = "NULL";
    if (cell_) cellName = cell_->getName().c_str();

    QPainter painter(this);
    painter.setFont      ( bigFont );
    painter.setBackground( QBrush( Qt::black ) );
    painter.eraseRect    ( QRect( QPoint(0,0), size() ) );

    int frameWidth  = 460;
    int frameHeight = 100;
    QRect nameRect ( (size().width ()-frameWidth )/2
                   , (size().height()-frameHeight)/2
                   , frameWidth
                   , frameHeight
                   );

    painter.drawRect( nameRect );
    painter.drawText( nameRect, Qt::AlignCenter, cellName );
  }
  
  void CellWidget::keyPressEvent(QKeyEvent* event) {
    event->ignore();

    if (event->modifiers() & (Qt::ControlModifier | Qt::ShiftModifier)) {
        return;
    }

    switch (event->key()) {
        case Qt::Key_Up:
            goUp();
            break;
        case Qt::Key_Down:
            goDown();
            break;
        case Qt::Key_Left:
            goLeft();
            break;
        case Qt::Key_Right:
            goRight();
            break;
        default:
            return;
    }

    event->accept();
  }

  void CellWidget::goRight() {
      viewport_.translate(Point(20, 0));
      repaint();
  }

  void CellWidget::goUp() {
      viewport_.translate(Point(0, 20));
      repaint();
  }
  
  void CellWidget::query(unsigned int flags, QPainter& painter) {
    if (!cell_ || !flags) return;

    const vector<Instance*>& instances = cell_->getInstances();
    for (size_t i = 0; i < instances.size(); ++i) {
        Point instPos = instances[i]->getPosition();
        const Symbol* symbol = instances[i]->getMasterCell()->getSymbol();
        if (!symbol) continue;

        if (flags & InstanceShapes) {
            const vector<Shape*>& shapes = symbol->getShapes();
            for (size_t j = 0; j < shapes.size(); ++j) {
                BoxShape* boxShape = dynamic_cast<BoxShape*>(shapes[j]);
                if (boxShape) {
                    Box box = boxShape->getBoundingBox();
                    QRect rect = boxToScreenRect(box.translate(instPos));
                    painter.drawRect(rect);
                }
            }
        }
    }
}



}  // Netlist namespace.
