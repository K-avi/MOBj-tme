#include "BoxShape.hpp"

namespace Netlist{

    BoxShape::BoxShape(Symbol * s, const Box & b) : Shape(s), box_(b){}

    BoxShape::~BoxShape(){}

    Box BoxShape::getBoundingBox() const {return box_;}

}