cmake_minimum_required(VERSION 3.10)
project(LicenseScanner)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(license-scanner src/main.cpp src/scanner.cpp src/logger.cpp)

# Enable multi-threading
find_package(Threads REQUIRED)
target_link_libraries(license-scanner Threads::Threads)
