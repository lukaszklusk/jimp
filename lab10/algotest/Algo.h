//
// Created by kluch on 16.05.18.
//

#ifndef JIMP_EXERCISES_ALGO_H
#define JIMP_EXERCISES_ALGO_H

#include <algorithm>
#include <vector>
#include <string>

namespace  algo{
    void CopyInto(const std::vector<int> &v, int n_elements, std::vector<int> *out){
        std::copy(v.begin(),v.begin() + n_elements,std::back_inserter(*out));
    }

    bool Contains(const std::vector<int> &v, int element){
        auto f = std::find(v.begin(),v.end(),element);
        return f!=v.end();
    }

    void InitializeWith(int initial_value, std::vector<int> *v){
        std::fill((*v).begin(),(*v).end(),initial_value);
    }
    std::vector<int> InitializedVectorOfLength(int length, int initial_value){
        std::vector<int> *new_v;
        std::uninitialized_fill_n(new_v,length,initial_value);
        return *new_v;
    }

    std::vector<std::string> MapToString(const std::vector<double> &v){

    }

}

#endif //JIMP_EXERCISES_ALGO_H
