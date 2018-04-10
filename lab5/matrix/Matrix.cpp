//
// Created by kluch on 10.04.18.
//

#include "Matrix.h"
#include <regex>

algebra::Matrix::Matrix() {
    dimx_ = 0;
    dimy_ = 0;
    mat_ = nullptr;
}


algebra::Matrix::~Matrix() {
    for(int i=0;i<dimy_;++i){
        delete [] mat_[i];
    }
    delete [] mat_;
}

algebra::Matrix::Matrix(std::string strmat) {
    int dimx=0,dimy=0,dimxtmp=0;
    for(int i=0;i<strmat.size();i++){
        if(strmat[i] == ' ')
            dimxtmp++;
        if(strmat[i] == ';') {
            dimy++;
            dimx = dimxtmp + 1;
            dimxtmp = 0;
        }
    }
    dimx_ = dimx;
    dimy_ = dimy;
    std::complex<double> **tmp = new std::complex<double> *[dimy_];
    for(int i=0;i<dimy_;++i){
        tmp[i] = new std::complex<double> [dimx_];
    }
    mat_ = tmp;
    strmat.erase(0);
    strmat.erase(strmat.size()-1);
    std::regex pattern {R"([0-9]+\.?[0-9]*i?[0-9]*\.?[0-9]*)"};
    std::smatch s;
    int x=0,y=0;
    while(std::regex_search(strmat,s,pattern)){
        for(auto m: s){
            std::string liczba = m.str();
            std::string r = liczba.substr(0,liczba.find('i'));
            std::string i = liczba.substr(liczba.find('i')+1,liczba.size());
            mat_[x,y]->real(std::stod(r));
            if(liczba.find('i') == liczba.size())
                mat_[x,y]->imag(0);
            if(liczba.find('i') != liczba.size() && i.empty())
                mat_[x,y]->imag(1);
            if(liczba.find('i') != liczba.size() && !i.empty())
                mat_[x,y]->imag(std::stod(i));
            x++;
            if(x == dimx_){
                x=0;
                y++;
            }
        }
        strmat = s.suffix().str();
    }

}

algebra::Matrix::Matrix(int dimx, int dimy) {
    dimx_ = dimx;
    dimy_ = dimy;
    mat_ = new std::complex<double> *[dimy_];
    for(int i=0;i<dimy_;++i){
        mat_[i] = new std::complex<double> [dimx_];
    }
    for(int i=0;i<dimy_;++i){
        for(int j=0;j<dimx_;++j){
            mat_[i][j] = 0.;
        }
    }
}

algebra::Matrix::Matrix(const algebra::Matrix &mat) {
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
}

algebra::Matrix &algebra::Matrix::operator=(const algebra::Matrix &mat) {
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

algebra::Matrix::Matrix(std::initializer_list<std::vector<std::complex<double>>> matlist) {
    dimy_ = int(matlist.size());
    dimx_ = int(matlist.begin()->size());
    std::complex<double> **tmp = new std::complex<double> *[dimy_];
    for(int i=0;i<dimy_;++i) {
        tmp[i] = new std::complex<double>[dimx_];
    }
    mat_ = tmp;
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

std::pair<size_t, size_t> algebra::Matrix::Size() const {
    size_t dimx = size_t(dimx_);
    size_t dimy = size_t(dimy_);
    return std::pair<size_t, size_t>{dimx,dimy};
}

std::string algebra::Matrix::Print() const {
    std::string wynik = "[";
    for(int i=0;i<dimy_;++i){
        for(int j=0;j<dimx_;++j){
            std::string tmp;
            if(mat_[i][j].real()) {
                tmp = std::to_string(mat_[i][j].real());
                tmp.erase(tmp.find_last_not_of('0') + 1, std::string::npos);
                if (tmp[tmp.size() - 1] == '.')
                    tmp.erase(tmp.size() - 1);
            }else tmp = "0";
            tmp = std::to_string(mat_[i][j].real());
            tmp.erase(tmp.find_last_not_of('0') + 1, std::string::npos);
            if (tmp[tmp.size() - 1] == '.')
                tmp.erase(tmp.size() - 1);
            wynik += tmp;
            if(mat_[i][j].imag()) {
                tmp = std::to_string(mat_[i][j].imag());
                tmp.erase(tmp.find_last_not_of('0') + 1, std::string::npos);
                if (tmp[tmp.size() - 1] == '.')
                    tmp.erase(tmp.size() - 1);
            }else tmp = "0";
            wynik += "i" + tmp;
            if(j<dimx_-1)
                wynik += ", ";
            else {
                if (i < dimy_ - 1)
                    wynik += "; ";
            }
        }
    }
    wynik += "]";
    return wynik;
}

algebra::Matrix algebra::Matrix::Add(const algebra::Matrix mat2) const {
    if(this->dimx_ != mat2.dimx_ || this->dimy_ != mat2.dimy_){
        return algebra::Matrix();
    }
    Matrix matwyn(dimx_,dimy_);
    for(int i=0;i<this->dimy_;++i){
        for(int j=0;j<this->dimx_;++j){
            matwyn.mat_[i][j] = this->mat_[i][j] + mat2.mat_[i][j];
        }
    }
    return matwyn;
}

algebra::Matrix algebra::Matrix::Sub(const algebra::Matrix mat2) const {
    if(this->Size() != mat2.Size()){
        return algebra::Matrix();
    }
    Matrix matwyn(dimx_,dimy_);
    for(int i=0;i<dimy_;++i){
        for(int j=0;j<dimx_;++j){
            matwyn.mat_[i][j] = this->mat_[i][j] - mat2.mat_[i][j];
        }
    }
    return matwyn;
}

algebra::Matrix algebra::Matrix::Mul(const algebra::Matrix mat2) const {
    if(this->Size().first != mat2.Size().second){
        return algebra::Matrix();
    }
    Matrix matwyn(mat2.dimx_,dimy_);
    for(int i=0;i<dimy_;++i){
        for(int j=0;j<mat2.dimx_;++j){
            std::complex<double> tmp = 0.;
            for(int k=0;k<dimx_;++k){
                tmp += this->mat_[i][k] * mat2.mat_[k][j];
            }
            matwyn.mat_[i][j] = tmp;
        }
    }
    return matwyn;
}

algebra::Matrix algebra::Matrix::Pow(int p) const {
    return algebra::Matrix();
}

algebra::Matrix::Matrix(algebra::Matrix &&mat) : mat_{mat.mat_}{
    dimy_ = mat.dimy_;
    dimx_ = mat.dimx_;
    mat.mat_ = nullptr;
}

algebra::Matrix &algebra::Matrix::operator=(algebra::Matrix &&mat) {
    if(&mat == this)
        return *this;
    for(int i=0;i<dimy_;++i){
        delete [] mat_[i];
    }
    delete [] mat_;
    dimy_ = mat.dimy_;
    dimx_ = mat.dimx_;
    mat_ = mat.mat_;
    mat.mat_ = nullptr;
    return *this;
}
