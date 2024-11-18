#include "Shape.hpp"


namespace Netlist{

    using namespace std;

    Shape::Shape(Symbol *s): owner_(s){
        owner_->add(this);
    }

    Shape::~Shape() {owner_->remove(this);}

    Box Shape::getBoundingBox() const {return Box();}

}