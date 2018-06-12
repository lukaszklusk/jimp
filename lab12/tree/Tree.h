//
// Created by kluch on 06.06.18.
//

#ifndef JIMP_EXERCISES_TREE_H
#define JIMP_EXERCISES_TREE_H

#include <memory>

namespace tree{
    template <typename Element>
    class Tree{
    public:
        Tree();
        Tree(Element val);
        Element Value();
        size_t Depth();
        size_t Size();
        void Insert(const Element &val);
        bool Find(const Element &val);
    private:
        Element val_;
        std::unique_ptr<Tree> left_;
        std::unique_ptr<Tree> right_;
        size_t dpth_;
        size_t size_;
    };

    template<typename Element>
    Tree<Element>::Tree() {
        val_ = Element();
        size_ = 0;
        dpth_ = 0;
        right_ = nullptr;
        left_ = nullptr;
    }

    template<typename Element>
    Tree<Element>::Tree(Element val) {
        val_ = val;
        size_ = 1;
        dpth_ = 1;
        right_ = nullptr;
        left_ = nullptr;
    }

    template<typename Element>
    Element Tree<Element>::Value() {
        return val_;
    }

    template<typename Element>
    size_t Tree<Element>::Depth() {
        return dpth_;
    }

    template<typename Element>
    size_t Tree<Element>::Size() {
        return size_;
    }

    template<typename Element>
    void Tree<Element>::Insert(const Element &val) {
        if(size_ == 0){
            val_ = val;
            size_ = 1;
            dpth_ = 1;
            right_ = nullptr;
            left_ = nullptr;
            return;
        }
        if(val > val_){
            if(right_ == nullptr){
                right_ = std::make_unique<Tree<Element>>(Tree<Element> {val});

            }else{
                right_->Insert(val);
            }
            dpth_ = right_->Depth()+1;
        }else{
            if(left_ == nullptr){
                left_ = std::make_unique<Tree<Element>>(Tree<Element> {val});

            }else{
                left_->Insert(val);
            }
            dpth_ = left_->Depth()+1;
        }
        if(right_ != nullptr){
            if(left_ != nullptr) size_ = left_->Size() + right_->Size() + 1;
            else size_ = right_->Size() + 1;
        }else{
            if(left_ != nullptr) size_ = left_->Size() + 1;
            else size_ = 1;
        }
    }

    template<typename Element>
    bool Tree<Element>::Find(const Element &val) {
        if(val_ == val)return true;
        return false;
    }


}

#endif //JIMP_EXERCISES_TREE_H
