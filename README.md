# Logging-system
Logger class written with C++ to be simple and efficient to logging errors, warning, debug and info.


A high-performance, thread-safe, asynchronous logging system designed for real-world C++ projects.  

## Overview

This Logger is a **singleton** utility that provides a centralized way to log messages from anywhere in your application.  
It is designed to **minimize overhead**, **preserve the order of log messages**, and **prevent blocking your main threads**.  

The system handles:

- Timestamped log messages  
- Multiple log levels: `DEBUG`, `INFO`, `WARNING`, `ERROR`  
- Color-coded console output for clarity  
- Safe file logging with automatic ANSI code stripping  
- Asynchronous queue processing via a background thread  

> The Logger ensures your application remains responsive, even under high-frequency logging.

## Why Use This Logger

1. **Thread-Safe:** Multiple threads can log simultaneously without corruption or race conditions.  
2. **Asynchronous:** Logging does not block your main logic.  
3. **Centralized:** No need to manage multiple log files or log objects.  
4. **Structured:** Automatic timestamps and log levels make debugging and analysis easier.  
5. **Cross-Platform:** Works consistently across Linux, Windows, and macOS.  

## Usage

### 1. Include the Logger

```cpp
#include "Logger.h"

```
## Access the singleton instance

```cpp

auto& logger = Logger::instance(); // Only one instance exists in the program

```

## Log messages

```cpp

logger.debug("Debugging message");
logger.info("Informational message");
logger.warning("Potential issue detected");
logger.error("Critical error occurred");

```
- All messages are timestamped automatically.

- Console output is color-coded for readability.

- Messages are queued and written asynchronously to the log file.

## File Logging

- The Logger writes all messages to imgorg.log (or a custom filename if specified).

- ANSI color codes are stripped from file output for clean logs.

```cpp

Logger::instance("my_app.log").info("Custom log file in use");

```

## Example

```cpp

#include "Logger.h"
#include <thread>

int main() {
    Logger::instance().info("Application started");

    std::thread t1([](){
        Logger::instance().debug("Thread 1 running");
    });

    std::thread t2([](){
        Logger::instance().warning("Thread 2 warning");
    });

    t1.join();
    t2.join();

    Logger::instance().error("Application terminating with error");

    return 0;
}

```

## Notes

- No manual initialization is required; the singleton handles setup automatically.

- The logger automatically flushes remaining messages on application exit.

- Designed for performance-critical applications where logging should never block or corrupt threads.
