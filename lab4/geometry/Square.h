//
// Created by kluch on 21.03.18.
//

#ifndef JIMP_EXERCISES_SQUARE_H
#define JIMP_EXERCISES_SQUARE_H

#include "Point.h"

namespace geometry{
    class Square{
    public:
        Square(Point p1,Point p2,Point p3, Point p4);
        ~Square();
        Point p1_;
        Point p2_;
        Point p3_;
        Point p4_;
        double Circumference() const;
    };
    Square::Square(Point p1, Point p2, Point p3, Point p4) {
        p1_ = p1;
        p2_ = p2;
        p3_ = p3;
        p4_ = p4;
    }
}

#endif //JIMP_EXERCISES_SQUARE_H
