//
// Created by kluch on 10.04.18.
//


#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H

#include <string>
#include <vector>
#include <complex>
#include <regex>
#include <utility>
namespace algebra {
    class Matrix {
    public:
        Matrix();

        ~Matrix();

        Matrix &operator=(const Matrix &mat);

        Matrix(int x, int y);

        Matrix(const Matrix &mat);

        Matrix(std::initializer_list<std::vector<std::complex<double>>> matrix_list);

        Matrix Add(Matrix mat_a) const;

        Matrix Sub(Matrix mat_s) const;

        Matrix Mul(const Matrix &mat_m) const;

        Matrix Pow(int pot) const;

        std::string Print() const;
        std::pair<size_t, size_t> Size();

    private:
        int dimx_;
        int dimy_;
        std::complex<double> **mat_;

    };
}
#endif //JIMP_EXERCISES_MATRIX_H