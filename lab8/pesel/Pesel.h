//
// Created by kluch on 25.04.18.
//

#ifndef JIMP_EXERCISES_PESEL_H
#define JIMP_EXERCISES_PESEL_H

#include <iostream>

namespace academia{
    class InvalidPeselChecksum : public std::invalid_argument{
    public:
        InvalidPeselChecksum(const std::string &s) : invalid_argument{"Zly pesel"}, s_{s};
    private:
        std::string s_;
    };
    class InvalidPeselLength : public std::invalid_argument{
    public:
        InvalidPeselLength(const std::string &s) : invalid_argument{"Zla dlugosc pesela"}, s_{s};
    private:
        std::string s_;
    };
    class InvalidPeselCharacter{

    };
    class AcademiaDataValidationError{

    };
    class Pesel{
    public:
        Pesel(std::string in);
    private:
        std::string str_;
    };
}

#endif //JIMP_EXERCISES_PESEL_H
