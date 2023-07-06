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
pub mod logger;
pub mod util;

use console::{style, Color};

// Helper function for printing colored messages
pub fn print_colored_message(msg_type: &str, msg: &str, color: Color) {
    // Get the current time
    let now = chrono::Local::now();
    print!(
        "{}{}{} {} {}",
        style("[").bold(),
        style(now.format("%H:%M:%S")).fg(Color::Cyan).bold(),
        style("]").bold(),
        style(msg_type).fg(color).bold(),
        msg
    );
}

// colored info
// 
#[macro_export]
macro_rules! cinfo {
    ($($arg:tt)*) => {
        $crate::print_colored_message(" ", &format!($($arg)*), console::Color::Green);
    };
}

// colored info with newline
#[macro_export]
macro_rules! cinfoln {
    ($($arg:tt)*) => {
        $crate::cinfo!($($arg)*);
        println!();
    };
}

// colored warning
// 
#[macro_export]
macro_rules! cwarn {
    ($($arg:tt)*) => {
        $crate::print_colored_message(" ", &format!($($arg)*), console::Color::Yellow);
    };
}

// colored warning with newline
#[macro_export]
macro_rules! cwarnln {
    ($($arg:tt)*) => {
        $crate::cwarn!($($arg)*);
        println!();
    };
}

// colored error
// 
#[macro_export]
macro_rules! cerr {
    ($($arg:tt)*) => {
        $crate::print_colored_message(" ", &format!($($arg)*), console::Color::Red);
    };
}

// colored error with newline
#[macro_export]
macro_rules! cerrln {
    ($($arg:tt)*) => {
        $crate::cerr!($($arg)*);
        println!();
    };
}
