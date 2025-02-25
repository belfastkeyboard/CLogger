#pragma once


typedef enum LoggerMode {
    LOGGER_MODE_TRUNC,
    LOGGER_MODE_APPEND
} LoggerMode;

typedef enum LoggerLevel {
    LOGGER_LEVEL_NULL = 0,
    LOGGER_LEVEL_DEBUG = 10,
    LOGGER_LEVEL_INFO = 20,
    LOGGER_LEVEL_WARN = 30,
    LOGGER_LEVEL_ERROR = 40,
    LOGGER_LEVEL_FATAL = 50,
} LoggerLevel;


void logger_init(const char *filepath,
                 LoggerMode mode,
                 LoggerLevel level);


void logger_debug(const char *message);

void logger_info(const char *message);

void logger_warn(const char *message);

void logger_error(const char *message);

void logger_fatal(const char *message);
