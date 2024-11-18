#include "TermShape.hpp"

namespace Netlist{

    using namespace std;

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