#include "Instance.hpp"
#include "Node.hpp"
#include "Point.hpp"
#include "Term.hpp"
#include <cstddef>
#include <ostream>
#include <string>
#include <vector>

using namespace std;
using namespace Netlist;

namespace Netlist {

        //constructeur / destructeur    

        //PLACEHOLDERS
        Instance::Instance            ( Cell* owner, Cell* model, const std::string& n) 
        :owner_(owner),
        masterCell_(model),
        name_(n),
        terms_(vector<Term*>()),
        position_()
        {
                for(auto term : model->getTerms()){
                        terms_.push_back(new Term(this, term));
                }
                owner->add(this);
        }

        Instance::~Instance            ()
        {     
                
                //cout << "haaaaaaaai" << terms_.size() << endl;
                for(size_t i = 0 ; i < terms_.size(); i++){
                        //cout << "terms[i]" << (void*) terms_[i] << endl;
                        if(terms_[i]){
                             delete terms_[i];
                             terms_[i] = nullptr;
                        }
                }
        }

        //accesseurs 
        const std::string&                Instance::getName             () const{return name_;}
        Cell*                                         Instance::getMasterCell () const{return masterCell_;}
        Cell*                                         Instance::getCell             () const{return owner_;}
        const std::vector<Term*>& Instance::getTerms            () const{return terms_;}
        
        Term*                                         Instance::getTerm             ( const std::string& n ) const{
        
                for( Term* term: terms_){
                        if(term->getName() == n)
                                return term;
                }
                return nullptr;
        }
        Point                                         Instance::getPosition     () const{return position_;}

        //PLACEHOLDERS
        //modificateurs
        bool    Instance::connect             ( const std::string& name, Net* n){

                Term* t = getTerm(name);
                if(t){
                        t->setNet(n);
                }
                return (bool)t;
        }

        size_t Instance::getFreeTermId () {
                for(size_t i = 0 ; i < terms_.size() ; i++){
                        if(! terms_[i]){
                                return i ;
                        }
                }
                return terms_.size();
        }//not tested; might be wrong

        void    Instance::add                     ( Term* t){
                size_t idx = getFreeTermId() ; 
                if(idx != terms_.size())
                        terms_[idx] = t;
                else
                        terms_.push_back(t);
        }//not tested; might not work

        void    Instance::remove                ( Term* term){
                for(size_t i = 0 ; i < terms_.size(); i++){
                        if(terms_[i] == term)
                                terms_[i] = nullptr;
                }
        }

        void    Instance::setPosition     ( const Point& p){
                position_ = Point(p.getX(),p.getY());
        }
        void    Instance::setPosition     ( int x, int y ){
                position_ = Point(x,y);
        }

        void Instance::toXml(ostream& o){
                o << indent << "<instance name=\"" << name_ << "\" mastercell=\"" << masterCell_->getName() << "\" x=\"" 
                    << position_.getX() << "\" y=\"" << position_.getY() << "\"/>" << endl;

        }
}
