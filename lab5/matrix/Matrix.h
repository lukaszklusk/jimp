//
// Created by kluch on 10.04.18.
//

#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H

#include <complex>
#include <string>
#include <initializer_list>
#include <utility>
#include <vector>
#include <memory>

namespace algebra{
    class Matrix{
    public:
        Matrix();
        ~Matrix();
        Matrix(std::string strmat);
        Matrix(int dimx, int dimy);
        Matrix(const Matrix &mat);
        Matrix &operator=(const Matrix &mat);
        Matrix(Matrix &&mat);
        Matrix &operator=(Matrix &&mat);
        Matrix(std::initializer_list<std::vector<std::complex<double>>> matlist);
        std::pair<size_t,size_t> Size() const;
        std::string Print() const;
        Matrix Add(Matrix mat2) const;
        Matrix Sub(Matrix mat2) const;
        Matrix Mul(Matrix mat2) const;
        Matrix Pow(int p) const;
    private:
        std::complex<double> **mat_;
        int dimx_;
        int dimy_;
    };
}

#endif //JIMP_EXERCISES_MATRIX_H
