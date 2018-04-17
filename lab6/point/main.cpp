//
// Created by kluch on 11.04.18.
//

#include "Point.h"
#include <iostream>
#include <sstream>

int main(){
    Point p;
    std::cin >> p;
    std::stringstream s;
    s << p;
    std::cout <<s.str();
    s >> p;
    std::cout <<p;
    //p.Print();
}