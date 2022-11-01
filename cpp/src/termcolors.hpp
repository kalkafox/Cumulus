#pragma once

#include <vector>
#include <iostream>

enum TermColor {
    RESET = 0,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    WHITE,
    BOLD_RED,
    BOLD_GREEN,
    BOLD_YELLOW,
    BOLD_BLUE,
    BOLD_MAGENTA,
    BOLD_CYAN,
    BOLD_WHITE
};

static const std::vector<const char*> TERM_COLORS = {
    "\033[0m", // reset
    "\033[1;31m", // red
    "\033[1;32m", // green
    "\033[1;33m", // yellow
    "\033[1;34m", // blue
    "\033[1;35m", // magenta
    "\033[1;36m", // cyan
    "\033[1;37m", // white
    // bold
    "\033[0;31m", // red
    "\033[0;32m", // green
    "\033[0;33m", // yellow
    "\033[0;34m", // blue
    "\033[0;35m", // magenta
    "\033[0;36m", // cyan
    "\033[0;37m", // white
};

namespace term_colors {
    basic_ostream<char>& red(basic_ostream<char>& os) {
        return os << flush << TERM_COLORS[RED];
    }

    basic_ostream<char>& green(basic_ostream<char>& os) {
        return os << flush << TERM_COLORS[GREEN];
    }

    basic_ostream<char>& yellow(basic_ostream<char>& os) {
        return os << flush << TERM_COLORS[YELLOW];
    }

    basic_ostream<char>& blue(basic_ostream<char>& os) {
        return os << flush << TERM_COLORS[BLUE];
    }

    basic_ostream<char>& magenta(basic_ostream<char>& os) {
        return os << flush << TERM_COLORS[MAGENTA];
    }

    basic_ostream<char>& cyan(basic_ostream<char>& os) {
        return os << flush << TERM_COLORS[CYAN];
    }

    basic_ostream<char>& white(basic_ostream<char>& os) {
        return os << flush << TERM_COLORS[WHITE];
    }

    basic_ostream<char>& reset(basic_ostream<char>& os) {
        return os << flush << TERM_COLORS[RESET];
    }

    basic_ostream<char>& bold_red(basic_ostream<char>& os) {
        return os << flush << TERM_COLORS[BOLD_RED];
    }

    basic_ostream<char>& bold_green(basic_ostream<char>& os) {
        return os << flush << TERM_COLORS[BOLD_GREEN];
    }

    basic_ostream<char>& bold_yellow(basic_ostream<char>& os) {
        return os << flush << TERM_COLORS[BOLD_YELLOW];
    }

    basic_ostream<char>& bold_blue(basic_ostream<char>& os) {
        return os << flush << TERM_COLORS[BOLD_BLUE];
    }

    basic_ostream<char>& bold_magenta(basic_ostream<char>& os) {
        return os << flush << TERM_COLORS[BOLD_MAGENTA];
    }

    basic_ostream<char>& bold_cyan(basic_ostream<char>& os) {
        return os << flush << TERM_COLORS[BOLD_CYAN];
    }

    basic_ostream<char>& bold_white(basic_ostream<char>& os) {
        return os << flush << TERM_COLORS[BOLD_WHITE];
    }
}