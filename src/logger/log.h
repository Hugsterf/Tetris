#pragma once
#include "logger.h"

#define LOG_TRACE(msg) Logger::log(Logger::TRACE, msg)
#define LOG_INFO(msg)  Logger::log(Logger::INFO, msg)
#define LOG_ERROR(msg) Logger::log(Logger::ERROR, msg)

inline void logInfo(const std::string& msg) 
{
    Logger::log(Logger::INFO, msg);
}