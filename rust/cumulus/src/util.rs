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

use crate::cinfoln;

pub fn attach_interrupt_handler(mut function: Option<fn()>) {
    if function.is_none() {
        function = Some(|| {
            cinfoln!("Ctrl-C pressed, exiting...");
            // Safely exit the program
            std::process::exit(0);
        });
    }

    ctrlc::set_handler(move || function.unwrap()()).expect("Error setting Ctrl-C handler");
}
