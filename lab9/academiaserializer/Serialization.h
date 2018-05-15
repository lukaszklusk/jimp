//
// Created by kluch on 09.05.18.
//

#ifndef JIMP_EXERCISES_SERIALIZATION_H
#define JIMP_EXERCISES_SERIALIZATION_H

#include <ostream>
#include <functional>
#include <vector>
#include <initializer_list>
#include <experimental/optional>

namespace academia{
    class Serializable;
    class Serializer {
    public:
        Serializer(std::ostream *out): out_{*out}{

        }
        virtual void IntegerField(const std::string &field_name, int value) = 0;
        virtual void DoubleField(const std::string &field_name, double value) = 0;
        virtual void StringField(const std::string &field_name, const std::string &value) = 0;
        virtual void BooleanField(const std::string &field_name, bool value) = 0;
        virtual void SerializableField(const std::string &field_name, const academia::Serializable &value) = 0;
        virtual void ArrayField(const std::string &field_name,
                        const std::vector<std::reference_wrapper<const academia::Serializable>> &value) = 0;
        virtual void Header(const std::string &object_name) = 0;
        virtual void Footer(const std::string &object_name) = 0;
        std::ostream &out_;
        bool comma_;
    };
    class JsonSerializer : public Serializer{
    public:
        JsonSerializer(std::ostream *out): Serializer(out){

        }
        void Header(const std::string &object_name) override;
        void Footer(const std::string &object_name) override;
        void IntegerField(const std::string &field_name, int value) override;
        void StringField(const std::string &field_name, const std::string &value) override;
        void DoubleField(const std::string &field_name, double value) override;
        void BooleanField(const std::string &field_name, bool value) override ;
        void SerializableField(const std::string &field_name, const academia::Serializable &value) override;
        void ArrayField(const std::string &field_name,
                                const std::vector<std::reference_wrapper<const academia::Serializable>> &value) override;
    };
    class XmlSerializer : public Serializer{
    public:
        XmlSerializer(std::ostream *out): Serializer(out){

        }
        void Header(const std::string &object_name) override;
        void Footer(const std::string &object_name) override;
        void IntegerField(const std::string &field_name, int value) override;
        void StringField(const std::string &field_name, const std::string &value) override;
        void DoubleField(const std::string &field_name, double value) override;
        void BooleanField(const std::string &field_name, bool value) override ;
        void SerializableField(const std::string &field_name, const academia::Serializable &value) override;
        void ArrayField(const std::string &field_name,
                        const std::vector<std::reference_wrapper<const academia::Serializable>> &value) override;
    };
    class Serializable{
    public:
        virtual void Serialize(Serializer * ser) const = 0;
    };
    class Room : public Serializable{
    public:
        enum class Type{
            COMPUTER_LAB,
            LECTURE_HALL,
            CLASSROOM
        };
        Room(int num, std::string str, Type typ);
        void Serialize(Serializer * ser)const override;

    private:
        int num_;
        std::string str_;
        Type typ_;
    };
    class Building : public Serializable{
    public:
        Building(int num,std::string str, std::vector<Room> rooms);
        void Serialize(Serializer *ser)const override;
        int Id();
    private:
        int num_;
        std::string str_;
        std::vector<Room> rooms_;
    };
    class BuildingRepository{
    public:
        BuildingRepository(std::initializer_list<Building> buildings);
        void StoreAll(Serializer *ser);
        void Add(const Building &new_build);
        std::experimental::optional<Building> operator[](int num) const;
    private:
        std::vector<Building> buildings_;
    };
}

#endif //JIMP_EXERCISES_SERIALIZATION_H
