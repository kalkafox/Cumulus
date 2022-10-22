#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <memory>

void print(const char*);
void print(const std::string&);
void print(const int&);
void print(const float&);
void print(const double&);
void print(const bool&);

void println(const char*);
void println(const std::string&);
void println(const int&);
void println(const float&);
void println(const double&);
void println(const bool&);


template<typename T>
void print(const T&);

template<typename T, typename... Args>
void print(const T&, const Args&...);

template<typename... Args>
void println(const Args&...);

template<typename T>
void print(const std::vector<T>&);

template<typename T>
void print(const std::set<T>&);

template<typename T, typename U>
void print(const std::map<T, U>&);

template<typename T>
void print(const std::shared_ptr<T>&);

template<typename T>
void print(const std::weak_ptr<T>&);

template<typename T>
void print(const std::initializer_list<T>&);

template<typename T>
void print(const std::tuple<T>&);

template<typename T, typename U>
void print(const std::tuple<T, U>&);

template<typename T, typename U, typename V>
void print(const std::tuple<T, U, V>&);

template<typename T, typename U, typename V, typename W>
void print(const std::tuple<T, U, V, W>&);



namespace log {
    enum class Level {
        DEBUG,
        INFO,
        WARNING,
        ERROR,
        FATAL
    };

    std::ofstream log_file;

    void info(const char*);
    void info(const std::string&);

    void warn(const char*);
    void warn(const std::string&);

    void error(const char*);
    void error(const std::string&);

    void fatal(const char*);
    void fatal(const std::string&);

    void debug(const char*);
    void debug(const std::string&);

    void open_log_file(const char*);
    void close_log_file();
    void write_to_log_file(const char*);
}