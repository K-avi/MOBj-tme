#pragma once

#include "Cell.hpp"
#include "Point.hpp"
#include <string>

namespace Netlist {

        class Cell;
        class Term;
        class Instance{

                //attributs :
                Cell*                             owner_;
                Cell*                             masterCell_;
                std::string                 name_;
                std::vector<Term*>    terms_;
                Point                             position_;

                size_t getFreeTermId ();

                public:
                //constructeurs
                 Instance            ( Cell* owner, Cell* model, const std::string& );
                ~Instance            ();

                //accesseurs
                const std::string&                getName             () const;
                Cell*                                         getMasterCell () const;
                Cell*                                         getCell             () const;
                const std::vector<Term*>& getTerms            () const;
                Term*                                         getTerm             ( const std::string& ) const;
                Point                                         getPosition     () const;

                //modificateurs
                bool    connect             ( const std::string& name, Net* );
                void    add                     ( Term* );
                void    remove                ( Term* );
                void    setPosition     ( const Point& );
                void    setPosition     ( int x, int y );

                void toXml(std::ostream& stream);

        };
}