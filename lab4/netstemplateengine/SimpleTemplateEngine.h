//
// Created by kluch on 27.03.18.
//

#ifndef JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#define JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H

#include <string>
#include <unordered_map>

namespace nets {
    class View{
    public:
        View(std::string templ);
        std::string Render(const std::unordered_map <std::string, std::string> &model) const;
    private:
        std::string templ_;
    };

}

#endif //JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
