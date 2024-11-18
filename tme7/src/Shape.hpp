#include "Box.hpp"
#include "Symbol.hpp"

namespace Netlist{

    class Term;
    class Line;
    class Box;

    class Shape{
        public:
            Shape(Symbol *s);
            ~Shape();
            virtual Box getBoundingBox() const = 0;
            static Shape* fromXml(Symbol* owner, xmlTextReaderPtr readerptr);
        //protected so that it can be accessed by derived classes
       	protected:
            Symbol * owner_;
    };
    
    class BoxShape : public Shape{
        public:
            BoxShape(Symbol *, const Box &);
            ~BoxShape();
            virtual Box getBoundingBox() const;
            static BoxShape* fromXml(Symbol* owner, xmlTextReaderPtr readerptr);
        private:
            Box box_;
    };
    
    class LineShape : public Shape{
        public :
            LineShape(Symbol *, const Line &, int, int, int, int);
            ~LineShape();
            virtual Box getBoundingBox() const;
            static LineShape* fromXml(Symbol* owner, xmlTextReaderPtr readerptr);
        private:
            int x1_, y1_, x2_, y2_;
            const Line & line_;
    };
    
    class TermShape : public Shape{
        public:
            enum NameAlign{TopLeft = 1, TopRight, BottomLeft, BottomRight};	
        
            TermShape(Symbol*, std::string, int, int, NameAlign);
            ~TermShape();
            virtual Box getBoundingBox() const;
            NameAlign toNameAlign(std::string);
            
            Term * getTerm() const;
            int getX1() const;
            int getY1() const;
            static TermShape* fromXml(Symbol* owner, xmlTextReaderPtr readerptr);
        private:
            Term * term_;
            NameAlign align_;
            int x1_,y1_;

    };

    class EllipseShape : public Shape{
        public:
            EllipseShape(Symbol*, const Box &);
            ~EllipseShape();
            virtual Box getBoundingBox() const;
            static EllipseShape* fromXml(Symbol* owner, xmlTextReaderPtr readerptr);
        private:
            Box box_;
            
    
    };
    
    class ArcShape : public Shape{
        public:
            ArcShape(Symbol *, const Box &, int, int);
            ~ArcShape();
            virtual Box getBoundingBox() const;
            static ArcShape* fromXml(Symbol* owner, xmlTextReaderPtr readerptr);
        private:
            Box box_;
            int start_;
            int span_;
    };
}
