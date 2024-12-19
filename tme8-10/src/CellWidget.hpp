// -*- explicit-buffer-name: "CellWidget.h<M1-MOBJ/8-10>" -*-

#ifndef NETLIST_CELL_WIDGET_H
#define NETLIST_CELL_WIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QPainter>
#include <QRect>
#include <QPoint>
#include "Box.hpp"
#include "Term.hpp"

class QPainter;

namespace Netlist {
  
  class Cell;
  class NodeTerm;


  class CellWidget : public QWidget {
    Q_OBJECT

    public:
        CellWidget(QWidget *parent = NULL);
        virtual ~CellWidget();
        
        void setCell(Cell *);
        inline Cell *getCell() const;
        
        inline QRect boxToScreenRect(const Box & box) const {

          int x1 = xToScreenX(box.getX1());
          int y1 = yToScreenY(box.getY2());
          

          int width = box.getWidth();
          int height = box.getHeight();

          return QRect(x1,y1,width,height);
        }


        inline QPoint pointToScreenPoint(const Point & point) const {

          int x = xToScreenX(point.getX());
          int y = yToScreenY(point.getY());
        
          return QPoint(x,y);
        }
        inline Box screenRectToBox(const QRect & rect) const{ 
          return Box(screenXToX(rect.x()), screenYToY(rect.y() + rect.height()), screenXToX(rect.x() + rect.width()), screenYToY(rect.y()));
        }
        inline Point screenPointToPoint(const QPoint & point) const {
          return Point(screenXToX(point.x()), screenYToY(point.y()));
        }

        inline  int     xToScreenX  ( int x ) const {return x - viewport_.getX1();};
        inline  int     yToScreenY  ( int y ) const {return viewport_.getY2() - y;};
        inline  int     screenXToX  ( int x ) const {return x + viewport_.getX1();}
        inline  int     screenYToY  ( int y ) const {return y + viewport_.getY1();}
        
        virtual QSize minimumSizeHint() const;
        virtual void resizeEvent(QResizeEvent *);
        void query(unsigned int flags, QPainter& painter);

    public slots:
        void goRight();
        void goLeft();
        void goUp();
        void goDown();

        

    protected:
        virtual void paintEvent(QPaintEvent *);
        virtual void keyPressEvent(QKeyEvent *);

    private:
        Cell *cell_;
        Box viewport_;
        unsigned InstanceShapes;
       void paintSymbol(QPainter* qpainter, Cell* event, Point& translation);
    };



  inline Cell* CellWidget::getCell () const { return cell_; }


}  // Netlist namespace.

#endif  // NETLIST_CELL_WIDGET_H
