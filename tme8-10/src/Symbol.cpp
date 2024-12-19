#include "Symbol.hpp"
#include "Box.hpp"
#include "Indentation.hpp"
#include "Term.hpp"
#include "Shape.hpp"
#include <ostream>

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
        for(auto c : Cell::getAllCells()){
        
        auto * sym = c->getSymbol();
        
        for( Shape* s : sym->getShapes()){
            if(TermShape* ts = dynamic_cast<TermShape*>(s)){

                cout << "term is : " << ts->getTerm()->getName()<<endl ;
                if(ts->getTerm()->getName() == t->getName()){
                    cerr << "Symbol::getTermShape Found symbol" << endl;
                    return ts;
                }
                else{
                    cerr << "Searching for symbol : " << t->getName() << endl ;  
                    cerr << "Symbol::getTermShape : non matching term is " << ts->getTerm()->getName() << endl ;
                }
            }
        }
        }
        
        return NULL;
    }

    void Symbol::add(Shape * s){
        shapes_.push_back(s);
    }

    void Symbol::remove(Shape * s){
        vector<Shape*>::iterator it;
        for(it = shapes_.begin(); it != shapes_.end(); it++){
            if(*it == s){
                shapes_.erase(it);
                return;
            }
        }
    }

    void Symbol::toXml(std::ostream& o) const{
        o << indent++ << "<symbol>" << endl;
        for (auto & s : shapes_){
            o << ++indent;
            s->toXml(o);
            o << --indent << endl ;
        }

        o << --indent << "</symbol>" << endl;
    }

    Symbol* Symbol::fromXml(Cell* c, xmlTextReaderPtr reader){

        const xmlChar* boxTag  = xmlTextReaderConstString( reader, (const xmlChar*)"box");
        const xmlChar* lineTag = xmlTextReaderConstString( reader, (const xmlChar*)"line");
        const xmlChar* termTag = xmlTextReaderConstString( reader, (const xmlChar*)"term");
        const xmlChar* arcTag  = xmlTextReaderConstString( reader, (const xmlChar*)"arc" );
        const xmlChar* ellipseTag = xmlTextReaderConstString( reader, (const xmlChar*)"ellipse" );
        const xmlChar* symbolTag = xmlTextReaderConstString( reader, (const xmlChar*)"symbol" );

        int status ; 
        Symbol * symbol = c->getSymbol();
       // int type = xmlTextReaderNodeType(reader); 
        const xmlChar* nodeName;
        
        while((status = xmlTextReaderRead(reader)) == 1){
            nodeName = xmlTextReaderConstLocalName( reader );
            //Shape::fromXml(symbol, reader);
            if(nodeName == boxTag && (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT)){
                if(!BoxShape::fromXml(symbol, reader)) 
                    cerr << "[ERROR] Symbol::fromXml(): error while parsing box node : " << nodeName << endl ;        

            }else if(nodeName == lineTag && (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT)){
                if(!LineShape::fromXml(symbol, reader)) 
                    cerr << "[ERROR] Symbol::fromXml(): error while parsing line node : " << nodeName << endl ; 
            }else if(nodeName == termTag && (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT)){
                if(!TermShape::fromXml(symbol, reader)) 
                    cerr << "[ERROR] Symbol::fromXml(): error while parsing term node : " << nodeName << endl ; 

            }else if(nodeName == arcTag && (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT)){
                if(!ArcShape::fromXml(symbol, reader)) 
                    cerr << "[ERROR] Symbol::fromXml(): error while parsing arc node : " << nodeName << endl ; 
            }else if(nodeName == ellipseTag && (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT)){
                if(!EllipseShape::fromXml(symbol, reader)) 
                    cerr << "[ERROR] Symbol::fromXml(): error while parsing ellipse node : " << nodeName << endl ;
            }else if(nodeName == symbolTag && (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT)){
                //nothing to do ; either @ the beginning or the end 
                break;
            }else if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT) {
                cerr << "[ERROR?] Symbol::fromXml(): Unrecognized element <" << nodeName << "> in symbol tags." << endl;
            }
        }
           
        if (status == -1) {
            cerr << "[ERROR] Symbol::fromXml(): Unexpected termination of the XML parser." << endl;
        }
        return symbol; 

    }


    Box  Symbol::getBoundingBox() const {
        Box b;
        for(auto s : shapes_){
            BoxShape * bs = dynamic_cast<BoxShape*>(s);
            if(bs){
                b.setX1(bs->getBoundingBox().getX1());
                b.setY1(bs->getBoundingBox().getY1());
                b.setX2(bs->getBoundingBox().getX2());
                b.setY2(bs->getBoundingBox().getY2());
            }
        }
        return b;   
    }

}
