//
// Created by kluch on 08.05.18.
//

#include <MovieSubtitles.h>

void
moviesubs::MicroDvdSubtitles::ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second, std::istream *in,
                                                  std::ostream *out) {
    int offset_in_frames = offset_in_micro_seconds * frame_per_second / 1000;
    std::string line, subs;
    int line_no = 0;
    while(std::getline(*in,line)) {
        line_no++;
        int line_length = line.size(), bracket_counter = 0, digit_counter = 0;
        bool in_brackets = false;
        for (int i = 0; i < line_length; i++) {
            if (line[i] == '{') {
                bracket_counter++;
                if (bracket_counter <= 2) {
                    while (line[i + digit_counter] != '}') {
                        digit_counter++;
                    }
                    std::string number = line.substr(i + 1, digit_counter - 1);
                    int number_int = std::stoi(number);
                    number_int += offset_in_frames;
                    if(number_int < 0) throw NegativeFrameAfterShift("asd",line_no);
                    number = std::to_string(number_int);
                    line.replace(i + 1, digit_counter - 1, number);
                    i = i + digit_counter - 1;
                    digit_counter = 0;
                    number.clear();
                }
            }
        }
        subs += line + "\n";
        line.clear();
    }
    *out << subs;
}

moviesubs::SubtitlesException::SubtitlesException(const std::string &__arg, int line_at) : invalid_argument(__arg) {
    line_at_ = line_at;
}

int moviesubs::SubtitlesException::LineAt() {
    return line_at_;
}

moviesubs::NegativeFrameAfterShift::NegativeFrameAfterShift(const std::string &__arg, int line_at) : SubtitlesException(__arg, line_at) {

}

moviesubs::SubtitleEndBeforeStart::SubtitleEndBeforeStart(const std::string &__arg, int line_at) : SubtitlesException(__arg, line_at) {

}

moviesubs::InvalidSubtitleLineFormat::InvalidSubtitleLineFormat(const std::string &__arg, int line_at) : SubtitlesException(__arg, line_at) {

}
