//
// Created by kluch on 23.05.18.
//

#include "FactoryMethod.h"

#include <iostream>
#include <memory>

int main(){
    int a=4,b=5;
    int c = factoryMethod::Add(a,b);
    std::cout <<c<<std::endl;
    std::shared_ptr<int> r= std::make_shared<int>(a);
    b = factoryMethod::Value(r);
    std::cout <<b;
}