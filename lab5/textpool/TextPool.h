//
// Created by Kornel on 10.04.2018.
//

#ifndef JIMP_EXERCISES_TEXTPOOL_H
#define JIMP_EXERCISES_TEXTPOOL_H
#include <initializer_list>
#include <string>
#include <experimental/string_view>
#include <set>
#include <vector>
#include <cstring>
#include <iostream>

namespace pool{
    using ::std::initializer_list;
    using ::std::move;
    using ::std::strcmp;
    using ::std::set;
    using ::std::cin;
    using ::std::cout;
    using ::std::string;
    using ::std::experimental::string_view;
    using ::std::size_t;
    using ::std::vector;

    class TextPool{
    public:

        TextPool();
        TextPool(const initializer_list<string> &ptr);
        TextPool(TextPool &&ptr);
        ~TextPool();

        TextPool& operator=(TextPool &&ptr);
        string_view Intern(const string &str);
        size_t StoredStringCount() const;

    private:
        set<string> pool;
    };
}



#endif //JIMP_EXERCISES_TEXTPOOL_H
