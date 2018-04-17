//
// Created by kluch on 11.04.18.
//

#include "StudentRepository.h"

academia::StudyYear::StudyYear() {
    year_ = 1;
}

academia::StudyYear::StudyYear(int new_year) {
    year_ = new_year;
}

bool academia::StudyYear::operator==(const int l) {
    if(this->year_ == l) return true;
    return false;
}

bool academia::StudyYear::operator<(const StudyYear l) const {
    if(this->year_ < l.year_) return true;
    return false;
}

