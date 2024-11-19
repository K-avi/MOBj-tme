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
    
    BoxShape * BoxShape::fromXml(Symbol * owner, xmlTextReaderPtr reader){
        const xmlChar* boxTag  = xmlTextReaderConstString        ( reader, (const xmlChar*)"box" );
        const xmlChar* nodeName = xmlTextReaderConstLocalName     ( reader );
        
        //check if all values are assigned
        bool init = true;
        
        if(boxTag == nodeName){
            int x1, y1, x2, y2;
            init &= xmlGetIntAttribute( reader, "x1", x1 );
            init &= xmlGetIntAttribute( reader, "y1", y1 );
            init &= xmlGetIntAttribute( reader, "x2", x2 );
            init &= xmlGetIntAttribute( reader, "y2", y2 );
            
            if(!init){
                cerr << "[ERROR] BoxShape::fromXml(): Unknown coordinate : x1 :" << x1 << " x2 : "<< x2 << " y1 : "<< y1 << " y2 : "<< y2 
                << " (line:" << xmlTextReaderGetParserLineNumber(reader) << ")." << endl;
                return NULL;
            }

            return new BoxShape(owner, Box(x1, y1, x2, y2));
        }
        
        return NULL;
    }



    //LineShape Methods
    LineShape::LineShape(Symbol * s, int x1, int y1, int x2, int y2) : Shape(s) ,x1_(x1), y1_(y1), x2_(x2), y2_(y2){}

    LineShape::~LineShape(){}

    Box LineShape::getBoundingBox() const{
        return Box(x1_, y1_, x2_, y2_);
    }
    
    LineShape * LineShape::fromXml(Symbol * owner, xmlTextReaderPtr reader){
        const xmlChar* lineTag  = xmlTextReaderConstString        ( reader, (const xmlChar*)"line" );
        const xmlChar* nodeName = xmlTextReaderConstLocalName     ( reader );
        
        bool init = true;
        
        if(lineTag == nodeName){
            int x1, y1, x2, y2;
            init &= xmlGetIntAttribute( reader, "x1", x1 );
            init &= xmlGetIntAttribute( reader, "y1", y1 );
            init &= xmlGetIntAttribute( reader, "x2", x2 );
            init &= xmlGetIntAttribute( reader, "y2", y2 );
            
            if(!init){
                cerr << "[ERROR] LineShape::fromXml(): Unknown coordinate : x1 :" << x1 << " x2 : "<< x2 << " y1 : "<< y1 << " y2 : "<< y2
                 << " (line:" << xmlTextReaderGetParserLineNumber(reader) << ")." << endl;
                return NULL;
            }

            return new LineShape(owner, x1, y1, x2, y2);
        }
        
        return NULL;
    }
    
    
    
    //TermShape Methods
    TermShape::TermShape(Symbol * s, string name, int x1, int y1, NameAlign align): Shape(s), x1_(x1), y1_(y1), align_(align){
        s->add(this);
        Cell * cell = owner_->getCell();
        term_ = cell->getTerm(name);
    }

    TermShape::~TermShape(){}

    /*Box TermShape::getBoundingBox() const{
        return Box(x1_, y1_).inflate(5,5);
    }*/
    
    TermShape::NameAlign TermShape::toNameAlign(string s){
        if(s == "top_left")
        	return TopLeft;
        else if (s == "top_right")
		return TopRight;
	    else if (s == "bottom_left")
		return BottomLeft;
        else if (s == "bottom_right")
        	return BottomRight;

        throw invalid_argument("TermShape::toNameAlign: Invalid string align: " + s);
    }
    
    Term * TermShape::getTerm() const {return term_;}
    int TermShape::getX1() const{return x1_;}
    int TermShape::getY1() const{return y1_;}
    
    
    TermShape * TermShape::fromXml(Symbol * owner, xmlTextReaderPtr reader){
        const xmlChar* termTag  = xmlTextReaderConstString        ( reader, (const xmlChar*)"term" );
        const xmlChar* nodeName = xmlTextReaderConstLocalName     ( reader );
        
        bool init = true;
        
        if(termTag == nodeName){
            int x1, y1;
            init &= xmlGetIntAttribute( reader, "x1", x1 );
            init &= xmlGetIntAttribute( reader, "y1", y1 );
            
            if(!init){
                cerr << "[ERROR] TermShape::fromXml(): Unknown coordinate : x1 :" << x1 << " y1 : "<< y1
                 << " (line:" << xmlTextReaderGetParserLineNumber(reader) << ")." << endl;
                return NULL;
            }
            
            string termName = xmlCharToString( xmlTextReaderGetAttribute( reader, (const xmlChar*)"name" ) );
            string termAlignStr = xmlCharToString( xmlTextReaderGetAttribute( reader, (const xmlChar*)"align" ) );
            
            if(termName.empty()){
                cerr << "[ERROR] TermShape::fromXml(): Unknown name" << endl;
                return NULL;
            }
            
            if(termAlignStr.empty()){
                cerr << "[ERROR] TermShape::fromXml(): Unknown align" << endl;
                return NULL;
            }
            
            return new TermShape(owner, termName, x1, y1, TermShape::toNameAlign(termAlignStr));     
        }
        
        return NULL;
    }
    
    //EllipseShape Methods
    EllipseShape::EllipseShape(Symbol * s, const Box & b) : Shape(s), box_(b){}
    
    EllipseShape::~EllipseShape(){}
    
    Box EllipseShape::getBoundingBox() const {return box_;}
    
    EllipseShape * EllipseShape::fromXml(Symbol * owner, xmlTextReaderPtr reader){
        const xmlChar* ellipseTag  = xmlTextReaderConstString        ( reader, (const xmlChar*)"ellipse" );
        const xmlChar* nodeName = xmlTextReaderConstLocalName     ( reader );
        
        bool init = true;
        
        if(ellipseTag == nodeName){
            int x1, y1, x2, y2;
            init &= xmlGetIntAttribute( reader, "x1", x1 );
            init &= xmlGetIntAttribute( reader, "y1", y1 );
            init &= xmlGetIntAttribute( reader, "x2", x2 );
            init &= xmlGetIntAttribute( reader, "y2", y2 );
            
            if(!init){
                cerr << "[ERROR] EllipseShape::fromXml(): Unknown coordinate : x1 :" << x1 << " x2 : "<< x2 << " y1 : "<< y1 << " y2 : "<< y2
                 << " (line:" << xmlTextReaderGetParserLineNumber(reader) << ")." << endl;
                return NULL;
            }

            return new EllipseShape(owner, Box(x1, y1, x2, y2));
        }
        
        return NULL;
    }

    //ArcShape Methods
    ArcShape::ArcShape(Symbol * s, const Box & b, int start, int span) : Shape(s), box_(b), start_(start), span_(span){}
    
    ArcShape::~ArcShape(){}
    
    Box ArcShape::getBoundingBox() const {return box_;}
    
    ArcShape * ArcShape::fromXml(Symbol * owner, xmlTextReaderPtr reader){
        const xmlChar* arcTag  = xmlTextReaderConstString        ( reader, (const xmlChar*)"arc" );
        const xmlChar* nodeName = xmlTextReaderConstLocalName     ( reader );
        
        bool init = true;
        
        if(arcTag == nodeName){
            int x1, y1, x2, y2, start, span;
            init &= xmlGetIntAttribute( reader, "x1", x1 );
            init &= xmlGetIntAttribute( reader, "y1", y1 );
            init &= xmlGetIntAttribute( reader, "x2", x2 );
            init &= xmlGetIntAttribute( reader, "y2", y2 );
            init &= xmlGetIntAttribute( reader, "start", start );
            init &= xmlGetIntAttribute( reader, "span", span );
            
            if(!init){
                cerr << "[ERROR] ArcShape::fromXml(): Unknown coordinate : x1 : " << x1 << " x2 : "<< x2 << " y1 : "<< y1 << " y2 : "<< y2 
                << " start : " << start << " span : " << span 
                 << " (line:" << xmlTextReaderGetParserLineNumber(reader) << ")." << endl;
                return NULL;
            }

            return new ArcShape(owner, Box(x1, y1, x2, y2), start, span);
        }
        
        return NULL;
    }
}
