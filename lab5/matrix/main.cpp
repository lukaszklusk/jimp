//
// Created by kluch on 10.04.18.
//

#include <iostream>
#include "Matrix.h"

using algebra::Matrix;
using std::cout;
using std::endl;


int main(){
    Matrix m1{{1.0i, 0., 0.}, {0., 1.0i, 0.}, {0., 0., 1.0i}};
    Matrix m2{{7. + 1.0i, 0., 0.}, {0., 1.0i, 8.}, {15. + 2.0i, 0. + 3.0i, 4. + 1.0i}};

    cout << "Macierz pierwsza: " << m1.Print() << endl;
    cout << "Macierz druga: " << m2.Print() << endl;

    cout << "Dodawanie" << (m1.Add(m2)).Print() << endl;
    cout << "Odejmowanie" << (m1.Sub(m2)).Print() << endl;
    cout << "Mnożenie" << (m1.Mul(m2)).Print() << endl;
    //cout << "Potęgowanie" << (m1.pow(2)).print() << endl;
    //cout << "Potęgowanie" << (m2.pow(2)).print() << endl;
}