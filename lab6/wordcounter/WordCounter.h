//
// Created by kluch on 13.04.18.
//

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H

#include <string>
#include <initializer_list>
#include <iostream>
#include <utility>
#include <vector>
#include <fstream>
#include <set>

namespace datastructures{
    class Counts{
    public:
        Counts(int val_in);
        friend const bool operator==(const Counts& l,const Counts& r){
            return l.val_ == r.val_;
        }
        friend const bool operator==(const int l,const Counts& r){
            return l == r.val_;
        }
        friend class WordCounter;
    private:
        int val_;
    };
    class Word{
    public:
        Word(std::string word_in);
        friend const bool operator==(const Word& l,const Word& r){
            return l.word_ == r.word_;
        }
        friend const bool operator<(const Word& l,const Word& r){
            return l.word_ < r.word_;
        }
        friend class WordCounter;
    private:
        std::string word_;
    };
    class WordCounter{
    public:
        WordCounter();
        WordCounter(std::initializer_list<Word> words_inpt);
        unsigned long DistinctWords() const;
        int TotalWords() const;
        Counts operator[](std::string word_f) const;
        std::set<Word> Words();
    private:
        std::vector<std::pair<Word,Counts>> dict_;
    };



}

#endif //JIMP_EXERCISES_WORDCOUNTER_H
