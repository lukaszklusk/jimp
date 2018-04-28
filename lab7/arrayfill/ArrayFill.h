//
// Created by kluch on 18.04.18.
//

#ifndef JIMP_EXERCISES_ARRAYFILL_H
#define JIMP_EXERCISES_ARRAYFILL_H

#include <vector>
#include <random>

namespace arrays{
    class ArrayFill{
    public:
        virtual int Value(int index) const =0;
    };

    class UniformFill : public ArrayFill {
    public:
        UniformFill(int value = 0) : value_{value} {}
        virtual int Value(int index) const override;
    private:
        int value_;
    };

    class IncrementalFill : public ArrayFill {
    public:
        IncrementalFill(int start, int step = 1);
        virtual int Value(int index) const override;
    private:
        int start_;
        int step_;
    };

    /*class RandomFill : public ArrayFill{
    public:
        RandomFill(std::unique_ptr<std::default_random_engine> generator, std::unique_ptr<std::uniform_int_distribution<int>> distribution);
        virtual int Value(int index) const override;
    private:

    };*/

    class SquaredFill : public ArrayFill{
        
    };

    void FillArray(size_t size, const ArrayFill &filler, std::vector<int> *v);
}

#endif //JIMP_EXERCISES_ARRAYFILL_H
