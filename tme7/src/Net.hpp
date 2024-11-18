#pragma once 

#include "Cell.hpp"
#include "Node.hpp"
#include "Term.hpp"

namespace Netlist {
        class Net{

                //attributs :
                Cell*                             owner_;
                std::string                 name_;
                unsigned int                id_;
                Term::Type                    type_;
                std::vector<Node*>    nodes_;

                //Ajout attribut Line
                std::vector<Line*> lines_;
                

                public:

                 Net         ( Cell*, const std::string&, Term::Type);    
                 /*
                 @param : Cell* the Cell* that will contain our ref
                 @param : string& the Net name
                 @param : Type the type of Net

                 @brief : initializes the fields of the net ; appends the net to the cell's net vector 
                 and sets the id_ to the index of the net in the cell vector
                 */ 
                ~Net         ();

                //accesseurs
                Cell* getCell() const;
                const std::string&                getName             () const;
                unsigned int                            getId                 () const;
                Term::Type                                getType             () const;
                const std::vector<Node*>& getNodes            () const;
                size_t  getFreeNodeId () const;

                //Ajout méthodes pour Line
                void add(Line*);
                bool remove(Line*);
                inline const std::vector<Line*>& getLines () const
                {return lines_;}

                //modificateurs
                void    add        ( Node* );
                bool    remove ( Node* );

                void toXml(std::ostream&);

                static Net* fromXml(Cell* c, xmlTextReaderPtr readerptr);
        };
}