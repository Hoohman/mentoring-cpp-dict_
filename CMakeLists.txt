cmake_minimum_required(VERSION 3.12)
project(DictionaryManagementSystem CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(dictionary_app 
    src/main.cpp
)

target_include_directories(dictionary_app PRIVATE src)

# Enable testing
enable_testing()
add_subdirectory(tests)
