//Laila Lahkim Bennani 21102544 Ivan Mulot-Radojcic 21102722
#pragma once 

#include <iostream>

namespace tme2qf {

    class Box{
        static long nb_allocated ;

            //attributs privés :
            long x_, y_; 
            float width_, height_; 
            std::string name_;

            public: 
            //constructeurs : 
            Box()
            :x_(0), y_(0), width_(0), height_(0), name_("")
            {std::cerr << "Debug: Box::Box()" << "<\"" << name_ << "\"" << "[" << x_<< " " << y_<< " "
                << width_  << " " << height_<< "]>" << std::endl ; nb_allocated++;};

            Box(const std::string, long x1, long y1, float width_, float height_);
            Box(const Box& b);
            //destructeur :
            ~Box()
            {}
            
            //accesseurs :

            inline std::string getName() const{
                return name_;
            }

            inline long getX1() const{return x_;}
            inline long getY1() const{return y_;}

            // prédicats : 
            inline long getWidth() const{return width_;}

            inline long getHeight() const{return height_;}

            //q3 :
            inline bool isEmpty() const{return (height_ <= 0) || (width_ <= 0);}

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