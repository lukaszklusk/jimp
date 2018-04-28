//
// Created by kluch on 18.04.18.
//

#include "ArrayFill.h"



int arrays::UniformFill::Value(int index) const {
    return value_;
}

void arrays::FillArray(size_t size, const ArrayFill &filler, std::vector<int> *v) {
    v->clear();
    v->reserve(size);
    for (size_t i = 0; i < size; i++) {
        v->emplace_back(filler.Value(i));
    }
}

arrays::IncrementalFill::IncrementalFill(int start, int step) {
    start_ = start;
    step_ = step;
}

int arrays::IncrementalFill::Value(int index) const {
    return start_ + (step_*index);
}
