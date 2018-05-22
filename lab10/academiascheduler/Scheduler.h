//
// Created by kluch on 22.05.18.
//

#ifndef JIMP_EXERCISES_SCHEDULER_H
#define JIMP_EXERCISES_SCHEDULER_H

#include <vector>
#include <algorithm>
#include <map>
#include <set>

namespace academia{
    class SchedulingItem{
    public:
        SchedulingItem();
        SchedulingItem(int course_id, int teacher_id, int room_id, int time_slot, int year);
        int CourseId() const{
            return course_id_;
        }
        int TeacherId() const{
            return teacher_id_;
        }
        int RoomId() const{
            return room_id_;
        }
        int TimeSlot() const{
            return time_slot_;
        }
        int Year() const{
            return year_;
        }
    private:
        int course_id_;
        int teacher_id_;
        int room_id_;
        int time_slot_;
        int year_;
    };
    class Schedule{
    public:
        Schedule();
        Schedule OfTeacher(int teacher_id) const;
        Schedule OfRoom(int room_id) const;
        Schedule OfYear(int year) const;
        std::vector<int> AvailableTimeSlots(int n_time_slots) const;
        void InsertScheduleItem(const SchedulingItem &it);
        size_t Size() const;
        const SchedulingItem &operator[](int num) const;
        std::vector<SchedulingItem> scheduled_;
    };
    class Scheduler{
    public:
        virtual Schedule PrepareNewSchedule(const std::vector<int> &rooms, const std::map<int, std::vector<int>> &teacher_courses_assignment, const std::map<int, std::set<int>> &courses_of_year, int n_time_slots) =0;
    };
    class NoViableSolutionFound{};
    class GreedyScheduler: public Scheduler{
        Schedule PrepareNewSchedule(const std::vector<int> &rooms, const std::map<int, std::vector<int>> &teacher_courses_assignment, const std::map<int, std::set<int>> &courses_of_year, int n_time_slots) override;
    };
}

#endif //JIMP_EXERCISES_SCHEDULER_H
