use std::fs::{File, OpenOptions};
use std::io::Write;
use ansi_term::Colour::*;
use directories::ProjectDirs;

static mut LOG_FILE: Option<File> = None;
static mut OUTPUT_PATH: String = String::new();

fn open_file(output_path: &str) -> std::io::Result<File> {
    // Recursively create the directory if it does not exist except for the last part
    let output_path = std::path::Path::new(output_path);
    let output_dir = output_path.parent().unwrap();
    std::fs::create_dir_all(output_dir)?;
    // Open the file
    let file = OpenOptions::new()
        .write(true)
        .create(true)
        .append(true)
        .open(output_path)?;
    Ok(file)
}

pub fn open_log_file_for_saving(custom_path: Option<&str>) -> std::io::Result<()> {
    unsafe {
        if custom_path.is_some() {
            OUTPUT_PATH = custom_path.unwrap().to_string();
        } else {
            // Get project name from Cargo.toml
            let project_name = env!("CARGO_PKG_NAME");
            // Get project directories
            let project_dirs = ProjectDirs::from("com", "Rust", project_name).unwrap();


            let output_path = format!(
                "{}/output-{}.log",
                project_dirs.data_dir().to_str().unwrap(),
                chrono::Local::now().format("%m-%d-%Y").to_string()
            );
            println!("Output path: {}", output_path);
            OUTPUT_PATH = project_dirs.data_local_dir().to_str().unwrap().to_string();
            let log_file = open_file(output_path.as_str());
            if log_file.is_ok() {
                LOG_FILE = Some(log_file.unwrap());
            } else {
                error(format!("Could not open log file for saving: {}", log_file.unwrap_err()).as_str());
            }
        }
    }
    Ok(())
}

fn write_to_log_file(message: &str) {
    unsafe {
        if let Some(log_file) = &mut LOG_FILE {
            // Open "output-mm-dd-yyyy.log" in the default output path
            // Filter out ANSI color codes
            const ANSI_COLOR_CODES: [&str; 8] = [
                "\x1b[0m",
                "\x1b[31m",
                "\x1b[32m",
                "\x1b[33m",
                "\x1b[34m",
                "\x1b[35m",
                "\x1b[36m",
                "\x1b[37m",
            ];

            let mut message = message.to_string();

            for color_code in ANSI_COLOR_CODES.iter() {
                message = message.replace(color_code, "");
            }

            log_file.write_all(message.as_bytes()).unwrap();
        }
    }
}

pub fn timestamp(colored: bool) -> String {
    let now = chrono::Local::now();
    // fmt for milliseconds is %3f
    let timestamp = now.format("%Y-%m-%d %H:%M:%S.%3f").to_string();
    if colored {
        return format!("[{}]", Green.paint(timestamp));
    }
    format!("[{}]", timestamp)
}

pub fn info(message: &str) {
    println!(
        "{} {} {}",
        timestamp(true),
        format!("[{}]", Green.paint("INFO")),
        message
    );
    write_to_log_file(&format!("{} [INFO] {}\r\n", timestamp(false), message));
}

pub fn warn(message: &str) {
    println!(
        "{} {} {}",
        timestamp(true),
        format!("[{}]", Yellow.paint("WARN")),
        message
    );
    write_to_log_file(&format!("{} [WARN] {}\r\n", timestamp(false), message));
}

pub fn error(message: &str) {
    println!(
        "{} {} {}",
        timestamp(true),
        format!("[{}]", Red.paint("ERROR")),
        message
    );
    write_to_log_file(&format!("{} [ERROR] {}\r\n", timestamp(false), message));
}

pub fn debug(message: &str) {
    println!(
        "{} {} {}",
        timestamp(true),
        format!("[{}]", Blue.paint("DEBUG")),
        message
    );
    write_to_log_file(&format!("{} [DEBUG] {}\r\n", timestamp(false), message));
}

pub fn trace(message: &str) {
    println!(
        "{} {} {}",
        timestamp(true),
        format!("[{}]", Purple.paint("TRACE")),
        message
    );
    write_to_log_file(&format!("{} [TRACE] {}\r\n", timestamp(false), message));
}

pub fn fatal(message: &str) {
    println!(
        "{} {} {}",
        timestamp(true),
        format!("[{}]", Red.paint("FATAL")),
        message
    );
    write_to_log_file(&format!("{} [FATAL] {}\r\n", timestamp(false), message));
}
