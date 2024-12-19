// -*- explicit-buffer-name: "CellWidget.cpp<M1-MOBJ/8-10>" -*-

#include  <QResizeEvent>
#include  <QPainter>
#include  <QPen>
#include  <QBrush>
#include  <QFont>
#include  <QApplication>
#include <qpainter.h>
#include <qt5/QtCore/qline.h>
#include <qt5/QtCore/qnamespace.h>
#include <qt5/QtCore/qpoint.h>
#include <qt5/QtGui/qbrush.h>
#include <qt5/QtGui/qfont.h>
#include  "CellWidget.hpp"
#include "Box.hpp"
#include  "Instance.hpp"
#include "Node.hpp"
#include "Point.hpp"
#include  "Symbol.hpp"
#include  "Shape.hpp"
#include  "Cell.hpp"
#include "Term.hpp"
#include "Net.hpp"
#include "Line.hpp"

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


void centerPoint(Point* p){
    p->translate(Point(100, 100));
}

void centerBox(Box* b){
    b->translate(Point(100, 100));
}


void CellWidget::paintSymbol(QPainter* painter, Cell* mastercell, Point& translation){
    QFont  bigFont = QFont( "URW Bookman L", 12 );
    QString cellName = "NULL";
    if (mastercell) cellName = mastercell->getName().c_str();


    QPen pen = painter->pen();
    pen.setWidth(3);
    pen.setColor(Qt::green);
    painter->setPen(pen);

    //draw the symbol of the cell
    if (mastercell) {
        for(auto & s : mastercell->getSymbol()->getShapes()){
            BoxShape* boxShape = dynamic_cast<BoxShape*>(s);
            if (boxShape) {
            
                Box box = boxShape->getBoundingBox();
                box.translate(translation);
                painter->drawRect(boxToScreenRect(box));
                
            } else if (LineShape* lineShape = dynamic_cast<LineShape*>(s)) {
             
                Box box = lineShape->getBoundingBox();
                box.translate(translation);
                
                Point p1 = Point(box.getX1(), box.getY1());
                Point p2 = Point(box.getX2(), box.getY2());
                painter->drawLine(pointToScreenPoint(p1), pointToScreenPoint(p2));
            } else if (EllipseShape* ellipseShape = dynamic_cast<EllipseShape*>(s)) {
                       
                Box box = ellipseShape->getBoundingBox();
                box.translate(translation);
                painter->drawEllipse(boxToScreenRect(box));
            } else if (ArcShape* arcShape = dynamic_cast<ArcShape*>(s)) {  
                Box box = arcShape->getBoundingBox();
                box.translate(translation);
                painter->drawArc(boxToScreenRect(box), arcShape->getStart()*16, arcShape->getSpan()*16);
            }
        }

        pen.setColor(Qt::red);
        pen.setWidth(1);
        pen.setBrush(Qt::red);
        painter->setPen(pen);

        for(auto & s : mastercell->getSymbol()->getShapes()){
            if (TermShape* termShape = dynamic_cast<TermShape*>(s)) {

                pen.setColor(Qt::red);
                pen.setBrush(Qt::red);
                painter->setPen(pen);
                  
                Term* term = termShape->getTerm();
                if (!term) continue;
                Point p = Point(termShape->getX1(), termShape->getY1());
                p.translate(translation);
                //centerPoint(&p);
                p.setY(p.getY() + 10);

                Box box = termShape->getBoundingBox();
                //centerBox(&box);
                box.translate(translation);


                painter->drawRect(boxToScreenRect(box));
                pen.setColor(Qt::black);
                painter->setPen(pen);
                painter->drawText(pointToScreenPoint(p), term->getName().c_str());      
            }
        }
    }
}

void  CellWidget::paintEvent ( QPaintEvent* event ){
    QFont  bigFont = QFont( "URW Bookman L", 12 );
    QString cellName = "NULL";
    if (cell_) cellName = cell_->getName().c_str();

    QPainter painter(this);
    painter.setFont      ( bigFont );
    painter.setBackground( QBrush( Qt::white ) );
    painter.eraseRect    ( QRect( QPoint(0,0), size() ) );

    painter.setPen  ( Qt::black );
    
    //draw the symbol of the cell
    for(auto & net : cell_->getNets()){
       
        for(auto * line : net->getLines()){

            painter.setPen(Qt::blue);
            
            Point p1 = line->getSourcePosition();
            centerPoint(&p1);
            Point p2 = line->getTargetPosition();
            centerPoint(&p2);

            painter.setPen(Qt::blue);
            painter.drawLine(pointToScreenPoint(p1), pointToScreenPoint(p2));

            for(auto* line2 : net->getLines()){
                if(line == line2) continue;
                if( (line->getSourcePosition() == line2->getSourcePosition()) && !(line->getTargetPosition() == line2->getTargetPosition()) ){
                    painter.setPen(Qt::blue);
                    painter.setBrush(Qt::blue);

                    Point p = line->getSourcePosition();
                    centerPoint(&p);

                    painter.drawEllipse(pointToScreenPoint(p), 5, 5);
                }
            }

        }
        //draw every node of the net 
        for(auto * node : net->getNodes()){

            //nodes are either terms or point so we need to cast them to the right type
            NodePoint* np = dynamic_cast<NodePoint*>(node);
            NodeTerm* nt = dynamic_cast<NodeTerm*>(node);
            if(np){//a point simply contains it's coordinates in the net so we draw it
                Point p = np->getPosition();
                centerPoint(&p);

                painter.setPen(Qt::black);
                painter.drawPoint(pointToScreenPoint(p));
            }else if(nt){//a term is either an instance of a cell or a "internal terminal??" 
            //if the term is an instance we need to draw it's associated symbol 
            //if it's a terminal we need to draw it's name at it's position
                Term* t = nt->getTerm();
                
                if(t->getInstance()){
                    
                    //get the instance of the term
                    Instance* i = t->getInstance();
                    //get the symbol of the instance
                    Cell* mastercell = i->getMasterCell();
                    //get the shapes of the symbol
                    Point p = i->getPosition();
                    centerPoint(&p);


                    QPen pencopy = painter.pen();
                    paintSymbol(&painter, mastercell, p);

                    painter.setPen(pencopy);

                }else{
                    //find the term in the cell 
                    Term* term = cell_->getTerm(t->getName());
                    //draw the name of the term at it's position in the cell's thing
                    painter.setPen(Qt::red);
                    painter.setBrush(Qt::red);

                    Point p = term->getPosition();
                    centerPoint(&p);
                    Box box = Box(p.getX(), p.getY(), p.getX() , p.getY());

                    p.translate(Point(0, 12));
                    painter.drawText(pointToScreenPoint(p), term->getName().c_str());

                    box.inflate(10);
                    painter.drawRect(boxToScreenRect(box));
                }

                
            }     
        }  
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

  void CellWidget::goLeft() {
      viewport_.translate(Point(20, 0));
      repaint();
  }
  void CellWidget::goRight() {
      viewport_.translate(Point(-20, 0));
      repaint();
  }

  void CellWidget::goDown() {
      viewport_.translate(Point(0, 20));
      repaint();
  }

  void CellWidget::goUp() {
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
