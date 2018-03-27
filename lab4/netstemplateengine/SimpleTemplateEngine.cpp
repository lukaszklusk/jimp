//
// Created by kluch on 27.03.18.
//

#include "SimpleTemplateEngine.h"

nets::View::View(std::string templ) {
    templ_ = templ;
}

std::string nets::View::Render(const std::unordered_map<std::string, std::string> &model) const {
    std::string result,match;
    result = templ_;
    unsigned long int d = model.size();
    for(const auto &m : model){
        match = "{{" + m.first + "}}";
        for(int i=0;i<result.size();++i){
            if(result[i] == '{' && result[i-1] != '#'){
                if(result.substr(i,match.size()) == match){
                    result.replace(i,match.size(),m.second);
                    result.insert(i,"#");
                }
            }
        }
    }
    int pos=-1,dl=0;
    for(int i=0;i<result.size()-1;++i){
        if(result[i] == '#')result.erase(i,1);
        if(result[i] == '{' && result[i+1] == '{'){
            pos = i;
        }
        if(pos != -1 && result[i] == ' '){
            pos = -1;
        }
        if(result[i] == '}' && result[i+1] == '}' && pos != -1){
            dl = i - pos + 2;
            bool inject = false;
            match = result.substr(pos,dl);
            for(const auto &m : model){
                if(m.second == match)inject = true;
            }
            if(!inject){
                result.erase(pos,dl);
                i = pos;
            }
        }
    }
    return result;
}
