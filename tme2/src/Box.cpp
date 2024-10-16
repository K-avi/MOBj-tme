//Laila Lahkim Bennani 21102544 Ivan Mulot-Radojcic 21102722
#include "Box.hpp"
#include <iostream>
#include <ostream>



namespace __TD2_BOX{

    //fonction utilitaire et de débuggage : 

    long Box::nb_allocated = 0; 

    static void BoxDebugPrint(const Box& box, std::string fun_name){
        std::cerr << "Debug: Box::" << fun_name ;
        box.print(std::cerr);
    }

    static inline long min ( long a, long b ){ 
        return (a > b) ? b : a; 
    }

    static inline long max ( long a, long b ){ 
        return (a > b) ? a : b; 
    }

    //constructeurs :

    Box::Box(const std::string name, long x1, long y1, long x2, long y2){
        nb_allocated++;
        name_ = name;
        x1_ = x1; 
        y1_ = y1; 
        x2_ = x2; 
        y2_ = y2;

        BoxDebugPrint(*this, "Box(const std::string, long, long, long, long)");
    }

    Box::Box(const Box& b){
        nb_allocated++;
        name_ = b.name_;
        x1_ = b.x1_;
        y1_ = b.y1_; 
        x2_ = b.x2_;
        y2_ = b.y2_;

        BoxDebugPrint(*this, "Box(const Box&)");
    }

    bool Box::intersect(const Box& b) const{

        if (isEmpty() || b.isEmpty()) return 0;
        if (  ((x2_ > b.x1_)
            && (x1_ < b.x2_)
            && (y2_ > b.y1_)
            && (y1_ < b.y2_) ))
            return 1; 
        return 0;
    }

    // fonction d'I/O : 
    std::ostream& Box::print(std::ostream& stream) const{
        return stream << "\"<" << name_ << "[" << x1_ << " " << y1_ << " " << x2_ << " " << y2_ << "]>" << std::endl ;
    }

    //modificateurs : 

    void Box::makeEmpty(){
        x1_ = y1_ = x2_ = y2_ = 0 ;
        name_ = nullptr ;
    }

    void Box::inflate(long dxy){
        x1_ -= dxy;
        y1_ -= dxy; 
        x2_ += dxy;
        y2_ += dxy;
    }

    void Box::inflate(long dx, long dy){
        x1_ -= dx;
        y1_ -= dx; 
        x2_ += dy;
        y2_ += dy;
    }

    void Box::inflate(long dx1, long dy1, long dx2, long dy2){

        x1_ -= dx1;
        y1_ -= dy1; 
        x2_ += dx2;
        y2_ += dy2;
    }

    Box Box::getIntersection(const Box& b) const{
        if (! intersect(b)) return Box();

        return Box(name_ + "." + b.name_, max(x1_,b.x1_), max(y1_, b.y1_), 
                     min(x2_, b.x2_), min(y2_, b.y2_));
    }

    //q4.1 : 
    std::ostream & operator<< (std::ostream & os, const Box& box){
        return box.print(os);
    }

    //q4.2 : 
    //on redéfinit l'opérateur and pour la classe box
    Box Box::operator&&( const Box& b2) const{
        return getIntersection(b2);
    }
}
