//
// Created by kluch on 28.03.18.
//

#ifndef JIMP_EXERCISES_XXX_H
#define JIMP_EXERCISES_XXX_H

#include <string>
#include <cstring>
#include <algorithm>
using ::std::swap;

class XXX {
public:
    XXX();
    XXX(const XXX& xxx);
    ~XXX();
    XXX & operator=(const XXX& xxx);
    XXX(XXX &&xxx);
    XXX & operator=(XXX &&xxx);
private:
    char *name_;
};





#endif //JIMP_EXERCISES_XXX_H
