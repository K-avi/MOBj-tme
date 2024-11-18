#include "LineShape.hpp"

namespace Netlist {

    LineShape::LineShape(Symbol * s, const Line & l, int x1, int y1, int x2, int y2) : Shape(s), line_(l),x1_(x1), y1_(y1), x2_(x2), y2_(y2){}

    LineShape::~LineShape(){}

    Box LineShape::getBoundingBox() const{
        return Box(x1_, y1_, x2_, y2_);
    }

}