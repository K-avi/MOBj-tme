// -*- explicit-buffer-name: "Node.cpp<M1-MOBJ/4-5>" -*-

#include    <limits>
#include    <ostream>
#include    "Node.hpp"
#include "Point.hpp"
#include    "Term.hpp"
#include    "Net.hpp"
#include    "Instance.hpp"
#include    "Cell.hpp"

namespace Netlist {

    using namespace std;
    const size_t    Node::noid = numeric_limits<size_t>::max();

    Node::Node ( Term* term, size_t id    )
        : id_            (id)
        , term_        (term)
        , position_()
    {
        Net * n = term->getNet(); 
        if(n){
            n->add(this);
        }
    }


    Node::~Node ()
    {
        
        if (getNet()) getNet()->remove( this );
        
    }


    inline Net* Node::getNet () const { return term_->getNet(); }


    void Node::toXml(ostream& o){
        Point p = getPosition();
        o << indent << "<node term=\"" << term_->getName() << "\""    ;
        //cout << endl << "nodetoxlm getterm " << getTerm()->getInstance() << endl ;
     // cout << "type : " << getTerm()->isInternal() <<endl ;
        if(getTerm()->getInstance()){
            o << " instance=\"" << getTerm()->getInstance()->getName() << "\"";
        }
        o << " id=\"" << id_ << "\" x=\"" << 
            p.getX() << "\" y=\"" <<    p.getY() << "\"/>" << endl;
    }

    bool Node::fromXml(Net* net, xmlTextReaderPtr readerptr){

        string term =  xmlCharToString(xmlTextReaderGetAttribute(readerptr, (const xmlChar*)"term"));
        size_t id = stoi(xmlCharToString(xmlTextReaderGetAttribute(readerptr, (const xmlChar*)"id")));
        
        //pas dans la version de halfadder du tme 6, étrange?
        //int x = stoi(xmlCharToString(xmlTextReaderGetAttribute(readerptr, (const xmlChar*)"x")));
        //int y = stoi(xmlCharToString(xmlTextReaderGetAttribute(readerptr, (const xmlChar*)"y")));

        xmlChar* instance = xmlTextReaderGetAttribute(readerptr, (const xmlChar*)"term");

        Node* node = new Node(net->getCell()->getTerm(term), id);
        //node->setPosition(x,y);

        if(instance != nullptr){
            string inststr = xmlCharToString(instance);

            Instance* inst = net->getCell()->getInstance(inststr); //tester si non null 
            if(inst){
                inst->add(node->getTerm());
            }
        }

        net->add(node);

        return true ; 
    }



}    // Netlist namespace.
