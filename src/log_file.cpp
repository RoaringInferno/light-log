#include "light-log_bits/log_file.hpp"

#include <filesystem>

using namespace llog::_internal;

std::ofstream log_file::file = std::ofstream("light-log-unitialized.log");
std::string log_file::buffer = std::string();


void log_file::set(std::string_view text)
{
    if (log_file::buffer.empty())
    {
        clear();
        return;
    }
    log_file::buffer = text;
}

void log_file::push(std::string_view text)
{
    log_file::buffer += text;
    if (log_file::buffer.size() >= 1024) flush();
}

void log_file::flush()
{
    log_file::file << log_file::buffer;
    clear();
}

void log_file::clear() { log_file::buffer.clear(); }

log_file::log_file(std::string_view prefix, std::string_view log_dir, std::string_view extension)
{
    // Clear the log_file::buffer
    log_file::file << log_file::buffer;
    clear();

    // If the file is already open, close it
    if (log_file::file.is_open())
    {
        log_file::file.close();
    }

    std::string file_path;
    {
        date_time dt;
        file_path = std::string(log_dir) + std::string(prefix) + dt.mm_dd_yy('-') + "_" + dt.hh_mm_ss() + "." + std::string(extension);
    }

    // Ensure the directory
    std::filesystem::create_directories(log_dir);

    // Open the file
    log_file::file.open(file_path);
    if (!log_file::file.is_open())
    {
        throw std::runtime_error("Failed to open file: " + file_path);
    }
}

log_file &log_file::operator<<(std::string_view data)
{
    push(data);
    return *this;
}

log_file &log_file::operator<<(const char *data)
{
    push(data);
    return *this;
}

log_file &log_file::operator<<(char data)
{
    push(std::string(1, data));
    return *this;
}

log_file::~log_file() { log_file::file.close(); }