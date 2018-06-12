//
// Created by kluch on 12.06.18.
//

#ifndef JIMP_EXERCISES_TIMERECORDER_H
#define JIMP_EXERCISES_TIMERECORDER_H

#include <chrono>

namespace profiling{
    template<typename T>
    auto TimeRecorder(const T &ob){
        auto start = std::chrono::system_clock::now();
        auto result = ob();
        auto end = std::chrono::system_clock::now();
        double asd = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count();
        return std::make_pair(result,asd/1000000);
    }
}

#endif //JIMP_EXERCISES_TIMERECORDER_H
