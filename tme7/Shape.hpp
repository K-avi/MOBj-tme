#include "Box.hpp"
#include "Symbol.hpp"

namespace Netlist{

    class Shape{
        public:
            Shape(Symbol *s);
            ~Shape();
            virtual Box getBoundingBox() const = 0;
        private:
            Symbol * owner_;
    };

}