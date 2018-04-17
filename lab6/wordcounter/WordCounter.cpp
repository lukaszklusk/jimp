//
// Created by kluch on 13.04.18.
//

#include "WordCounter.h"

datastructures::Counts::Counts(int val_in) {
    val_ = val_in;
}

datastructures::Word::Word(std::string word_in) {
    word_ = word_in;
}


datastructures::WordCounter::WordCounter() {

}

unsigned long datastructures::WordCounter::DistinctWords() const {
    return dict_.size();
}

int datastructures::WordCounter::TotalWords() const {
    int res = 0;
    for(auto a : dict_){
        res += a.second.val_;
    }
    return res;
}

datastructures::WordCounter::WordCounter(std::initializer_list<datastructures::Word> words_inpt) {
    for(auto a: words_inpt){
        if(dict_.empty()){
            std::pair<Word,Counts> n(a,1);
            dict_.push_back(n);
        }else{
            bool f = true;
            for(int i=0;i<dict_.size();i++){
                if(dict_[i].first.word_ == a.word_){
                    dict_[i].second.val_ += 1;
                    f = false;
                    break;
                }
            }
            if(f){
                std::pair<Word,Counts> n(a,1);
                dict_.push_back(n);
            }
        }
    }
}

datastructures::Counts datastructures::WordCounter::operator[](std::string word_f) const {
    for(auto a: dict_){
        if(a.first.word_ == word_f){
            return a.second;
        }
    }
    return Counts(0);
}

std::set<datastructures::Word> datastructures::WordCounter::Words() {
    std::set<Word> n;
    for(auto a: dict_){
        n.insert(a.first);
    }
    return n;
}
