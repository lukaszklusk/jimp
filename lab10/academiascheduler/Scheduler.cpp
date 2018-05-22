//
// Created by kluch on 22.05.18.
//

#include <map>
#include "Scheduler.h"

academia::SchedulingItem::SchedulingItem(int course_id, int teacher_id, int room_id, int time_slot, int year) {
    course_id_ = course_id;
    teacher_id_ = teacher_id;
    room_id_ = room_id;
    time_slot_ = time_slot;
    year_ = year;
}

academia::SchedulingItem::SchedulingItem() {
}

academia::Schedule academia::Schedule::OfTeacher(int teacher_id) const {
    Schedule result;
    std::copy_if(scheduled_.begin(),scheduled_.end(),std::back_inserter(result.scheduled_),[teacher_id](const SchedulingItem &tmp){return teacher_id == tmp.TeacherId();});
    return result;
}

void academia::Schedule::InsertScheduleItem(const academia::SchedulingItem &it) {
    scheduled_.emplace_back(it);
}


academia::Schedule academia::Schedule::OfRoom(int room_id) const {
    Schedule result;
    std::copy_if(scheduled_.begin(),scheduled_.end(),std::back_inserter(result.scheduled_),[room_id](const SchedulingItem &tmp){return room_id == tmp.RoomId();});
    return result;
}

academia::Schedule academia::Schedule::OfYear(int year) const {
    Schedule result;
    std::copy_if(scheduled_.begin(),scheduled_.end(),std::back_inserter(result.scheduled_),[year](const SchedulingItem &tmp){return year == tmp.Year();});
    return result;
}

std::vector<int> academia::Schedule::AvailableTimeSlots(int n_time_slots) const {
    std::vector<int> result;
    std::vector<int> time_slot_cp;
    for(auto &tmp: scheduled_) time_slot_cp.emplace_back(tmp.TimeSlot());
    for(int i=1;i<=n_time_slots;i++){
        if(std::find(time_slot_cp.begin(),time_slot_cp.end(),i) == time_slot_cp.end())result.emplace_back(i);
    }
    return result;
}

size_t academia::Schedule::Size() const {
    return size_t(scheduled_.size());
}

const academia::SchedulingItem &academia::Schedule::operator[](int num) const {
    return scheduled_[num];
}

academia::Schedule::Schedule() {

}

academia::Schedule academia::GreedyScheduler::PrepareNewSchedule(const std::vector<int> &rooms,
                                                                 const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                                                 const std::map<int, std::set<int>> &courses_of_year,
                                                                 int n_time_slots) {
    Schedule result;
    int num = 0;
    for(const auto &tmp1: teacher_courses_assignment){
        if(n_time_slots <= tmp1.second.size()) throw NoViableSolutionFound();
        for(const auto &tmp2: tmp1.second){
            for(const auto &year: courses_of_year){
                if(n_time_slots <= year.second.size()) throw NoViableSolutionFound();
                for(const auto &year_course: year.second){
                    if(tmp2 == year_course){
                        auto tmp3 =  SchedulingItem{tmp2, tmp1.first, rooms[num], num, year.first};
                        result.InsertScheduleItem(tmp3);
                        num++;
                    }
                }
            }
        }
    }
    return result;
}
