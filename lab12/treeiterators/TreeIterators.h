//
// Created by kluch on 12.06.18.
//

#ifndef JIMP_EXERCISES_TREEITERATORS_H
#define JIMP_EXERCISES_TREEITERATORS_H

#include "../tree/Tree.h"
#include <vector>

namespace tree{
    template<typename Element>
    class InOrderTreeIterator{
    public:
        InOrderTreeIterator(std::shared_ptr<Tree<Element>> node);
        void Position(std::shared_ptr<Tree<Element>> node);
        InOrderTreeIterator<Element> operator++();
        Element operator*();
        InOrderTreeIterator<Element> End();
        bool operator!=(const InOrderTreeIterator &o) const;
    private:
        unsigned long id_;
        std::vector<std::shared_ptr<Tree<Element>>> list_;
    };

    template<typename Element>
    InOrderTreeIterator<Element>::InOrderTreeIterator(std::shared_ptr<Tree<Element>> node) {
        Position(node);
        id_ = 0;
    }

    template<typename Element>
    void InOrderTreeIterator<Element>::Position(std::shared_ptr<Tree<Element>> node) {
        if(node->left_) Position(node->left_);
        list_.emplace_back(node);
        if(node->right_) Position(node->right_);
    }

    template<typename Element>
    InOrderTreeIterator<Element> InOrderTreeIterator<Element>::operator++() {
        id_++;
        return *this;
    }

    template<typename Element>
    Element InOrderTreeIterator<Element>::operator*() {
        return list_[id_]->Value();
    }

    template<typename Element>
    InOrderTreeIterator<Element> InOrderTreeIterator<Element>::End() {
        id_ = list_.size();
        return *this;
    }

    template<typename Element>
    bool InOrderTreeIterator<Element>::operator!=(const InOrderTreeIterator &o) const {
        return id_ != o.id_;
    }

    template<typename Element>
    class InOrderTreeView{
    public:
        InOrderTreeView(Tree<Element> *node);
        InOrderTreeIterator<Element> begin();
        InOrderTreeIterator<Element> end();
    private:
        std::shared_ptr<Tree<Element>> root_;
    };

    template<typename Element>
    InOrderTreeView<Element>::InOrderTreeView(Tree<Element> *node) {
        root_ = std::make_shared<Tree<Element>>(*node);
    }

    template<typename Element>
    InOrderTreeIterator<Element> InOrderTreeView<Element>::begin() {
        return InOrderTreeIterator<Element>(root_);
    }

    template<typename Element>
    InOrderTreeIterator<Element> InOrderTreeView<Element>::end() {
        return InOrderTreeIterator<Element>(root_).End();
    }

    template<typename Element>
    InOrderTreeView<Element> InOrder(Tree<Element> *t){
        return InOrderTreeView<Element>(t);
    }

    //###############################################################################################

    template<typename Element>
    class PostOrderTreeIterator{
    public:
        PostOrderTreeIterator(std::shared_ptr<Tree<Element>> node);
        void Position(std::shared_ptr<Tree<Element>> node);
        PostOrderTreeIterator<Element> operator++();
        Element operator*();
        PostOrderTreeIterator<Element> End();
        bool operator!=(const PostOrderTreeIterator &o) const;
    private:
        unsigned long id_;
        std::vector<std::shared_ptr<Tree<Element>>> list_;
    };

    template<typename Element>
    PostOrderTreeIterator<Element>::PostOrderTreeIterator(std::shared_ptr<Tree<Element>> node) {
        Position(node);
        id_ = 0;
    }

    template<typename Element>
    void PostOrderTreeIterator<Element>::Position(std::shared_ptr<Tree<Element>> node) {
        if(node->left_) Position(node->left_);
        if(node->right_) Position(node->right_);
        list_.emplace_back(node);
    }

    template<typename Element>
    PostOrderTreeIterator<Element> PostOrderTreeIterator<Element>::operator++() {
        id_++;
        return *this;
    }

    template<typename Element>
    Element PostOrderTreeIterator<Element>::operator*() {
        return list_[id_]->Value();
    }

