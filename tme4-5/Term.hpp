#pragma once 

#include "Node.hpp"
#include "Cell.hpp"
#include "Instance.hpp"

#include <string>


namespace Netlist{
        class Net;

        class Term{

                public :

                enum Type{ Internal = 1, External = 2 };
                enum Direction{ In = 1 , Out, Inout, Tristate, Transcv, Unknown};

                private : 
                //attributs
                void* owner_; 
                std::string name_; 
                Direction direction_; 
                Type type_;
                Net* net_; 
                Node node_;

                public:

                //methodes de classe
                static std::string toString(Type); 
                static std::string toString(Direction); 
                static Direction toDirection(std::string);

                //constructeurs / destructeurs 
                Term(Cell*, const std::string& name, Direction); 
                Term(Instance* , const Term* modelTerm );
                ~Term();

                //prédicats : 
                inline bool                             isInternal     () const{return (type_ == Internal);}
                inline bool                             isExternal     () const{return (type_ == External);}
                inline const std::string& getName            () const{return name_;}
                inline Node*                            getNode            (){return &node_;}
                inline Net*                             getNet             () const{return net_;}
                inline Cell*                            getCell            () const{
                        return (type_ == External) ? static_cast<Cell*>(owner_) : nullptr;
                }
                             Cell*                            getOwnerCell () const;
                             
                inline Instance*                    getInstance    () const{
                        return (type_ == Internal) ? static_cast<Instance*>(owner_) : nullptr;
                }
                inline Direction                    getDirection () const;
                inline Point                            getPosition    () const;
                inline Type                             getType            () const;

                //modificateurs
                void    setNet             ( Net* );
                void    setNet             ( const std::string& );
                inline void    setDirection ( Direction );
                void    setPosition    ( const Point& );
                void    setPosition    ( int x, int y );

                void toXml(std::ostream& o);
        };

        
}