#pragma once
#include <iostream>
#include <string>

class Logger {
public:
    enum Level {
        TRACE,      
        DEBUG,     
        INFO,      
        WARN,      
        ERROR,     
        FATAL      
    };

    static void log(Level level, const std::string& message) 
    {
        switch (level) {
        case TRACE: std::cout << "[TRACE]: "; break;
        case DEBUG: std::cout << "[DEBUG]: "; break;
        case INFO:  std::cout << "[INFO]: "; break;
        case WARN:  std::cout << "[WARN]: "; break;
        case ERROR: std::cout << "[ERROR]: "; break;
        case FATAL: std::cout << "[FATAL]: "; break;
        }

        std::cout << message << std::endl;
    }
};