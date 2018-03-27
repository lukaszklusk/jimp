//
// Created by kluch on 21.03.18.
//

#ifndef JIMP_EXERCISES_POINT_H
#define JIMP_EXERCISES_POINT_H


#include <cmath>
#include <ostream>

using ::std::ostream;
using ::std::endl;
using ::std::pow;
using ::std::sqrt;

namespace geometry{
    class Point {
    public:
        Point(double x, double y);

        Point();

        double Distance(const Point &other) const;

        double GetX() const;
        double GetY() const;
        void SetX(double x);
        void SetY(double y);
    private:
        double x_, y_;
    };

    Point::Point(double x, double y){
        x_ = x;
        y_ = y;
    }

    double Point::Distance(const Point &other) const{
        return sqrt(pow(GetX()-other.GetX(),2)+pow(GetY()-other.GetY(),2));
    }

}

#endif //JIMP_EXERCISES_POINT_H
