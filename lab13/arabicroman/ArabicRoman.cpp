//
// Created by kluch on 06.06.18.
//

#include <stdexcept>
#include "ArabicRoman.h"

int numbers::RomanToArabic(std::string num) {
    for(int i =0;i<num.size();i++){
        if(num[i] != 'M' && num[i] != 'C' && num[i] != 'L' && num[i] != 'D' && num[i] != 'X' && num[i] != 'V' && num[i] != 'I')
            throw std::invalid_argument(num);
    }
    int result=0;
    if(num == "I")return 1;
    for(int i = 0;i< num.size();i++){
        if(num[i]=='M') result += 1000;
        if(num[i]=='D') result += 500;
        if(num[i]=='C'){
            if(i+1<num.size()) {
                if (num[i + 1] == 'M') {
                    result += 900;
                    i++;
                } else {
                    if(num[i+1]== 'D') {
                        result += 400;
                        i++;
                    }
                    result += 100;
                }
            }
        }
        if(num[i]=='L')result += 50;
    }
    return result;
}
