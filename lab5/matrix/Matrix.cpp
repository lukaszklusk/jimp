//
// Created by kluch on 10.04.18.
//

#include "Matrix.h"
using namespace algebra;
Matrix::Matrix() {};
Matrix::~Matrix(){
    for(int i=0; i<dimy_; i++)
        delete [] mat_[i];
    delete [] mat_;
};
Matrix::Matrix(int x, int y) {
    dimx_=y;
    dimy_=x;
    mat_= new std::complex<double>*[dimy_];
    for(int i=0;i<dimy_;i++){
        mat_[i]= new std::complex<double>[dimx_];
    }
}
Matrix::Matrix(const Matrix &mat) {
    dimx_=mat.dimx_;
    dimy_=mat.dimy_;
    mat_= new std::complex<double>*[dimy_];
    for(int i=0;i<dimy_;i++){
        mat_[i]= new std::complex<double>[dimx_];

    }
    for(int i=0;i<dimy_;i++){
        for(int j=0;j<dimx_;j++){
            mat_[i][j]=mat.mat_[i][j];
        }
    }
}
std::string Matrix::Print() const {
    std::string wynik;
    wynik += "[";

    for (int y = 0; y < dimy_; y++) {
        for (int x = 0; x < dimx_; x++) {
            std::string liczba = std::to_string(this->mat_[y][x].real());
            //asd
            liczba.erase(liczba.find_last_not_of('0') + 1, std::string::npos);
            if (liczba[liczba.size() - 1] == '.')
                liczba.erase(liczba.size() - 1);
            wynik += liczba;
            liczba = std::to_string(this->mat_[y][x].imag());
            liczba.erase(liczba.find_last_not_of('0') + 1, std::string::npos);
            if (liczba[liczba.size() - 1] == '.')
                liczba.erase(liczba.size() - 1);
            wynik += "i" + liczba;
            wynik += ", ";
        }
        wynik[wynik.size()-2]=';';
    }
    wynik.erase(wynik.size()-2,std::string::npos);
    wynik += "]";

    return wynik;
}
std::pair<size_t, size_t> Matrix::Size() {
    return std::pair<size_t, size_t>(dimy_, dimx_);
}
algebra::Matrix::Matrix(std::initializer_list<std::vector<std::complex<double>>> matlist) {
    dimy_ = int(matlist.size());
    dimx_ = int(matlist.begin()->size());
    mat_ = new std::complex<double> *[dimy_];
    for(int i=0;i<dimy_;++i) {
        mat_[i] = new std::complex<double>[dimx_];
    }
    mat_;
    int x=0,y=0;
    for(auto i: matlist){
        unsigned long d = i.size();
        x=0;
        for(unsigned long j=0;j<d;++j){
            mat_[y][x] = i[j];
            ++x;
        }
        ++y;
    }
}

Matrix Matrix::Add(const Matrix mat_a) const {
    if(this->dimy_!=mat_a.dimy_ || this->dimx_!=mat_a.dimx_){
        Matrix ret(0,0);
        return ret;
    }
    Matrix matwyn(dimy_,dimx_);
    for(int i=0;i<dimy_;i++){
        for(int j=0;j<dimy_;j++){
            matwyn.mat_[i][j]=this->mat_[i][j]+mat_a.mat_[i][j];
        }
    }
    return matwyn;
}

Matrix Matrix::Sub(const Matrix mat_s) const{
    if(this->dimy_!=mat_s.dimy_ || this->dimx_!=mat_s.dimx_){
        Matrix ret(0,0);
        return ret;
    }
    Matrix matwyn(dimy_,dimx_);
    for(int i=0;i<dimy_;i++){
        for(int j=0;j<dimy_;j++){
            matwyn.mat_[i][j]=this->mat_[i][j]-mat_s.mat_[i][j];
        }
    }
    return matwyn;
}

Matrix Matrix::Mul(const Matrix &mat_m)const {
    if(this->dimx_!=mat_m.dimy_ ){
        Matrix ret(0,0);
        return ret;
    }
    Matrix matwyn(dimy_,mat_m.dimx_);

    for(int i=0;i<dimy_;i++){
        for(int j=0;j<mat_m.dimx_;j++){
            std::complex<double> tmp = 0.;
            for(int k=0;k<dimx_;++k){
                tmp += this->mat_[i][k] * mat_m.mat_[k][j];
            }
            matwyn.mat_[i][j] = tmp;
        }
    }
    return matwyn;
}

Matrix Matrix::Pow(int pot)const {
    if(dimx_ != dimy_){
        return Matrix(0,0);
    }
    Matrix matwyn = *this;
    if(pot == 0){
        for(int i=0;i<dimy_;i++){
            for(int j=0;j<dimx_;j++){
                if(i == j)matwyn.mat_[i][j] = 1.;
                else matwyn.mat_[i][j] = 0.;
            }
        }
    }else {
        Matrix tmp = *this;
        for (int i = 1; i < pot; i++)
            matwyn = matwyn.Mul(tmp);
    }
    return matwyn;
}

Matrix &Matrix::operator=(const Matrix &mat) {
    if(this == &mat)
        return *this;
    for(int i=0;i<dimy_;++i){
        delete [] mat_[i];
    }
    delete [] mat_;
    dimx_ = mat.dimx_;
    dimy_ = mat.dimy_;
    std::complex<double> **tmp = new std::complex<double> *[dimy_];
    for(int i=0;i<dimy_;++i){
        tmp[i] = new std::complex<double> [dimx_];
    }
    mat_ = tmp;
    for(int i=0;i<dimx_;++i){
        for(int j=0;j<dimy_;++j){
            mat_[i][j] = mat.mat_[i][j];
        }
    }
    return *this;
}
