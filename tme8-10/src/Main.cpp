#include <QApplication>
#include <QtGui>
#include "Cell.hpp"
#include "CellViewer.hpp"
#include <iostream>
#include "Shape.hpp"
#include "Term.hpp"

using namespace std; 
using namespace Netlist;

int main(int argc, char *argv[]) {

    Cell * vdd = Cell::load("vdd"); 
    Cell::load("gnd");
    Cell::load("TransistorN"); 
    Cell::load("TransistorP"); 
    Cell::load("or2"); 
    Cell::load("and2"); 

    Cell* xor2 = Cell::load("xor2");

   // Cell* halfadder = Cell::load("halfadder");

    for(auto s : vdd->getSymbol()->getShapes()){
        if(TermShape* ts = dynamic_cast<TermShape*>(s)){
                cout << "term is : " << ts->getTerm()->getName()<<endl ;
        }
    }

    QApplication *qa = new QApplication(argc, argv);
    CellViewer *viewer = new CellViewer();
    viewer->setCell(xor2);
    viewer->show();
    
    int rvalue = qa->exec();
    delete qa;
    
    return rvalue;
}

