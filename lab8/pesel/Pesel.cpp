//
// Created by kluch on 25.04.18.
//

#include "Pesel.h"

academia::Pesel::Pesel(std::string in) {
    if(in.size() != 11){
        throw InvalidPeselLength();
    }
    int checksum = 0;
    for(int i = 0;i<11;i++){
        if(in[i] < '0' || in[i] > '9'){
            throw InvalidPeselCharacter();
        }

    }
    str_ = in;
}
