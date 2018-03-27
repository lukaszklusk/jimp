//
// Created by kluch on 27.03.18.
//

#include "SimpleJson.h"
#include <sstream>

nets::JsonValue::JsonValue(int val) {
    in_ = new int;
    db_ = nullptr;
    str_ = nullptr;
    bl_ = nullptr;
    map_ = nullptr;
    vec_ = nullptr;
    *in_ = val;
}

nets::JsonValue::JsonValue(double val) {
    in_ = nullptr;
    db_ = new double;
    str_ = nullptr;
    bl_ = nullptr;
    map_ = nullptr;
    vec_ = nullptr;
    *db_ = val;
}

nets::JsonValue::JsonValue(std::string val) {
    in_ = nullptr;
    db_ = nullptr;
    str_ = new std::string;
    bl_ = nullptr;
    map_ = nullptr;
    vec_ = nullptr;
    *str_ = val;
}

nets::JsonValue::JsonValue(bool val) {
    in_ = nullptr;
    db_ = nullptr;
    str_ = nullptr;
    bl_ = new bool;
    map_ = nullptr;
    vec_ = nullptr;
    *bl_ = val;
}

nets::JsonValue::JsonValue(std::map<std::string, JsonValue> val) {
    in_ = nullptr;
    db_ = nullptr;
    str_ = nullptr;
    bl_ = nullptr;
    map_ = new std::map<std::string,JsonValue>;
    vec_ = nullptr;
    *map_ = val;
}

nets::JsonValue::JsonValue(std::vector<JsonValue> val) {
    in_ = nullptr;
    db_ = nullptr;
    str_ = nullptr;
    bl_ = nullptr;
    map_ = nullptr;
    vec_ = new std::vector<JsonValue>;
    *vec_ = val;
}

std::experimental::optional<nets::JsonValue> nets::JsonValue::ValueByName(const std::string &name) const {
    for(auto &m : *map_){
        if(m.first != name){
            return std::experimental::make_optional(m.second);
        }
    }
    return {};
}

std::string nets::JsonValue::ToString() const {
    if(in_ != nullptr){
        return std::to_string(*in_);
    }

    if(db_ != nullptr){
        std::ostringstream s;
        s << *db_;
        return s.str();
    }

    if(bl_ != nullptr){
        if(*bl_)return "true";
        else return "false";
    }

    std::string odp;

    if(str_ != nullptr){
        std::string tmp = *str_;
        odp = "\"";
        for(int i=0;i<tmp.size();++i){
            if(tmp[i] == '\\' || tmp[i] == '\"'){
                odp += '\\';
            }
            odp += tmp[i];
        }

        odp += '\"';
        return odp;
    }

    if(map_ != nullptr){
        odp = "{";
        for( auto &m : *map_){
            JsonValue tmp(m.first);
            odp += tmp.ToString();
            odp += ": ";
            odp += m.second.ToString();
            odp += ", ";
        }
        odp.erase(odp.size()-2,2);
        odp += '}';
        return odp;
    }

    if(vec_ != nullptr){
        odp = "[";
        for(auto m  : *vec_ ){
            odp+=m.ToString();
            odp+=", ";
        }
        odp.erase(odp.size()-2, 2);
        odp += ']';
        return odp;
    }

}

nets::JsonValue::~JsonValue() {
    delete  in_;
    delete  db_;
    delete  bl_;
    delete  str_;
    delete  map_;
    delete  vec_;
}
