cmake_minimum_required(VERSION 3.14)
project(testing_test)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp)
add_executable(DateConverter_run ${SOURCE_FILES})

include_directories(Sidel)
add_subdirectory(Sidel)

target_link_libraries(DateConverter_run Sidel)

add_subdirectory(Google_tests)

