#include "Symbol.hpp"
#include "Term.hpp"
#include "Shape.hpp"
#include <ostream>

namespace Netlist {

    using namespace std;

    Symbol::Symbol(Cell * c): owner_(c){}

    Symbol::~Symbol(){}

    Cell * Symbol::getCell() const {return owner_;}

    //TODO : j'ai zero idée de ce que doit return cette fonction
    //Box Symbol::getBoundingBox() const {}

    Point Symbol::getTermPosition(Term * t) const{
        return t->getPosition();
    }

    //TODO : j'ai zero idée de ce que doit return cette fonction
    TermShape* Symbol::getTermShape(Term * t) const {
        
        for( Shape* s : shapes_){
            if(TermShape* ts = dynamic_cast<TermShape*>(s)){
                if(ts->getTerm() == t)
                    return ts;
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

        for (auto & s : shapes_)
            s->toXml(o);

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
        Symbol * symbol = new Symbol(c);
       // int type = xmlTextReaderNodeType(reader); 
        const xmlChar* nodeName = xmlTextReaderConstLocalName( reader );

        do{
            nodeName = xmlTextReaderConstLocalName( reader );

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
            }else if(nodeName == symbolTag){
                //nothing to do ; either @ the beginning or the end 
            }else{
                cerr << "placeholder error 1" << endl ; 
            }
            
        } while( !(status = xmlTextReaderRead(reader)) && 
                 !(xmlTextReaderNodeType(reader) == XML_READER_TYPE_END_ELEMENT) && (nodeName == symbolTag) );
      
        if(status == -1){
            cerr << "[ERROR] Symbol::fromXml(): Unexpected termination of the XML parser." << endl;
        }   

        return symbol; 

    }

}
