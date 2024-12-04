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
        std::ofstream file;
        std::string buffer;
    public:
        void set_buffer(std::string_view new_buffer);
        void push_buffer(std::string_view new_buffer);
        void flush_buffer();
        void clear_buffer();

        void write() { flush_buffer(); };
    public:
        log_file& operator<<(std::string_view data);
        log_file& operator<<(const char* data);
        log_file& operator<<(char data);
    public:
        log_file(std::string_view prefix = "log_", std::string_view log_dir = "logs/", std::string_view extension = "log");
        ~log_file();
    };
} // namespace _internal