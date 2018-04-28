//
// Created by kluch on 28.04.18.
//

#include "Iterable.h"


bool utility::ZipperIterator::NotEquals(const std::unique_ptr<utility::IterableIterator>&other) const {
    const ZipperIterator *other2 = dynamic_cast<const ZipperIterator *>(other.get());
    return !(l1_ == other2->l1_ && r1_ == other2->r1_ && l2_ == other2->l2_ && r2_ == other2->r2_);
}

std::pair<int, std::string> utility::ZipperIterator::Dereference() const {
    int left_value;
    std::string right_value;
    if (l1_ != l2_) {
        left_value = *l1_;
    } else {
        left_value = *(l1_ - 1);
    }
    if (r1_ != r2_) {
        right_value = *r1_;
    } else {
        right_value = *(r1_ - 1);
    }
    return std::make_pair(left_value, right_value);
}

utility::IterableIterator &utility::ZipperIterator::Next() {
    if (l1_ != l2_) l1_++;
    if (r1_ != r2_) r1_++;
    return *this;
}

utility::ZipperIterator::ZipperIterator(std::vector<int>::const_iterator left, std::vector<std::string>::const_iterator right,
                                        std::vector<int>::const_iterator left_end, std::vector<std::string>::const_iterator right_end) {
    l1_ = left;
    l2_ = left_end;
    r1_ = right;
    r2_ = right_end;
}

utility::IterableIteratorWrapper::IterableIteratorWrapper(std::unique_ptr<utility::IterableIterator> iterator) {
    iter_ = move(iterator);
}

bool utility::IterableIteratorWrapper::operator!=(const utility::IterableIteratorWrapper &other) const {
    return iter_->NotEquals(other.iter_);
}

std::pair<int, std::string> utility::IterableIteratorWrapper::operator*() const {
    return iter_->Dereference();
}

utility::IterableIteratorWrapper &utility::IterableIteratorWrapper::operator++() {
    iter_->Next();
    return *this;
}

utility::IterableIteratorWrapper utility::Iterable::begin() const {
    return cbegin();
}

utility::IterableIteratorWrapper utility::Iterable::end() const {
    return cend();
}

utility::IterableIteratorWrapper utility::Iterable::cbegin() const {
    std::unique_ptr<IterableIterator> p = ConstBegin();
    return IterableIteratorWrapper(move(p));
}

utility::IterableIteratorWrapper utility::Iterable::cend() const {
    std::unique_ptr<IterableIterator> p = ConstEnd();
    return IterableIteratorWrapper(move(p));
}

std::unique_ptr<utility::IterableIterator> utility::Zipper::ConstBegin() const {
    std::unique_ptr<IterableIterator> p = std::make_unique<ZipperIterator>(prod_bg);
    return move(p);
}

std::unique_ptr<utility::IterableIterator> utility::Zipper::ConstEnd() const {
    std::unique_ptr<IterableIterator> p = std::make_unique<ZipperIterator>(prod_en);
    return move(p);
}

utility::Zipper::Zipper(const std::vector<int> &vi, const std::vector<std::string> &vs) : prod_bg{vi.begin(), vs.begin(), vi.end(), vs.end()},
                                                                                          prod_en{vi.end(), vs.end(), vi.end(), vs.end()}
{}


utility::EnumerateIterator::EnumerateIterator(std::vector<std::string>::const_iterator begin,
                                              std::vector<std::string>::const_iterator end) {
    this->begin=begin;
    this->end = end;

}


std::pair<int, std::string> utility::EnumerateIterator::Dereference() const {
    return std::make_pair(getIndex(),getString()) ;
}

utility::IterableIterator &utility::EnumerateIterator::Next() {
    if (begin != end) {
        ++begin;
        ++index;
    }

    return *this;
}

bool utility::EnumerateIterator::NotEquals(const std::unique_ptr<utility::IterableIterator> &other) const {
    const EnumerateIterator *s = dynamic_cast<const EnumerateIterator *>(other.get());
    return !(begin == s->begin
             && end == s->end);
}

int utility::EnumerateIterator::getIndex() const {
    return index;
}

std::string utility::EnumerateIterator::getString() const {
    return *this->begin;
}


utility::Enumerate::Enumerate(const std::vector<std::string> & vs) : enumerate_begin{vs.begin(), vs.end()}, enumerate_end{vs.end(),vs.end()}
{
}

std::unique_ptr<utility::IterableIterator> utility::Enumerate::ConstBegin() const {
    std::unique_ptr<IterableIterator> p = std::make_unique<utility::EnumerateIterator>(enumerate_begin);
    return move(p);
}

std::unique_ptr<utility::IterableIterator> utility::Enumerate::ConstEnd() const {
    std::unique_ptr<IterableIterator> p = std::make_unique<EnumerateIterator>(enumerate_end);
    return move(p);
}

std::pair<int, std::string> utility::ProductIterator::Dereference() const {
    std::string right_value;
    int left_value;
    if (r1_ != r3_) {
        right_value = *r1_;
    } else {
        right_value = *(r1_ - 1);
    }
    if (l1_ != l3_) {
        left_value = *l1_;
    } else {
        left_value = *(l1_ - 1);
    }
    return std::make_pair(left_value, right_value);
}

utility::IterableIterator & utility::ProductIterator::Next() {
    if (l1_ != l3_) {
        ++r1_;
        if(r1_==r3_){
            ++l1_;
            r1_=r2_;
        }

    }
    if(l1_==l3_){
        r1_=r3_;
        l1_=l3_;
    }
    return *this;
}

bool utility::ProductIterator::NotEquals(const std::unique_ptr<utility::IterableIterator> &other) const {
    const ProductIterator *s = dynamic_cast<const ProductIterator *>(other.get());
    return !(l1_ == s->l1_
             && r1_ == s->r1_
             && l3_ == s->l3_
             && r3_ == s->r3_);
}

utility::ProductIterator::ProductIterator(std::vector<int>::const_iterator left, std::vector<std::string>::const_iterator right,
                                          std::vector<int>::const_iterator left_end, std::vector<std::string>::const_iterator right_end) {
    l1_ = left;
    l2_ = left;
    l3_ = left_end;
    r1_ = right;
    r2_ = right;
    r3_ = right_end;
}


std::unique_ptr<utility::IterableIterator> utility::Product::ConstBegin() const {
    std::unique_ptr<IterableIterator> p = std::make_unique<ProductIterator>(prod_bg);
    return move(p);
}

std::unique_ptr<utility::IterableIterator> utility::Product::ConstEnd() const {
    std::unique_ptr<IterableIterator> p = std::make_unique<ProductIterator>(prod_en);
    return move(p);
}

utility::Product::Product(const std::vector<int> & vi, const std::vector<std::string> & vs): prod_bg{vi.begin(), vs.begin(), vi.end(), vs.end()},
                                                                                    prod_en{vi.end(), vs.end(), vi.end(), vs.end()} {

}