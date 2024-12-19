#pragma once

#include "Box.hpp"
#include "Symbol.hpp"
#include "XmlUtil.hpp"

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
            virtual void toXml(std::ostream&) = 0;
        //protected so that it can be accessed by derived classes
       	protected:
            Symbol * owner_;
    };
    
    class BoxShape : public Shape{
        public:
            BoxShape(Symbol *, const Box &);
            ~BoxShape();
            Box getBoundingBox() const;
            static BoxShape* fromXml(Symbol* owner, xmlTextReaderPtr readerptr);
            void toXml(std::ostream&);
        private:
            Box box_;
    };
    
    class LineShape : public Shape{
        public :
            LineShape(Symbol *, int, int, int, int);
            ~LineShape();
            Box getBoundingBox() const;
            static LineShape* fromXml(Symbol* owner, xmlTextReaderPtr readerptr);
            void toXml(std::ostream&);
        private:
            int x1_, y1_, x2_, y2_;
    };
    
    //TODO : a quel moment on rempli term_ ?????
    class TermShape : public Shape{
        public:
            enum NameAlign{TopLeft = 1, TopRight, BottomLeft, BottomRight};	
        
            TermShape(Symbol*, std::string, int, int, NameAlign);
            ~TermShape();
            Box getBoundingBox() const;
            static NameAlign strToNameAlign(std::string);
            static std::string NameAlignToStr(TermShape::NameAlign n);   
            Term * getTerm() const;
            int getX1() const;
            int getY1() const;
            static TermShape* fromXml(Symbol* owner, xmlTextReaderPtr readerptr);
            void toXml(std::ostream&);
        private:

            Term * term_;
            NameAlign align_;
            int x1_,y1_;

    };

    class EllipseShape : public Shape{
        public:
            EllipseShape(Symbol*, const Box &);
            ~EllipseShape();
            Box getBoundingBox() const;
            static EllipseShape* fromXml(Symbol* owner, xmlTextReaderPtr readerptr);
            void toXml(std::ostream&);
        private:
            Box box_;
            
    
    };
    
    class ArcShape : public Shape{
        public:
            ArcShape(Symbol *, const Box &, int, int);
            ~ArcShape();
            Box getBoundingBox() const;
            static ArcShape* fromXml(Symbol* owner, xmlTextReaderPtr readerptr);
            void toXml(std::ostream&);
            inline int getStart() const {return start_;}
            inline int getSpan() const {return span_;}
        private:
            Box box_;
            int start_;
            int span_;
    };
}
