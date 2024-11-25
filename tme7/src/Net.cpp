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
        
        Node * Net::getNode(int i) const {
        	return nodes_[i];
        }

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
                o << indent++ << "<net name=\"" << name_ << "\" type=\"" << Term::typeToString(type_) << "\"/>" <<    endl;

                for(auto & n : nodes_)
                        n->toXml(o);   
                
                for(auto & l : lines_)
                	l->toXml(o);             

                o << --indent << "</net>" << endl;
        }


        //not tested, might be wrong (probably right tho bc i made it :D)
        Net* Net::fromXml(Cell* c, xmlTextReaderPtr readerptr){
                const xmlChar* netTag  = xmlTextReaderConstString( readerptr, (const xmlChar*)"net");
                const xmlChar* nodeTag = xmlTextReaderConstString( readerptr, (const xmlChar*)"node");
                const xmlChar* lineTag = xmlTextReaderConstString( readerptr, (const xmlChar*)"line");

                int status ; 
                
                string netName = xmlCharToString( xmlTextReaderGetAttribute( readerptr, (const xmlChar*)"name" ) );
                string netType = xmlCharToString( xmlTextReaderGetAttribute( readerptr, (const xmlChar*)"type" ) );

                if(netName.empty()){
                        cerr << "[ERROR] Net::fromXml(): net name is empty" << endl ; 
                }
                
                if(netType.empty()){
                        cerr << "[ERROR] Net::fromXml(): net type is empty" << endl ; 
                }

                cout << "[DEBUG::Net::fromXml] Net name: " << netName << ", Net type: " << netType << endl;
                Net * net = new Net(c, netName, Term::typeFromString(netType));
        // int type = xmlTextReaderNodeType(reader); 
                const xmlChar* nodeName;

                do{
                nodeName = xmlTextReaderConstLocalName( readerptr );
                cout << "[DEBUG::Net::fromXml] dans net le node name est : " << nodeName << endl;
                if(nodeName == nodeTag && (xmlTextReaderNodeType(readerptr) == XML_READER_TYPE_ELEMENT)){
                        if(!Node::fromXml(net, readerptr)) 
                            cerr << "[ERROR] Net::fromXml(): error while parsing node : " << nodeName << endl ;        
                }else if(nodeName == lineTag && (xmlTextReaderNodeType(readerptr) == XML_READER_TYPE_ELEMENT)){
                        if(!Line::fromXml(net, readerptr)) 
                            cerr << "[ERROR] Net::fromXml(): error while parsing line node : " << nodeName << endl ; 
                }else if(nodeName == netTag){
                        //nothing to do ; either @ the beginning or the end 
                }else{
                        cerr << "placeholder error 1" << endl ; 
                }
                
                } while( !(status = xmlTextReaderRead(readerptr)) && 
                        !(xmlTextReaderNodeType(readerptr) == XML_READER_TYPE_END_ELEMENT) && (nodeName == netTag) );
        
                if(status == -1){
                        cerr << "[ERROR] Net::fromXml(): Unexpected termination of the XML parser." << endl;
                }   

                return net; 

        }
}
