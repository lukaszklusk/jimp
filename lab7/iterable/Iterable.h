//
// Created by kluch on 28.04.18.
//

#ifndef JIMP_EXERCISES_ITERABLE_H
#define JIMP_EXERCISES_ITERABLE_H

#include <string>
#include <vector>
#include<memory>
namespace utility {
    class IterableIterator {
    public:
        virtual ~IterableIterator() = default;
        virtual std::pair<int, std::string> Dereference() const = 0;
        virtual IterableIterator &Next() = 0;
        virtual bool NotEquals(const std::unique_ptr<utility::IterableIterator> &other) const = 0;
    };
    
    class ZipperIterator : public IterableIterator {
    public:
        explicit ZipperIterator(std::vector<int>::const_iterator left, std::vector<std::string>::const_iterator right,
                                std::vector<int>::const_iterator left_end, std::vector<std::string>::const_iterator right_end);
        std::pair<int, std::string> Dereference() const override;
        IterableIterator &Next() override;
        bool NotEquals(const std::unique_ptr<utility::IterableIterator> &other) const override;
    private:
        std::vector<int>::const_iterator l1_;
        std::vector<int>::const_iterator l2_;
        std::vector<std::string>::const_iterator r1_;
        std::vector<std::string>::const_iterator r2_;
    };

    class IterableIteratorWrapper {
    public:
        IterableIteratorWrapper(std::unique_ptr<IterableIterator> iterator);
        bool operator!=(const IterableIteratorWrapper &other) const;
        std::pair<int, std::string> operator*() const;
        IterableIteratorWrapper &operator++();
    private:
        std::unique_ptr<IterableIterator> iter_;
    };

    class Iterable {
    public:
        IterableIteratorWrapper cbegin() const;
        IterableIteratorWrapper cend() const;
        IterableIteratorWrapper begin() const;
        IterableIteratorWrapper end() const;
    protected:
        virtual std::unique_ptr<IterableIterator> ConstBegin() const = 0;
        virtual std::unique_ptr<IterableIterator> ConstEnd() const = 0;
    };

    class EnumerateIterator : public IterableIterator {
    public:
        std::pair<int, std::string> Dereference() const override;

        IterableIterator &Next() override;
        bool NotEquals(const std::unique_ptr<utility::IterableIterator> &other) const override;
        explicit EnumerateIterator(std::vector<std::string >::const_iterator begin, std::vector<std::string >::const_iterator end);
        int getIndex() const;
        std::string getString() const;
    private:
        std::vector<std::string >::const_iterator begin;
        std::vector<std::string >::const_iterator end;
        int index =1;
    };

    class Enumerate: public Iterable
    {
    public:
        explicit Enumerate(const  std::vector<std::string> & vs);
        std::unique_ptr<IterableIterator> ConstBegin() const override;
        std::unique_ptr<IterableIterator> ConstEnd()const override;
    private:
        EnumerateIterator enumerate_begin;
        EnumerateIterator enumerate_end;

    };

    class Zipper : public Iterable {
    public:
        Zipper(const std::vector<int> &, const std::vector<std::string>&);
    protected:
        std::unique_ptr<IterableIterator> ConstBegin() const override;
        std::unique_ptr<IterableIterator> ConstEnd() const override;
    private:
        ZipperIterator prod_bg;
        ZipperIterator prod_en;
    };

    class ProductIterator : public IterableIterator {
    public:
        explicit ProductIterator(std::vector<int>::const_iterator left, std::vector<std::string>::const_iterator right,
                                 std::vector<int>::const_iterator left_end, std::vector<std::string>::const_iterator right_end);
        std::pair<int, std::string> Dereference() const override;
        IterableIterator &Next() override;
        bool NotEquals(const std::unique_ptr<utility::IterableIterator> &other) const override;
    private:
        std::vector<int>::const_iterator l1_;
        std::vector<int>::const_iterator l2_;
        std::vector<int>::const_iterator l3_;
        std::vector<std::string>::const_iterator r1_;
        std::vector<std::string>::const_iterator r3_;
        std::vector<std::string>::const_iterator r2_;
    };

    class Product : public Iterable {
    public:
        Product(const std::vector<int>&, const std::vector<std::string>&);
    protected:
        std::unique_ptr<IterableIterator> ConstBegin() const override;
        std::unique_ptr<IterableIterator> ConstEnd() const override;
    private:
        ProductIterator prod_bg;
        ProductIterator prod_en;
    };
}


#endif //JIMP_EXERCISES_ITERABLE_H
