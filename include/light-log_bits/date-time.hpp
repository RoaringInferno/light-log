#pragma once

#include <string>

namespace llog::_internal
{
    class date
    {
    public:
        enum MONTH : unsigned char
        {
            JANUARY = 1,
            FEBRUARY,
            MARCH,
            APRIL,
            MAY,
            JUNE,
            JULY,
            AUGUST,
            SEPTEMBER,
            OCTOBER,
            NOVEMBER,
            DECEMBER
        };
    private:
        MONTH month;
        unsigned char day;
        /// @brief The year value.
        /// @details Positive = AD, Negative = BC.
        short year;
    private:
        static MONTH int_to_month(const unsigned char month);
    public:
        void reset();
        void set_month(const unsigned char month);
        void set_day(const unsigned char day);
        void set_year(const short year);
    public:
        std::string mm() const;
        std::string dd() const;
        std::string yyyy() const;
        std::string yy() const;
    public:
        std::string mm_dd_yyyy(const char separator = '/') const;
        std::string dd_mm_yyyy(const char separator = '/') const;
        std::string yyyy_mm_dd(const char separator = '/') const;
        std::string mm_dd_yy(const char separator = '/') const;
    public:
        date();
    };

    class time
    {
    private:
        unsigned char hour;
        unsigned char minute;
        unsigned char second;
    public:
        void reset();
        void set_hour(const unsigned char hour);
        void set_minute(const unsigned char minute);
        void set_second(const unsigned char second);
    public:
        std::string hh() const;
        std::string mm() const;
        std::string ss() const;
    public:
        std::string hh_mm_ss(const char separator = ':') const;
        std::string hh_mm(const char separator = ':') const;
        std::string mm_ss(const char separator = ':') const;
    public:
        time();
    };

    class date_time
    {
    private:
        date _date;
        time _time;
    public: // Date
        void reset_day();
        void set_hour(const unsigned char hour);
        void set_minute(const unsigned char minute);
        void set_second(const unsigned char second);

        std::string hh() const;
        std::string mmon() const;
        std::string ss() const;

        std::string hh_mm_ss(const char separator = ':') const;
        std::string hh_mm(const char separator = ':') const;
        std::string mm_ss(const char separator = ':') const;
    public: // Time
        void reset_time();
        void set_month(const unsigned char month);
        void set_day(const unsigned char day);
        void set_year(const short year);

        std::string mmin() const;
        std::string dd() const;
        std::string yyyy() const;
        std::string yy() const;

        std::string mm_dd_yyyy(const char separator = '/') const;
        std::string dd_mm_yyyy(const char separator = '/') const;
        std::string yyyy_mm_dd(const char separator = '/') const;
        std::string mm_dd_yy(const char separator = '/') const;
    public:
        void reset();
    public:
        date_time();
    };
} // namespace _internal