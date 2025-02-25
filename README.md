# C Logger

Simple logger functionality for C. 

## Features
- Multiple log levels: DEBUG, INFO, WARN, ERROR, FATAL
- Write to file or to stdout
- Logs messages to file in this format: ```[TIME] [LOG LEVEL]: MESSAGE```.

## Usage

### 1. Clone the repository

```bash
git clone https://github.com/belfastkeyboard/CLogger.git
```

### 2. Include the Header

```c
#include "logger.h"
```

### 3. Include the source file
CMake
```cmake
add_executable(CLogger main.c logging.c)
```
Bash
```bash
gcc -o CLogger main.c logging.c
```


### 4. Initialize the Logger (Optional)
The logger can be configured to log to a file or stdout.
By default, the logger will write to ```stdout``` and with a level of ```LOGGER_LEVEL_NULL``` which is all-inclusive.

To configure the logger settings call ```logger_init()```.
```c
void logger_init(const char *filepath, // NULL to write to stdout
                 LoggerMode mode,      // LOGGER_LEVEL_TRUNC to clear log file before writing
                 LoggerLevel level)    // Specify the minimum level to log e.g. LOGGER_LEVEL_ERROR will not write on a log_info() call
```

### 5. Log Messages
```c
logger_debug("This is a debug message.");
logger_info("This is an info message.");
logger_warn("This is a warning message.");
logger_error("This is an error message.");
logger_fatal("This is a fatal error message.");
```

Example output: ```[12:36:55.782]  INFO: This is an info message.```
