//
// Created by kluch on 23.05.18.
//

#ifndef JIMP_EXERCISES_FACTORYMETHOD_H
#define JIMP_EXERCISES_FACTORYMETHOD_H

#include <string>
#include <ostream>

namespace factoryMethod {
    template<typename T>
    auto Create() {
        return T();
    }

    class MyType{
    public:
        MyType() =default;
        std::string SayHello(){
            return "hello";
        }
    };

    template<typename T>
    auto Add(const T &n1,const T &n2){
        return n1+n2;
    }

    template <typename T>
    auto Value(const T &tt){
        return *tt;
    }

    template<typename log>
    class Logger{
    public:
        enum class Level {DEBUG,ERROR};
        void Debug(const log &l);
        void Info(const log &l);
        void Warning(const log &l);
        void Error(const log &l);
    private:
        std::ostream *out_;
        Level current_level_;
    };

    template<typename log>
    void Logger<log>::Debug(const log &l) {
        if( current_level_ >= Level::DEBUG){
            (*out_)<<l;
        }
    }

    template<typename log>
    void Logger<log>::Info(const log &l) {

    }
}

#endif //JIMP_EXERCISES_FACTORYMETHOD_H
