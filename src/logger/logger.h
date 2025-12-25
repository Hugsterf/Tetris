#pragma once
#include <iostream>
#include <string>

class Logger {
public:
    enum Level {
        TRACE,      
        INFO,        
        ERROR     
    };

    static void log(Level level, const std::string& message) 
    {
        switch (level) {
        case TRACE: std::cout << "[TRACE]: "; break;
        case INFO:  std::cout << "[INFO]: "; break;
        case ERROR: std::cout << "[ERROR]: "; break;
        }

        std::cout << message << std::endl;
    }
};