#include "Shape.hpp"
#include "Term.hpp"
#include "Box.hpp"
#include "Line.hpp"


namespace Netlist{

    using namespace std;

    //Shape Methods
    Shape::Shape(Symbol *s): owner_(s){
        owner_->add(this);
    }

    Shape::~Shape() {owner_->remove(this);}

    Box Shape::getBoundingBox() const {return Box();}
    
    Shape* Shape::fromXml ( Symbol* owner, xmlTextReaderPtr reader )
    {
    // Factory-like method.
      const xmlChar* boxTag
        = xmlTextReaderConstString( reader, (const xmlChar*)"box" );
      const xmlChar* ellipseTag
        = xmlTextReaderConstString( reader, (const xmlChar*)"ellipse" );
      const xmlChar* arcTag
        = xmlTextReaderConstString( reader, (const xmlChar*)"arc" );
      const xmlChar* lineTag
        = xmlTextReaderConstString( reader, (const xmlChar*)"line" );
      const xmlChar* termTag
        = xmlTextReaderConstString( reader, (const xmlChar*)"term" );
      const xmlChar* nodeName
          = xmlTextReaderConstLocalName( reader );

      Shape* shape = NULL;
      if (boxTag == nodeName)
        shape = BoxShape::fromXml( owner, reader );
      if (ellipseTag == nodeName)
        shape = EllipseShape::fromXml( owner, reader );
      if (arcTag == nodeName)
        shape = ArcShape::fromXml( owner, reader );
      if (lineTag == nodeName)
        shape = LineShape::fromXml( owner, reader );
      if (termTag == nodeName)
        shape = TermShape::fromXml( owner, reader );

      if (shape == NULL)
        cerr << "[ERROR] Unknown or misplaced tag <" << nodeName << "> (line:"
             << xmlTextReaderGetParserLineNumber(reader) << ")." << endl;

      return shape;
    }


    
    //BoxShape Methods
    BoxShape::BoxShape(Symbol * s, const Box & b) : Shape(s), box_(b){}

    BoxShape::~BoxShape(){}

    Box BoxShape::getBoundingBox() const {return box_;}



    //LineShape Methods
    LineShape::LineShape(Symbol * s, const Line & l, int x1, int y1, int x2, int y2) : Shape(s), line_(l),x1_(x1), y1_(y1), x2_(x2), y2_(y2){}

    LineShape::~LineShape(){}

    Box LineShape::getBoundingBox() const{
        return Box(x1_, y1_, x2_, y2_);
    }
    
    
    
    //TermShape Methods
    TermShape::TermShape(Symbol * s, string name, int x1, int y1, NameAlign align_): Shape(s), term_(nullptr), x1_(x1), y1_(y1), align_(align){
        s->add(this);
        Cell * cell = owner_->getCell();
        term_ = cell->getTerm(name);
    }

    TermShape::~TermShape(){}

    /*Box TermShape::getBoundingBox() const{
        return Box(x1_, y1_).inflate(5,5);
    }*/
    
    TermShape::NameAlign TermShape::toNameAlign(string s){
        switch(s){
            case "top_left" : return TopLeft;
            case "top_right" : return TopRight;
            case "bottom_left" : return BottomLeft;
            case "bottom_right" : return BottomRight;
        }
        cerr << "TermShape::toNameAlign string align invalide: " << s << endl; 
    }
    
    Term * TermShape::getTerm() const {return term_;}
    int TermShape::getX1() const{return x1_;}
    int TermShape::getY1() const{return y1_;}

}
