//
// Created by kluch on 11.04.18.
//

#ifndef JIMP_EXERCISES_STUDENTREPOSITORY_H
#define JIMP_EXERCISES_STUDENTREPOSITORY_H

namespace academia{
    class StudyYear{
    public:
        StudyYear();
        StudyYear(int new_year);
        bool operator==(const int l);
        bool operator<(const StudyYear l) const;
    private:
        int year_;
    };
}

#endif //JIMP_EXERCISES_STUDENTREPOSITORY_H
