//Laila Lahkim Bennani 21102544 Ivan Mulot-Radojcic 21102722
#include <iostream>
#include "QuestionFacultative.hpp"

using namespace std ; 

namespace tme2qf {

    long Box::nb_allocated = 0;

    Box::Box(const std::string name, long x1, long y1, float width, float height){
        name_ = name;
        x_ = x1;
        y_ = y1;
        width_ = width;
        height_ = height;
        nb_allocated++;
        std::cerr << "Debug: Box::Box()" << "<\"" << name_ << "\"" << "[" << x_<< " " << y_<< " "
            << width_  << " " << height_<< "]>" << std::endl ;
    }

    Box::Box(const Box& b){
        name_ = b.name_;
        x_ = b.x_;
        y_ = b.y_;
        width_ = b.width_;
        height_ = b.height_;
        nb_allocated++;
        std::cerr << "Debug: Box::Box()" << "<\"" << name_ << "\"" << "[" << x_<< " " << y_<< " "
            << width_  << " " << height_<< "]>" << std::endl ;
    }

    bool Box::intersect(const Box& b) const{
        if (isEmpty() || b.isEmpty()) {
            return false;
        }
        if (x_ + width_ < b.x_ || b.x_ + b.width_ < x_ || y_ + height_ < b.y_ || b.y_ + b.height_ < y_) {
            return true;
        }
        return false;

    }

    std::ostream& Box::print(std::ostream& os) const{
        os << "Box \"" << name_ << "\" [" << x_ << " " << y_ << " " << width_ << " " << height_ << "]";
        return os;
    }

    void Box::makeEmpty(){
        x_ = 0;
        y_ = 0;
        width_ = 0;
        height_ = 0;
    }

    void Box::inflate(long dxy){
        width_ += 2*dxy;
        height_ += 2*dxy;
        x_ = width_ / 2;
        y_ = height_ / 2;
    }

    void Box::inflate(long dx, long dy){
        width_ += 2*dx;
        height_ += 2*dy;
        x_ = width_ / 2;
        y_ = height_ / 2;
    }

    void Box::inflate(long dx1, long dy1, long dx2, long dy2){
        width_ += dx1 + dx2;
        height_ += dy1 + dy2;
        x_ = width_ / 2;
        y_ = height_ / 2;
    }

    Box Box::getIntersection(const Box& b) const{
        Box res;
        if(intersect(b)){
            res.x_ = max(x_, b.x_);
            res.y_ = max(y_, b.y_);
            res.width_ = min(x_ + width_, b.x_ + b.width_) - res.x_;
            res.height_ = min(y_ + height_, b.y_ + b.height_) - res.y_;
        }
        return res;
    }

    std::ostream & operator<< (std::ostream & os, const Box& box){
        return box.print(os);
    }

    Box Box::operator&& (const Box& b) const{
        return getIntersection(b);
    }




}

