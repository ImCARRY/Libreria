cmake_minimum_required(VERSION 3.20)

set(PROJECT_NAME Kindle)
project(${PROJECT_NAME} VERSION 1.0)
set(CMAKE_CXX_STANDARD 20)

set(SRC_FILES src/Book.cpp src/Date.cpp src/BookShelf.cpp)
set(HEADER_FILES include/Book.h include/Date.h include/BookShelf.h)
SET(GCC_COVERAGE_COMPILE_FLAGS "-Og")

add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})

include_directories(include src)

add_library(
    ${PROJECT_NAME}
    ${SRC_FILES} 
    ${HEADER_FILES}
)

add_executable(Books src/main.cpp)

target_link_libraries(Books ${PROJECT_NAME})
