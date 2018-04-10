//
// Created by Kornel on 10.04.2018.
//

#include "TextPool.h"

using namespace pool;

TextPool::TextPool(){
}

TextPool::TextPool(const initializer_list<string> &ptr) {
    for(auto &i : ptr)
        this->pool.insert(i);
}

TextPool::TextPool(TextPool &&ptr) {
    std::swap(this->pool, ptr.pool);
}

TextPool::~TextPool() {
}

TextPool& TextPool::operator=(TextPool &&ptr) {
    if(this == &ptr)
        return *this;
    this->pool.clear();
    std::swap(this->pool, ptr.pool);
    return *this;
}

size_t TextPool::StoredStringCount() const {
    return this->pool.size();
}

string_view TextPool::Intern(const string &str) {
    bool in = false;

    for (auto i = pool.begin(); i != pool.end(); i++)
        if (str == *i){
            in = true;
            return *i;
        }

    if (!in){
        this->pool.insert(str);
        return str;
    }
}



