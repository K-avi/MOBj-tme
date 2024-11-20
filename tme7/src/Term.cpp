#include "Term.hpp"
#include "Cell.hpp"
#include "Net.hpp"
#include <iostream>
#include <string>

namespace Netlist {
        
        using namespace std;
        
        
        //methodes de classe
        std::string Term::toString(Type t){
                return (t == Internal) ? "Internal" : "External";
        }

        Term::Type Term::fromString(string s){
                Term::Type t ;
                if(s == "Internal") t = Internal ;
                else if(s == "External" ) t = External ; 
                else {cerr << "wrong value in Term::fromString arg is" << s <<endl; t = Internal ; }
                return t;
        }

        std::string Term::toString(Direction d){
                switch (d) {
                        case In : return "In";
                        case Out : return "Out";
                        case Inout : return "Inout";
                        case Tristate : return "Tristate";
                        case Transcv : return "Transcv";
                        case Unknown : return "Unknown";
                        default : return "Unknown";
                }
        }

        Term::Direction Term::toDirection(std::string s){
                if(s.empty()) return Unknown;

                switch (s[0]) {
                        case 'I' : if( !s.compare("In")) return In ;
                                             else if(!s.compare("Inout")) return Inout;
                                             break;

                        case 'O' : if( !s.compare("Out")) return Out ; 
                                             break;

                        case 'T' : if(!s.compare("Tristate")) return Tristate; 
                                             else if(!s.compare("Transcv")) return Transcv;
                                             break;
                        default : return Unknown;
                }
                return Unknown;
        }

        //constructeurs / destructeurs
        Term::Term(Cell* c, const string& name, Direction d)
        :owner_((void*)c),
        name_(name),
        direction_(d),
        type_(External),
        net_(nullptr), //placeholder
        node_(this)
        {
                c->add(this);
        }

        Term::Term(Instance* i, const Term* modelTerm) //duplique le modèle
        :owner_((void*)i),
        name_(modelTerm->name_),
        direction_(modelTerm->direction_),
        type_(Internal),
        net_(modelTerm->net_),
        node_(this)
        {}

        Term::~Term(){
                
                if(net_)
                        net_->remove(&node_); 
                net_ = nullptr;
                
        }

        //prédicats (les autres sont inlines)
        Cell* Term::getOwnerCell () const{
                if(type_ == External)
                        return static_cast<Cell*>(owner_);
                return static_cast<Instance*>(owner_)->getCell();    
        }

        //modificateurs
        void    Term::setNet( Net* n){
                if(!n){
                        if(net_){
                                net_->remove(&node_);
                                net_ = NULL;     
                        }
                }else{
                        net_ = n;
                        net_->add(&node_);
                }
                //placeholder
        }//not tested; might be wrong 

        void    Term::setNet( const std::string& s){
                
                net_ = getOwnerCell()->getNet(s);
                if(!net_)
                        cerr << "Term::setNet nom de Cell invalide: " << s << endl; 
                
                net_->add(&node_);

                return ; 
        }//not tested; should be ok

        inline void    Term::setDirection ( Term::Direction d){
                direction_    = d;
        }

        void    Term::setPosition    ( const Point& p){
                node_.setPosition(p);
        }//not tested; might be wrong

        void    Term::setPosition    ( int x, int y ){
                node_.setPosition(Point(x,y));
        }

        void Term::toXml(std::ostream& o){
                o << indent << "<term name=\"" << name_ 
                    << "\" direction=\"" << toString(direction_)
                    << "\" x=\"" << this->getPosition().getX()  
                    << "y=\"" << this->getPosition().getY() << "\" \"/>" << endl;
        }

        Term* Term::fromXml(Cell* cell, xmlTextReaderPtr readerptr){

                string name = xmlCharToString(xmlTextReaderGetAttribute(readerptr, (const xmlChar*)"name"));
                Direction d = toDirection(xmlCharToString(xmlTextReaderGetAttribute(readerptr, (const xmlChar*)"direction")));
                
                int x = stoi(xmlCharToString(xmlTextReaderGetAttribute(readerptr, (const xmlChar*)"x")));
                int y = stoi(xmlCharToString(xmlTextReaderGetAttribute(readerptr, (const xmlChar*)"y")));

                Term* ret = new Term(cell, name,d);

                ret->setPosition(Point(x,y));
                return ret;
        }// a faire : traitement d'erreur 
};
