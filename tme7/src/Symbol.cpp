#include "Symbol.hpp"
#include "Term.hpp"
#include "TermShape.hpp"

namespace Netlist {

    using namespace std;

    Symbol::Symbol(Cell * c): owner_(c){}

    Symbol::~Symbol(){}

    Cell * Symbol::getCell() const {return owner_;}

    //Box Symbol::getBoundingBox() const {}

    Point Symbol::getTermPosition(Term * t) const{
        return t->getPosition();
    }

    TermShape* Symbol::getTermShape(Term * t) const {
        Point p = t->getPosition();
        string name = t->getName();
        
        return new TermShape(this, name, p.getX(), p.getY());

    }

}