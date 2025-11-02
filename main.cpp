// SPDX-License-Identifier: MIT
/*
 * main.cpp
 * Copyright (C) 2025 Haider Bassem
 *
 * 11/2025  - Implements main program demonstrating Logger usage with multi-threading
 */


#include "Logger.h"
#include <thread>

int main() 
{
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
