//
// Created by kluch on 20.03.18.
//

#include <ostream>
#include <string>
#include <memory>
#include <queue>
#include "SmartTree.h"

namespace datastructures{
    std::unique_ptr <SmartTree> CreateLeaf(int value){
        std::unique_ptr<SmartTree> leaf = std::make_unique<SmartTree>();
        leaf->value = value;
        leaf->left = nullptr;
        leaf->right = nullptr;
        return leaf;
    }
    std::unique_ptr <SmartTree> InsertLeftChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> left_subtree){
        tree->left = std::move(left_subtree);
        return tree;
    }
    std::unique_ptr <SmartTree> InsertRightChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> right_subtree){
        tree->right = std::move(right_subtree);
        return tree;
    }
    void PrintTreeInOrder(const std::unique_ptr<SmartTree> &unique_ptr, std::ostream *out){
        if(unique_ptr->left != nullptr){
            PrintTreeInOrder(unique_ptr->left,out);
        }
        *out <<unique_ptr->value<<", ";
        if(unique_ptr->right != nullptr){
            PrintTreeInOrder(unique_ptr->right,out);
        }
    }
    std::string DumpTree(const std::unique_ptr<SmartTree> &tree){
        if(tree == nullptr)return "[none]";
        std::string wyj;
        wyj = "[" + std::to_string(tree->value) + " " + DumpTree(tree->left) + " " + DumpTree(tree->right) + "]";
        return wyj;

    }
    std::unique_ptr <SmartTree> RestoreTree(const std::string &tree){
        if(tree == "[none]")return nullptr;
        std::unique_ptr<SmartTree> leaf = std::make_unique<SmartTree>();
        int poz_d1_p=-1, poz_d1_k=-1,  poz_d2_p=-1, poz_d2_k=-1, stopien=0, poz_l = 0;
        for(int i=0;i<tree.size();++i){
            if(tree[i] == '['){
                if(stopien == 1){
                    if(poz_d1_p == -1){
                        poz_d1_p = i;
                    }else{
                        poz_d2_p = i;
                    }
                }
                stopien++;
            }
            if(tree[i] == ']'){
                if(stopien == 2){
                    if(poz_d1_k == -1){
                        poz_d1_k = i;
                    }else{
                        poz_d2_k = i;
                    }
                }
                stopien--;
            }
            if(stopien == 1 && (tree[i]>='0' && tree[i]<='9')){
                poz_l++;
            }
        }
        int value = std::stoi(tree.substr(1,poz_l+1));
        leaf->value = value;
        leaf->left = RestoreTree(tree.substr(poz_d1_p,(poz_d1_k-poz_d1_p+1)));
        leaf->right = RestoreTree(tree.substr(poz_d2_p,(poz_d2_k-poz_d2_p+1)));
        return leaf;
    }
}
