cmake_minimum_required(VERSION 3.12)

# Add Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


# Forward List Tests
add_executable(test_forward_list 
    test_forward_list.cpp
)
target_link_libraries(test_forward_list 
    gtest_main 
    gmock_main
)
target_include_directories(test_forward_list PRIVATE 
    ${CMAKE_SOURCE_DIR}/src
)
add_test(NAME ForwardListTest COMMAND test_forward_list)


# Dictionary Tests
add_executable(test_dictionary
    test_dictionary.cpp
)
target_link_libraries(test_dictionary
    gtest_main
    gmock_main
)
target_include_directories(test_dictionary PRIVATE 
    ${CMAKE_SOURCE_DIR}/src
)
add_test(NAME DictionaryTest COMMAND test_dictionary)
