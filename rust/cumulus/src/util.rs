use colored::Colorize;
use crate::logger;

pub fn attach_interrupt_handler(mut function: Option<fn()>) {

    if function.is_none() {
        function = Some(|| {
            println!();
            logger::info("Exiting...".red().bold().to_string().as_str());
            // Safely exit the program
            std::process::exit(0);
        });
    }

    ctrlc::set_handler(move || function.unwrap()()).expect("Error setting Ctrl-C handler");
}