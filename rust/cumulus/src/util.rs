use colored::Colorize;
use crate::logger;
use std::io::Read;

pub fn attach_interrupt_handler(mut function: Option<fn()>) {

    if function.is_none() {
        function = Some(|| {
            // Check if stdin is empty. If it is, print a newline and exit
            if std::io::stdin().bytes().next().is_none() {
                logger::info("Exiting...".red().bold().to_string().as_str());
                // Safely exit the program
                std::process::exit(0);
            } else {
                // Clear the input buffer
                std::io::stdin().read_line(&mut String::new()).unwrap();
            }
        });
    }

    ctrlc::set_handler(move || function.unwrap()()).expect("Error setting Ctrl-C handler");
}