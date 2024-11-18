#include "Shape.hpp"
#include "Term.hpp"
#include "Box.hpp"
#include "Line.hpp"


namespace Netlist{

    using namespace std;

    //Shape Methods
    Shape::Shape(Symbol *s): owner_(s){
        owner_->add(this);
    }

    Shape::~Shape() {owner_->remove(this);}

    Box Shape::getBoundingBox() const {return Box();}
    
    //BoxShape Methods
    BoxShape::BoxShape(Symbol * s, const Box & b) : Shape(s), box_(b){}

    BoxShape::~BoxShape(){}

    Box BoxShape::getBoundingBox() const {return box_;}

    //LineShape Methods
    LineShape::LineShape(Symbol * s, const Line & l, int x1, int y1, int x2, int y2) : Shape(s), line_(l),x1_(x1), y1_(y1), x2_(x2), y2_(y2){}

    LineShape::~LineShape(){}

    Box LineShape::getBoundingBox() const{
        return Box(x1_, y1_, x2_, y2_);
    }
    
    //TermShape Methods
    TermShape::TermShape(Symbol * s, string name, int x1, int y1): Shape(s), term_(nullptr), x1_(x1), y1_(y1){
        s->add(this);
        Cell * cell = owner_->getCell();
        term_ = cell->getTerm(name);
    }

    TermShape::~TermShape(){}

    /*Box TermShape::getBoundingBox() const{
        return Box(x1_, y1_).inflate(5,5);
    }*/

    int TermShape::getX1() const{return x1_;}
    int TermShape::getY1() const{return y1_;}

}
