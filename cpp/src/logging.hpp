/*
    Copyright (C) 2022  Kalka

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as
    published by the Free Software Foundation, either version 3 of the
    License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <memory>


template<typename T>
inline void print(const T& t) { std::cout << t; }

template<typename T, typename... Args>
inline void print(const T& t, const Args&... args) { print(t); print(args...); }

template<typename... Args>
inline void println(const Args&... args) { print(args...); std::cout << std::endl; }

inline void println() { std::cout << std::endl; }

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