    template<typename Element>
    PostOrderTreeIterator<Element> PostOrderTreeIterator<Element>::End() {
        id_ = list_.size();
        return *this;
    }

    template<typename Element>
    bool PostOrderTreeIterator<Element>::operator!=(const PostOrderTreeIterator &o) const {
        return id_ != o.id_;
    }

    template<typename Element>
    class PostOrderTreeView{
    public:
        PostOrderTreeView(Tree<Element> *node);
        PostOrderTreeIterator<Element> begin();
        PostOrderTreeIterator<Element> end();
    private:
        std::shared_ptr<Tree<Element>> root_;
    };

    template<typename Element>
    PostOrderTreeView<Element>::PostOrderTreeView(Tree<Element> *node) {
        root_ = std::make_shared<Tree<Element>>(*node);
    }

    template<typename Element>
    PostOrderTreeIterator<Element> PostOrderTreeView<Element>::begin() {
        return PostOrderTreeIterator<Element>(root_);
    }

    template<typename Element>
    PostOrderTreeIterator<Element> PostOrderTreeView<Element>::end() {
        return PostOrderTreeIterator<Element>(root_).End();
    }

    template<typename Element>
    PostOrderTreeView<Element> PostOrder(Tree<Element> *t){
        return PostOrderTreeView<Element>(t);
    }

    //#####################################################################################################

    template<typename Element>
    class PreOrderTreeIterator{
    public:
        PreOrderTreeIterator(std::shared_ptr<Tree<Element>> node);
        void Position(std::shared_ptr<Tree<Element>> node);
        PreOrderTreeIterator<Element> operator++();
        Element operator*();
        PreOrderTreeIterator<Element> End();
        bool operator!=(const PreOrderTreeIterator &o) const;
    private:
        unsigned long id_;
        std::vector<std::shared_ptr<Tree<Element>>> list_;
    };

    template<typename Element>
    PreOrderTreeIterator<Element>::PreOrderTreeIterator(std::shared_ptr<Tree<Element>> node) {
        Position(node);
        id_ = 0;
    }

    template<typename Element>
    void PreOrderTreeIterator<Element>::Position(std::shared_ptr<Tree<Element>> node) {
        list_.emplace_back(node);
        if(node->left_) Position(node->left_);
        if(node->right_) Position(node->right_);
    }

    template<typename Element>
    PreOrderTreeIterator<Element> PreOrderTreeIterator<Element>::operator++() {
        id_++;
        return *this;
    }

    template<typename Element>
    Element PreOrderTreeIterator<Element>::operator*() {
        return list_[id_]->Value();
    }

    template<typename Element>
    PreOrderTreeIterator<Element> PreOrderTreeIterator<Element>::End() {
        id_ = list_.size();
        return *this;
    }

    template<typename Element>
    bool PreOrderTreeIterator<Element>::operator!=(const PreOrderTreeIterator &o) const {
        return id_ != o.id_;
    }

    template<typename Element>
    class PreOrderTreeView{
    public:
        PreOrderTreeView(Tree<Element> *node);
        PreOrderTreeIterator<Element> begin();
        PreOrderTreeIterator<Element> end();
    private:
        std::shared_ptr<Tree<Element>> root_;
    };

    template<typename Element>
    PreOrderTreeView<Element>::PreOrderTreeView(Tree<Element> *node) {
        root_ = std::make_shared<Tree<Element>>(*node);
    }

    template<typename Element>
    PreOrderTreeIterator<Element> PreOrderTreeView<Element>::begin() {
        return PreOrderTreeIterator<Element>(root_);
    }

    template<typename Element>
    PreOrderTreeIterator<Element> PreOrderTreeView<Element>::end() {
        return PreOrderTreeIterator<Element>(root_).End();
    }

    template<typename Element>
    PreOrderTreeView<Element> PreOrder(Tree<Element> *t){
        return PreOrderTreeView<Element>(t);
    }


}

#endif //JIMP_EXERCISES_TREEITERATORS_H
