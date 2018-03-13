//
// Created by kluch on 10.03.18.
//

#include "Polybius.h"
#include <string>

std::string PolybiusCrypt(std::string message){
    if(message.empty())return "";
    char character = message[0];
    std::string wynik = "";
    message.erase(message.begin());
    if(character != ' ') {
        if(character >= 'a' && character <= 'z') {
            if (character >= 'a' && character < 'f')
                wynik = wynik + "1";
            if (character >= 'f' && character < 'l')
                wynik = wynik + "2";
            if (character >= 'l' && character < 'q')
                wynik = wynik + "3";
            if (character >= 'q' && character < 'v')
                wynik = wynik + "4";
            if (character >= 'v' && character < 'z' + 1)
                wynik = wynik + "5";
            if (character >= 'j')character--;
            if (((int) character) % 5 == 2)
                wynik = wynik + "1";
            if (((int) character) % 5 == 3)
                wynik = wynik + "2";
            if (((int) character) % 5 == 4)
                wynik = wynik + "3";
            if (((int) character) % 5 == 0)
                wynik = wynik + "4";
            if (((int) character) % 5 == 1)
                wynik = wynik + "5";
        }else{
            if (character >= 'A' && character < 'F')
                wynik = wynik + "1";
            if (character >= 'F' && character < 'L')
                wynik = wynik + "2";
            if (character >= 'L' && character < 'Q')
                wynik = wynik + "3";
            if (character >= 'Q' && character < 'V')
                wynik = wynik + "4";
            if (character >= 'V' && character < 'Z' + 1)
                wynik = wynik + "5";
            if (character >= 'J')character--;
            if (((int) character) % 5 == 0)
                wynik = wynik + "1";
            if (((int) character) % 5 == 1)
                wynik = wynik + "2";
            if (((int) character) % 5 == 2)
                wynik = wynik + "3";
            if (((int) character) % 5 == 3)
                wynik = wynik + "4";
            if (((int) character) % 5 == 4)
                wynik = wynik + "5";
        }
    }
    wynik = wynik + PolybiusCrypt(message);
    return wynik;
}
std::string PolybiusDecrypt(std::string crypted){
    if(crypted.empty())return "";
    int szyfr = 0;
    std::string wynik = "";
    for(int i = 10;i>=1;i/=10){
        szyfr += ((int)crypted[0] - '0') * i;
        crypted.erase(crypted.begin());
    }
    if(szyfr >= 11 && szyfr <20)
        wynik = wynik + (char)(szyfr + 86);
    if(szyfr >= 21 && szyfr <25)
        wynik = wynik + (char)(szyfr + 81);
    if(szyfr == 25)
        wynik = wynik + (char)(szyfr + 82);
    if(szyfr >= 31 && szyfr <=35)
        wynik = wynik + (char)(szyfr + 77);
    if(szyfr >= 41 && szyfr <=45)
        wynik = wynik + (char)(szyfr + 72);
    if(szyfr >= 51 && szyfr <=55)
        wynik = wynik + (char)(szyfr + 67);
    wynik = wynik + PolybiusDecrypt(crypted);
    return wynik;
}
