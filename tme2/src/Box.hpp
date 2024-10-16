//Laila Lahkim Bennani 21102544 Ivan Mulot-Radojcic 21102722
#pragma once 

#include <ostream>
#include <string>
#include <iostream>
namespace __TD2_BOX{

class Box {

    static long nb_allocated ;

    //attributs privés :
    long x1_, y1_, x2_, y2_; 
    std::string name_;

    public: 
    //constructeurs : 
    Box()
    :x1_(0), y1_(0), x2_(0), y2_(0), name_("")
    {std::cerr << "Debug: Box::Box()" << "<\"" << name_ << "\"" << "[" << x1_ << " " << y1_  << " "
        << x2_  << " " << y2_ << "]>" << std::endl ; nb_allocated++;};

    Box(const std::string, long x1, long y1, long x2, long y2);
    Box(const Box& b);
    //destructeur :
    ~Box()
    {}
    
    //accesseurs :
    //accesseurs :

    inline std::string getName() const{
        return name_;
    }

    inline long getX1() const{return x1_;}
    inline long getY1() const{return y1_;}

    inline long getX2() const{return x2_;}

    inline long getY2() const{return y2_;}

    // prédicats : 
    inline long getWidth() const{return x2_ < x1_ ? 0 : x2_ - x1_ ;}

    inline long getHeight() const{return y2_ < y1_ ? 0 : y2_ - y1_ ;}

    //q3 :
    inline bool isEmpty() const{return (y2_ <= y1_) || (x2_ <= x1_);}

    bool intersect(const Box& b) const;
    std::ostream& print(std::ostream&) const;

    //modificateurs :
    void makeEmpty();
    void inflate(long dxy);
    void inflate(long dx, long dy);
    void inflate(long dx1, long dy1, long dx2, long dy2);
    Box getIntersection(const Box& b) const; 

    friend std::ostream & operator<< (std::ostream & os, const Box& box) ;
    Box operator&& (const Box& b) const;

    //q5 
    //fonction statique : 
    static inline long getAllocateds(){return nb_allocated;}
};

}
