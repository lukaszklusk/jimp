//
// Created by kluch on 08.05.18.
//

#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H

#include <iostream>
#include <string>
#include <stdexcept>

namespace moviesubs{
    class MovieSubs{
    public:
        virtual void ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second, std::istream *in, std::ostream *out) =0;
        ~MovieSubs() = default;
    };
    class MicroDvdSubtitles: public MovieSubs {
    public:
        virtual void ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second, std::istream *in, std::ostream *out) override;
    };
    class SubtitlesException : public std::invalid_argument{
    public:
        SubtitlesException(const std::string &__arg, int line_at);
        int LineAt();
    private:
        int line_at_;
    };
    class NegativeFrameAfterShift : public SubtitlesException {
    public:
        NegativeFrameAfterShift(const std::string &__arg, int line_at);
    };
    class SubtitleEndBeforeStart : public SubtitlesException{
    public:
        SubtitleEndBeforeStart(const std::string &__arg, int line_at);
    };
    class InvalidSubtitleLineFormat : public SubtitlesException{
    public:
        InvalidSubtitleLineFormat(const std::string &__arg, int line_at);
    };
}

#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
