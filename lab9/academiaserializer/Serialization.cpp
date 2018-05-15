//
// Created by kluch on 09.05.18.
//

#include "Serialization.h"

academia::Room::Room(int num, std::string str, academia::Room::Type typ) {
    num_ = num;
    str_ = str;
    typ_ = typ;
}

void academia::Room::Serialize(academia::Serializer *ser) const {
    ser->Header("room");
    ser->comma_ = true;
    ser->IntegerField("id",num_);
    ser->StringField("name",str_);
    ser->comma_ = false;
    if(typ_ == Type::COMPUTER_LAB)
        ser->StringField("type","COMPUTER_LAB");
    if(typ_ == Type::CLASSROOM)
        ser->StringField("type","CLASSROOM");
    if(typ_ == Type::LECTURE_HALL)
        ser->StringField("type","LECTURE_HALL");
    ser->Footer("room");
}

void academia::JsonSerializer::Header(const std::string &object_name) {
    out_ << "{";
}

void academia::JsonSerializer::Footer(const std::string &object_name) {
    out_ << "}";
}

void academia::JsonSerializer::IntegerField(const std::string &field_name, int value) {
    out_ << "\"" << field_name << "\": " << std::to_string(value);
    if(comma_) out_ << ", ";
}

void academia::JsonSerializer::StringField(const std::string &field_name, const std::string &value) {
    out_ << "\"" << field_name << "\": \"" << value << "\"";
    if(comma_) out_ << ", ";
}

void academia::JsonSerializer::DoubleField(const std::string &field_name, double value) {

}

void academia::JsonSerializer::BooleanField(const std::string &field_name, bool value) {

}

void academia::JsonSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {

}

void academia::JsonSerializer::ArrayField(const std::string &field_name,
                                          const std::vector<std::reference_wrapper<const academia::Serializable>> &value) {
    out_ << "\"" << field_name << "\": [";
    int d = value.size();
    bool inner_comma = true;
    for(const Serializable &tmp: value){
        d--;
        if(d == 0)inner_comma = false;
        tmp.Serialize(this);
        if(inner_comma) out_ << ", ";
    }
    out_ <<"]";
    if(comma_) out_ << ", ";
}

academia::Building::Building(int num, std::string str, std::vector<academia::Room> rooms) {
    num_ = num;
    str_ = str;
    rooms_ = rooms;
}

void academia::Building::Serialize(academia::Serializer *ser) const {
    std::vector<std::reference_wrapper<const Serializable>> rooms_as_rw;
    for(const auto &tmp: rooms_){
        rooms_as_rw.emplace_back(tmp);
    }
    ser->Header("building");
    ser->comma_ = true;
    ser->IntegerField("id",num_);
    ser->StringField("name",str_);
    ser->comma_ = false;
    ser->ArrayField("rooms",rooms_as_rw);
    ser->Footer("building");
}

int academia::Building::Id() {
    return num_;
}

void academia::XmlSerializer::Header(const std::string &object_name) {
    out_ << "<" << object_name << ">";
}

void academia::XmlSerializer::Footer(const std::string &object_name) {
    out_ << "<\\" << object_name << ">";
}

void academia::XmlSerializer::IntegerField(const std::string &field_name, int value) {
    out_ << "<" << field_name << ">" << std::to_string(value) << "<\\" << field_name << ">";
}

void academia::XmlSerializer::StringField(const std::string &field_name, const std::string &value) {
    out_ << "<" << field_name << ">" << value << "<\\" << field_name << ">";
}

void academia::XmlSerializer::DoubleField(const std::string &field_name, double value) {

}

void academia::XmlSerializer::BooleanField(const std::string &field_name, bool value) {

}

void academia::XmlSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {

}

void academia::XmlSerializer::ArrayField(const std::string &field_name,
                                         const std::vector<std::reference_wrapper<const academia::Serializable>> &value) {
    out_ << "<" << field_name << ">";
    for(const Serializable &tmp : value){
        tmp.Serialize(this);
    }
    out_ << "<\\" << field_name << ">";
}

academia::BuildingRepository::BuildingRepository(std::initializer_list<academia::Building> buildings): buildings_{buildings} {

}

void academia::BuildingRepository::StoreAll(academia::Serializer *ser) {
    std::vector<std::reference_wrapper<const Serializable>> buildings_as_rw;
    for(const auto &tmp: buildings_){
        buildings_as_rw.emplace_back(tmp);
    }
    ser->Header("building_repository");
    ser->ArrayField("buildings",buildings_as_rw);
    ser->Footer("building_repository");
}

void academia::BuildingRepository::Add(const academia::Building &new_build) {
    buildings_.emplace_back(new_build);
}

std::experimental::optional<academia::Building> academia::BuildingRepository::operator[](int num) const {
    for(auto tmp: buildings_){
        if(num == tmp.Id()){
            return std::experimental::make_optional(tmp);
        }
    }
    return {};
}
