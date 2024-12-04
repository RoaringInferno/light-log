#pragma once

#include "date-time.hpp"

#include <string>
#include <string_view>
#include <fstream>

namespace llog::_internal
{
    class log_file
    {
    private:
        static std::ofstream file;
        static std::string buffer;
    public: // Static
        static void set(std::string_view text);
        static void push(std::string_view text);
        static void flush();
        static void clear();

        static void write() { flush(); };
    public:
        log_file& operator<<(std::string_view data);
        log_file& operator<<(const char* data);
        log_file& operator<<(char data);
    public:
        log_file(std::string_view prefix = "log_", std::string_view log_dir = "logs/", std::string_view extension = "log");
        ~log_file();
    };
} // namespace _internal