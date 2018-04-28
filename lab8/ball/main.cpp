//
// Created by kluch on 25.04.18.
//

#include <iostream>
using namespace std;

class CircleException{
    // Oznacza ze nie mozna wyrysowac kola
};

class BallException : public CircleException{
    // Oznacza ze nie mozna wyrysowac
};

void drawBall() {
    throw BallException();
}
void drawCircle() {
    throw CircleException();
}

int main(){
    try{
        drawBall();
    }catch(CircleException &a){
        cout << "Blad podczas rysowania kola" << endl;
    }catch(BallException &b){
        cout << "Blad podczas rysowania kuli" << endl;
    }

}