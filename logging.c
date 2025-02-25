#include <stdio.h>
#include <assert.h>
#include <sys/time.h>
#include <time.h>
#include "logging.h"


static const char *logger_path = NULL;
static LoggerLevel logger_level = LOGGER_LEVEL_NULL;


static void log_message(const char *message,
                        const char *level)
{
    FILE *file = stdout;

    if (logger_path)
    {
        file = fopen(logger_path,
                     "a");
    }

    struct timeval tv;
    gettimeofday(&tv,
                 NULL);

    struct tm *tm_info;
    tm_info = localtime(&tv.tv_sec);

    fprintf(file,
            "[%02d:%02d:%02d.%03ld] %*s: %s\n",
            tm_info->tm_hour,
            tm_info->tm_min,
            tm_info->tm_sec,
            tv.tv_usec / 1000,
            5,
            level,
            message);

    if (logger_path)
    {
        fclose(file);
    }
}


void logger_init(const char *filepath,
                 const LoggerMode mode,
                 const LoggerLevel level)
{
    logger_path = filepath;
    logger_level = level;

    if (filepath &&
        mode == LOGGER_MODE_TRUNC)
    {
        FILE *f = fopen(logger_path,
                        "w");

        fclose(f);
    }
}


void logger_debug(const char *message)
{
    if (logger_level <= LOGGER_LEVEL_DEBUG)
    {
        log_message(message,
                    "DEBUG");
    }
}

void logger_info(const char *message)
{
    if (logger_level <= LOGGER_LEVEL_INFO)
    {
        log_message(message,
                    "INFO");
    }
}

void logger_warn(const char *message)
{
    if (logger_level <= LOGGER_LEVEL_WARN)
    {
        log_message(message,
                    "WARN");
    }
}

void logger_error(const char *message)
{
    if (logger_level <= LOGGER_LEVEL_ERROR)
    {
        log_message(message,
                    "ERROR");
    }
}

void logger_fatal(const char *message)
{
    if (logger_level <= LOGGER_LEVEL_FATAL)
    {
        log_message(message,
                    "FATAL");
    }
}