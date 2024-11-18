#include "Net.hpp"
#include "Indentation.hpp"
#include "XmlUtil.hpp"
#include "Node.hpp"
#include "Line.hpp"
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
                        	//check if its a nodeTerm using dynamic_cast
                        	if(NodeTerm* termNode = dynamic_cast<NodeTerm*>(node)){
                        		Term * t = termNode->getTerm();
                        		if(t->getNet() == this){
                                        	t->setNet(nullptr);
                        		}
                        	}
               	 	}
            
        	}
        }
        

        //accessseurs

        Cell* Net::getCell() const{
                return owner_;
        }

        const std::string& Net::getName() const{return name_;}
        unsigned int                            Net::getId                 () const{return id_;}
        Term::Type                                Net::getType             () const{return type_;}

        const std::vector<Node*>& Net::getNodes            () const{return nodes_;}
        
        size_t  Net::getFreeNodeId () const{
                for(size_t i = 0 ; i < nodes_.size() ; i++){
                        if(! nodes_[i]){
                                return i ;
                        }
                }
                return nodes_.size();
        }//

        //modificateurs Node
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

        //modificateurs Line

        void Net::add (Line* line){
                if(line)
                        lines_.push_back(line);
        }

        bool Net::remove (Line* line){
                if(line){
                        vector<Line*>::iterator il ;
                        for(il= lines_.begin(); il!=lines_.end(); ++il){
                                if(*il == line){
                                        lines_.erase(il);
                                        return true;
                                }
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

        //TODO : Modifier fromXml pour ajouter les Lines.

        Net* Net::fromXml(Cell* c, xmlTextReaderPtr readerptr){
                const xmlChar* netTag  = xmlTextReaderConstString( readerptr, (const xmlChar*)"net" );
                const xmlChar* nodeTag = xmlTextReaderConstString( readerptr, (const xmlChar*)"node" );
                const xmlChar* lineTag = xmlTextReaderConstString( readerptr, (const xmlChar*)"line" );

                typedef enum NetState {
                        BeginNet,
                        BeginNodes,
                        BeginLines,
                        EndNet
                }NetState;

                NetState state = BeginNet ; 
                Net * net = nullptr;

                bool first_it = true ; //ugly solution to skip reading first time bc we already are at net

                while( true ){
                        
                        int status ; 
                        if(!first_it) status = xmlTextReaderRead(readerptr);
                        else{
                                status = 1 ; 
                                first_it = false ;
                        }

                        if (status != 1) {
                                if (status != 0) {
                                        cerr << "[ERROR] Net::fromXml(): Unexpected termination of the XML parser." << endl;
                                }
                                break;
                        }
                        switch ( xmlTextReaderNodeType(readerptr) ) {
                                case XML_READER_TYPE_COMMENT:
                                case XML_READER_TYPE_WHITESPACE:
                                case XML_READER_TYPE_SIGNIFICANT_WHITESPACE:
                                continue;
                        }

                                  
                        const xmlChar* nodeName = xmlTextReaderConstLocalName( readerptr );
                       // cout << "ex " << nodeName << endl ;

                        switch(state){
                                case BeginNet : {
                                      //  cout << "entry 1" << endl ;
                                        string netName = xmlCharToString( xmlTextReaderGetAttribute( readerptr, (const xmlChar*)"name" ) );
                                        if (not netName.empty()) {
                                                net = new Net(c,netName, Term::External);//quand le net est-il internal ? a corriger.
                                                state = BeginNodes ;
                                                continue;
                                        }
                                       // cout << "exit 1" << endl ;
                                        break;
                                }
                                      
                                case BeginNodes : {
                                        if(nodeName == nodeTag  and (xmlTextReaderNodeType(readerptr) == XML_READER_TYPE_ELEMENT)){          
                                                //cout << "node case 1" << endl ;
                                                if(Node::fromXml(net, readerptr)) {  continue; }
                                        }else if(nodeName == lineTag){
                                        	state = BeginLines;
                                        	continue;
                                        }else if( nodeName == netTag ){
                                                if ((xmlTextReaderNodeType(readerptr) == XML_READER_TYPE_END_ELEMENT) ) {
                                                        return net ;
                                                }
                                                break;
                                        }
                                        break;
                                }
                                
                                case BeginLines : {
                                	if(nodeName == lineTag and (xmlTextReaderNodeType(readerptr) == XML_READER_TYPE_ELEMENT)){
                                		if(Line::fromXml(net, readerptr)) {continue ;}
                                	}else if( nodeName == netTag ){
                                                if ((xmlTextReaderNodeType(readerptr) == XML_READER_TYPE_END_ELEMENT) ) {
                                                        return net ;
                                                }
                                                break;
                                        }
                                	break;
                                }
                                
                                default: {
                                        break;
                                }
                        }
                        cerr << "[ERROR] Net::fromXml(): Unknown or misplaced tag <" << nodeName
                             << "> (line:" << xmlTextReaderGetParserLineNumber(readerptr) << ")." << endl;
                        break;
                }
                return net; 
        }
}
