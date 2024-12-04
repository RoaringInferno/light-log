#include "light-log_bits/log_file.hpp"

#include <filesystem>

using namespace llog::_internal;


void log_file::set_buffer(std::string_view new_buffer)
{
    if (this->buffer.empty())
    {
        this->clear_buffer();
        return;
    }
    this->buffer = new_buffer;
}

void log_file::push_buffer(std::string_view new_buffer)
{
    this->buffer += new_buffer;
    if (this->buffer.size() >= 1024) this->flush_buffer();
}

void log_file::flush_buffer()
{
    this->file << this->buffer;
    this->clear_buffer();
}

void log_file::clear_buffer() { this->buffer.clear(); }

log_file::log_file(std::string_view prefix, std::string_view log_dir, std::string_view extension)
    : file(), buffer()
{
    std::string file_path;
    {
        date_time dt;
        file_path = std::string(log_dir) + std::string(prefix) + dt.mm_dd_yy('-') + "_" + dt.hh_mm_ss() + "." + std::string(extension);
    }

    // Ensure the directory
    std::filesystem::create_directories(log_dir);

    // Open the file
    this->file.open(file_path);
    if (!this->file.is_open())
    {
        throw std::runtime_error("Failed to open file: " + file_path);
    }
}

log_file &log_file::operator<<(std::string_view data)
{
    this->push_buffer(data);
    return *this;
}

log_file &log_file::operator<<(const char *data)
{
    this->push_buffer(data);
    return *this;
}

log_file &log_file::operator<<(char data)
{
    this->push_buffer(std::string(1, data));
    return *this;
}

log_file::~log_file() { this->file.close(); }