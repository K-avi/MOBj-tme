#include "Net.hpp"
#include "Indentation.hpp"
#include "Node.hpp"
#include <cstddef>
#include <ostream>

namespace Netlist {

        using namespace std;

        //constructeurs 
        Net::Net ( Cell* c, const std::string& s, Term::Type t)
        :owner_(c),
        name_(s),
        type_(t),
        nodes_(vector<Node*>())
        {
                c->add(this);    
                id_ = c->newNetId();
                for(size_t i = 0 ; i < nodes_.size() ; i++){
                        nodes_[i] = nullptr;
                }
        }

        Net::~Net(){
                for( auto node : nodes_){
                        if(node != nullptr){
                                Term * t = node->getTerm();

                                if(t->getNet() == this){
                                        t->setNet(nullptr);

                                }else{//error case
                                        cerr << "Net::~Net() t's Net should be : "
                                                 << (void*)this << "but is" << (void*) t->getNet() << endl;
                                }
                        }
                }
            
        }

        //accessseurs

        Cell*                                         Net::getCell             () const{
                return owner_;
        }

        const std::string&                Net::getName             () const{return name_;}
        unsigned int                            Net::getId                 () const{return id_;}
        Term::Type                                Net::getType             () const{return type_;}

        const std::vector<Node*>& Net::getNodes            () const{return nodes_;}
        
        size_t    Net::getFreeNodeId () const{
                for(size_t i = 0 ; i < nodes_.size() ; i++){
                        if(! nodes_[i]){
                                return i ;
                        }
                }
                return nodes_.size();
        }//

        //modificateurs
        void    Net::add        ( Node* n ){
                size_t idx = getFreeNodeId() ; 
                if(idx != nodes_.size()){
                        nodes_[idx] = n; 
                }else{
                        nodes_.push_back(n); 
                }
                n->setId(idx);
        }

        bool    Net::remove ( Node* n ){
                for(size_t i = 0 ; i < nodes_.size() ; i++){
                        if(n == nodes_[i] ){
                                nodes_[i] = nullptr; 
                                return true;
                        }
                }
                return false;
        }

        void Net::toXml(ostream& o){
                o << indent++ << "<net name=\"" << name_ << "\" type=\"" << Term::toString(type_) << "\"/>" <<    endl;

                for(auto & n : nodes_)
                        n->toXml(o);                

                o << --indent << "</net>" << endl;
        }
}