cmake_minimum_required(VERSION 3.10)
project(LoggerProject VERSION 1.0 LANGUAGES CXX)

# Use C++17 for std::filesystem
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable multi-threading support
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

set(SOURCES
    Logger.cpp
    main.cpp
)


add_executable(Logger ${SOURCES})


target_link_libraries(Logger PRIVATE Threads::Threads)
