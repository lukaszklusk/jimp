//
// Created by kluch on 14.03.18.
//

#include <vector>
#include <sstream>
#include <regex>
#include <cmath>
#include "MinimalTimeDifference.h"

unsigned int minimaltimedifference::ToMinutes(std::string time_HH_MM){
    std::vector<std::string> godz;
    std::regex pattern {R"(\d{1,2}:\d{2})"};
    std::smatch sm;
    if(std::regex_match(time_HH_MM, sm, pattern)){
        return 1;
    }
    return 0;
}
unsigned int minimaltimedifference::MinimalTimeDifference(std::vector<std::string> times){
    return 0;
}