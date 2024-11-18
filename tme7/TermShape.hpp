#include "Shape.hpp"
#include "Term.hpp"

namespace Netlist{

    class TermShape : public Shape{
        public:
            TermShape(Symbol*, std::string, int, int);
            ~TermShape();
            virtual Box getBoundingBox() const = 0;
            Term * getTerm() const;
            int getX1() const;
            int getY1() const;
        private:
            Symbol * owner_;
            Term * term_;
            int x1_,y1_;

    };

}