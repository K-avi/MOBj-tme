#include "Shape.hpp"

namespace Netlist{

    class BoxShape : public Shape{
        public:
            BoxShape(Symbol *, const Box &);
            ~BoxShape();
            virtual Box getBoundingBox() const = 0;
        private:
            Box box_;
    };

}