#include "light-log_bits/date-time.hpp"

#include <ctime>

using namespace llog::_internal;

// ================================================== Date ==================================================

date::MONTH date::int_to_month(const unsigned char month)
{
    switch (month)
    {
    case 1: return MONTH::JANUARY;
    case 2: return MONTH::FEBRUARY;
    case 3: return MONTH::MARCH;
    case 4: return MONTH::APRIL;
    case 5: return MONTH::MAY;
    case 6: return MONTH::JUNE;
    case 7: return MONTH::JULY;
    case 8: return MONTH::AUGUST;
    case 9: return MONTH::SEPTEMBER;
    case 10: return MONTH::OCTOBER;
    case 11: return MONTH::NOVEMBER;
    case 12: return MONTH::DECEMBER;
    default: throw std::invalid_argument("Invalid month passed to date::int_to_month: " + std::to_string(month));
    }
}

void date::reset()
{
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
    this->year = now->tm_year + 1900;
    this->month = this->int_to_month(now->tm_mon + 1);
    this->day = now->tm_mday;
}

void date::set_month(const unsigned char month) { this->month = this->int_to_month(month); }
void date::set_day(const unsigned char day) { this->day = day; }
void date::set_year(const short year) { this->year = year; }

std::string date::mm() const
{
    std::string month_str = std::to_string(static_cast<unsigned char>(this->month));
    if (month_str.size() == 1) { month_str = "0" + month_str; }
    return month_str;
}

std::string date::dd() const
{
    std::string day_str = std::to_string(this->day);
    if (day_str.size() == 1) { day_str = "0" + day_str; }
    return day_str;
}

std::string date::yyyy() const
{
    std::string year_str = std::to_string(this->year);
    if (year_str.size() == 1) { year_str = "000" + year_str; }
    else if (year_str.size() == 2) { year_str = "00" + year_str; }
    else if (year_str.size() == 3) { year_str = "0" + year_str; }
    return year_str;
}

std::string date::yy() const
{
    std::string year_str = std::to_string(this->year);
    if (year_str.size() == 1) { year_str = "0" + year_str; }
    return year_str;
}

std::string date::mm_dd_yyyy(const char separator) const { return this->mm() + separator + this->dd() + separator + this->yyyy(); }
std::string date::dd_mm_yyyy(const char separator) const { return this->dd() + separator + this->mm() + separator + this->yyyy(); }
std::string date::yyyy_mm_dd(const char separator) const { return this->yyyy() + separator + this->mm() + separator + this->dd(); }
std::string date::mm_dd_yy(const char separator) const { return this->mm() + separator + this->dd() + separator + this->yy(); }

date::date() { this->reset(); }


// ================================================== Time ==================================================

void time::reset()
{
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
    this->hour = now->tm_hour;
    this->minute = now->tm_min;
    this->second = now->tm_sec;
}

void time::set_hour(const unsigned char hour) { this->hour = hour; }
void time::set_minute(const unsigned char minute) { this->minute = minute; }
void time::set_second(const unsigned char second) { this->second = second; }

std::string time::hh() const { std::string hour_string = std::to_string(this->hour); if (hour_string.size() == 1) hour_string = "0" + hour_string; return hour_string; }
std::string time::mm() const { std::string minute_string = std::to_string(this->minute); if (minute_string.size() == 1) minute_string = "0" + minute_string; return minute_string; }
std::string time::ss() const { std::string second_string = std::to_string(this->second); if (second_string.size() == 1) second_string = "0" + second_string; return second_string; }
std::string time::hh_mm_ss(const char separator) const { return this->hh() + separator + this->mm() + separator + this->ss(); }
std::string time::hh_mm(const char separator) const { return this->hh() + separator + this->mm(); }
std::string time::mm_ss(const char separator) const { return this->mm() + separator + this->ss(); }
time::time() { this->reset(); }


// ================================================== Date Time(Date) ==================================================
void date_time::reset_time(){ this->_date.reset(); }
void date_time::set_month(const unsigned char month){ this->_date.set_month(month); }
void date_time::set_day(const unsigned char day){ this->_date.set_day(day); }
void date_time::set_year(const short year){ this->_date.set_year(year); }

std::string date_time::mmon() const { return this->_date.mm(); };
std::string date_time::dd() const { return this->_date.dd(); };
std::string date_time::yyyy() const { return this->_date.yyyy(); };
std::string date_time::yy() const { return this->_date.yy(); };

std::string date_time::mm_dd_yyyy(const char separator) const { return this->_date.mm_dd_yyyy(separator); };
std::string date_time::dd_mm_yyyy(const char separator) const { return this->_date.dd_mm_yyyy(separator); };
std::string date_time::yyyy_mm_dd(const char separator) const { return this->_date.yyyy_mm_dd(separator); };
std::string date_time::mm_dd_yy(const char separator) const { return this->_date.mm_dd_yy(separator); }

// ================================================== Date Time(Time) ==================================================
void date_time::reset_day() { this->_time.reset(); };
void date_time::set_hour(const unsigned char hour) { this->_time.set_hour(hour); };
void date_time::set_minute(const unsigned char minute) { this->_time.set_minute(minute); };
void date_time::set_second(const unsigned char second) { this->_time.set_second(second); };

std::string date_time::hh() const { return this->_time.hh(); };
std::string date_time::mmin() const { return this->_time.mm(); };
std::string date_time::ss() const { return this->_time.ss(); };

std::string date_time::hh_mm_ss(const char separator) const { return this->_time.hh_mm_ss(separator); };
std::string date_time::hh_mm(const char separator) const { return this->_time.hh_mm(separator); };
std::string date_time::mm_ss(const char separator) const { return this->_time.mm_ss(separator); };

// ================================================== Date Time ==================================================
void date_time::reset()
{
    this->_date.reset();
    this->_time.reset();
}
date_time::date_time()
{
    this->reset();
};