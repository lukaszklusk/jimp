//
// Created by klusukas on 02.03.18.
//

#include "ReverseString.h"
#include <string>

std::string reverse(std::string str){
    int dl = str.size();
    if(dl == 0)return "\0";
    std::string character = "";
    character = character + str[dl-1];
    str.erase(dl-1);
    return character+reverse(str);
}