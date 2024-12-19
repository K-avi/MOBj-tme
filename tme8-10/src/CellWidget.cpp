// -*- explicit-buffer-name: "CellWidget.cpp<M1-MOBJ/8-10>" -*-

#include  <QResizeEvent>
#include  <QPainter>
#include  <QPen>
#include  <QBrush>
#include  <QFont>
#include  <QApplication>
#include <qpainter.h>
#include <qt5/QtCore/qnamespace.h>
#include <qt5/QtGui/qbrush.h>
#include <qt5/QtGui/qfont.h>
#include  "CellWidget.hpp"
#include "Box.hpp"
#include  "Instance.hpp"
#include "Point.hpp"
#include  "Symbol.hpp"
#include  "Shape.hpp"
#include  "Cell.hpp"
#include "Term.hpp"

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
  {//the actual method that will draw the cell 
  //get the symbol of the cell ; get the shapes of the symbol ; draw the shapes
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

/*
  void CellWidget::drawTerm(Term* term, QPainter& painter) {
    QFont  bigFont = QFont( "URW Bookman L", 12 );
    

    QString cellName = "NULL";
    if (cell_) cellName = cell_->getName().c_str();

    int frameWidth  = 460;
    int frameHeight = 100;
    QRect nameRect ( (size().width ()-frameWidth )/2
                   , (size().height()-frameHeight)/2
                   , frameWidth
                   , frameHeight
                   );
    //draw the cell
    if (cell_) {
        for(auto & s : cell_->getSymbol()->getShapes()){
            BoxShape* boxShape = dynamic_cast<BoxShape*>(s);
            if (boxShape) {
                Box box = boxShape->getBoundingBox();
                painter.drawRect(boxToScreenRect(box));
            } else if (LineShape* lineShape = dynamic_cast<LineShape*>(s)) {
                Box box = lineShape->getBoundingBox();
                Point p1 = Point(box.getX1(), box.getY1());
                Point p2 = Point(box.getX2(), box.getY2());
                painter.drawLine(pointToScreenPoint(p1), pointToScreenPoint(p2));
            } else if (EllipseShape* ellipseShape = dynamic_cast<EllipseShape*>(s)) {
                Box box = ellipseShape->getBoundingBox();
                painter.drawEllipse(boxToScreenRect(box));
            } else if (ArcShape* arcShape = dynamic_cast<ArcShape*>(s)) {
                Box box = arcShape->getBoundingBox();
                painter.drawArc(boxToScreenRect(box), arcShape->getStart(), arcShape->getSpan());
            } else if (TermShape* termShape = dynamic_cast<TermShape*>(s)) {
                Term* term = termShape->getTerm();
                if (!term) continue;
                Point termPos = cell_->getSymbol()->getTermPosition(term);
                drawTerm(term, painter);
                painter.drawText(pointToScreenPoint(termPos), term->getName().c_str());

            }
        }
        painter.drawRect(boxToScreenRect(cell_->getSymbol()->getBoundingBox()));
        
    }
  }*/



  void  CellWidget::paintEvent ( QPaintEvent* event )
  {
    
    QFont  bigFont = QFont( "URW Bookman L", 12 );

    QString cellName = "NULL";
    if (cell_) cellName = cell_->getName().c_str();

    QPainter painter(this);
    painter.setFont      ( bigFont );
    painter.setBackground( QBrush( Qt::white ) );
    painter.eraseRect    ( QRect( QPoint(0,0), size() ) );

    //int frameWidth  = 460;
    //int frameHeight = 100;
    /*QRect nameRect ( (size().width ()-frameWidth )/2
                   , (size().height()-frameHeight)/2
                   , frameWidth
                   , frameHeight
                   );
                   */
    painter.setPen  ( Qt::black );
    //painter.drawRect( nameRect);
    //painter.drawText( nameRect, Qt::AlignCenter, cellName );*/


    //draw the symbol of the cell
    if (cell_) {
        painter.setPen(Qt::black);
       // painter.setBrush(Qt::black);
        for(auto & s : cell_->getSymbol()->getShapes()){
            BoxShape* boxShape = dynamic_cast<BoxShape*>(s);
            if (boxShape) {
                painter.setPen(Qt::black);
                Box box = boxShape->getBoundingBox();
                painter.drawRect(boxToScreenRect(box));
                
            } else if (LineShape* lineShape = dynamic_cast<LineShape*>(s)) {
                cout << "Drawing line: " <<  endl;
                painter.setPen(Qt::blue);
                Box box = lineShape->getBoundingBox();
                
                //box.translate(bref.getX1(), bref.getY1());

                Point p1 = Point(box.getX1(), box.getY1());
                Point p2 = Point(box.getX2(), box.getY2());
                painter.drawLine(pointToScreenPoint(p1), pointToScreenPoint(p2));
            } else if (EllipseShape* ellipseShape = dynamic_cast<EllipseShape*>(s)) {
                
                cout << "Drawing ellipse: " <<  endl;
                painter.setPen(Qt::red);
                Box box = ellipseShape->getBoundingBox();
                painter.drawEllipse(boxToScreenRect(box));


            } else if (ArcShape* arcShape = dynamic_cast<ArcShape*>(s)) {
                painter.setPen(Qt::red);
                Box box = arcShape->getBoundingBox();
                painter.drawArc(boxToScreenRect(box), arcShape->getStart()*16, arcShape->getSpan()*16);
            } else if (TermShape* termShape = dynamic_cast<TermShape*>(s)) {
                painter.setPen(Qt::yellow);
                Term* term = termShape->getTerm();
                if (!term) continue;
                painter.drawText(pointToScreenPoint(Point(termShape->getX1(),termShape->getY1())), term->getName().c_str());
            }
        }
      //  painter.setPen(Qt::black);
      //  painter.fillRect(boxToScreenRect(cell_->getSymbol()->getBoundingBox()), QBrush(QColor(128,128,255,128)));
      //  painter.drawRect(boxToScreenRect(cell_->getSymbol()->getBoundingBox()));
        
    }
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
  void CellWidget::goLeft() {
      viewport_.translate(Point(-20, 0));
      repaint();
  }

  void CellWidget::goUp() {
      viewport_.translate(Point(0, 20));
      repaint();
  }

  void CellWidget::goDown() {
      viewport_.translate(Point(0, -20));
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
