//
// Created by kluch on 27.03.18.
//

#ifndef JIMP_EXERCISES_SIMPLEJSON_H
#define JIMP_EXERCISES_SIMPLEJSON_H

#include <experimental/optional>
#include <string>
#include <map>
#include <vector>

namespace nets{
    class JsonValue{
    public:
        JsonValue(int val);
        JsonValue(double val);
        JsonValue(std::string val);
        JsonValue(bool val);
        JsonValue(std::map <std::string,JsonValue> val);
        JsonValue(std::vector <JsonValue> val);
        std::experimental::optional<JsonValue> ValueByName(const std::string &name) const;
        std::string ToString() const;
        ~JsonValue();
    private:
        int *in_;
        double *db_;
        std::string *str_;
        bool *bl_;
        std::map <std::string,nets::JsonValue> *map_;
        std::vector <nets::JsonValue> *vec_;
    };
}

#endif //JIMP_EXERCISES_SIMPLEJSON_H
