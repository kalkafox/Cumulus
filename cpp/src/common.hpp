#pragma once

#include <string>
#include <vector>
#include <map>
#include <set>
#include <memory>
#include <algorithm>
#include <functional>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cassert>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstdarg>
#include <cstddef>
#include <cstdint>
#include <cinttypes>
#include <climits>
#include <cfloat>
#include <limits>
#include <type_traits>
#include <utility>
#include <tuple>
#include <initializer_list>
#include <exception>
#include <stdexcept>
#include <new>
#include <typeinfo>
#include <typeindex>

// Don't worry, these will get removed later, just debugging includes for now

inline void print(const char* str) { std::cout << str; }
inline void print(const std::string& str) { std::cout << str; }
inline void print(const int& i) { std::cout << i; }
inline void print(const float& f) { std::cout << f; }
inline void print(const double& d) { std::cout << d; }
inline void print(const bool& b) { std::cout << b; }
inline void print(const char& c) { std::cout << c; }
inline void print(const void* ptr) { std::cout << ptr; }

template<typename T>
inline void print(const T& t) { std::cout << t; }

template<typename T, typename... Args>
inline void print(const T& t, const Args&... args) { print(t); print(args...); }

template<typename... Args>
inline void println(const Args&... args) { print(args...); std::cout << std::endl; }

template<typename T>
inline void print(const std::vector<T>& vec) {
    std::cout << "[";
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        print(*it);
        if (it != vec.end() - 1) std::cout << ", ";
    }
    std::cout << "]";
}

template<typename T>
inline void print(const std::set<T>& set) {
    std::cout << "{";
    for (auto it = set.begin(); it != set.end(); ++it) {
        print(*it);
        if (it != set.end() - 1) std::cout << ", ";
    }
    std::cout << "}";
}

template<typename T, typename U>
inline void print(const std::map<T, U>& map) {
    std::cout << "{";
    for (auto it = map.begin(); it != map.end(); ++it) {
        print(it->first);
        std::cout << ": ";
        print(it->second);
        if (it != map.end() - 1) std::cout << ", ";
    }
    std::cout << "}";
}

template<typename T>
inline void print(const std::shared_ptr<T>& ptr) {
    std::cout << ptr.get();
}

template<typename T>
inline void print(const std::unique_ptr<T>& ptr) {
    std::cout << ptr.get();
}

template<typename T>
inline void print(const std::weak_ptr<T>& ptr) {
    std::cout << ptr.lock().get();
}

template<typename T>
inline void print(const std::initializer_list<T>& list) {
    std::cout << "{";
    for (auto it = list.begin(); it != list.end(); ++it) {
        print(*it);
        if (it != list.end() - 1) std::cout << ", ";
    }
    std::cout << "}";
}

template<typename T>
inline void print(const std::tuple<T>& tuple) {
    std::cout << "(";
    print(std::get<0>(tuple));
    std::cout << ")";
}

template<typename T, typename U>
inline void print(const std::tuple<T, U>& tuple) {
    std::cout << "(";
    print(std::get<0>(tuple));
    std::cout << ", ";
    print(std::get<1>(tuple));
    std::cout << ")";
}

template<typename T, typename U, typename V>
inline void print(const std::tuple<T, U, V>& tuple) {
    std::cout << "(";
    print(std::get<0>(tuple));
    std::cout << ", ";
    print(std::get<1>(tuple));
    std::cout << ", ";
    print(std::get<2>(tuple));
    std::cout << ")";
}

template<typename T, typename U, typename V, typename W>
inline void print(const std::tuple<T, U, V, W>& tuple) {
    std::cout << "(";
    print(std::get<0>(tuple));
    std::cout << ", ";
    print(std::get<1>(tuple));
    std::cout << ", ";
    print(std::get<2>(tuple));
    std::cout << ", ";
    print(std::get<3>(tuple));
    std::cout << ")";
}