// -*- explicit-buffer-name: "Main.cpp<M1-MOBJ/4-5>" -*-

#include <string>
#include <sstream>
#include <iostream>
#include <memory>
using namespace std;

#include "Term.hpp"
#include "Net.hpp"
#include "Instance.hpp"
#include "Cell.hpp"
using namespace Netlist;


int main ( int argc, char* argv[] )
{
  cout << "Chargement des modeles:" << endl;
  cout << "- <and2> ..." << endl;
  Cell::load( "and2" );
    
  cout << "- <or2> ..." << endl;
  Cell::load( "or2" );

  cout << "- <xor2> ..." << endl;
  Cell::load( "xor2" );

    
  cout << "- <halfadder> ..." << endl;
  Cell* halfadder = Cell::load( "halfadder" );

  cout << "\nContenu du <halfadder>:" << endl;
  halfadder->toXml( cout );

  //delete halfadder;

  return 0;
}
