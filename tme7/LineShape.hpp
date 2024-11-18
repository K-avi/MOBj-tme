#include "Shape.hpp"
#include "Line.hpp"

namespace Netlist{

    class LineShape : public Shape{
        public :
            LineShape(Symbol *, const Line &, int, int, int, int);
            ~LineShape();
            virtual Box getBoundingBox() const = 0;
        
        private:
            int x1_, y1_, x2_, y2_;
            const Line & line_;
    };
}