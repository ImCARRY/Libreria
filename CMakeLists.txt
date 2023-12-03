#@author JFK
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
# Serve per la RELEASE, fa funzionare il programma out-of-the-box
set(CMAKE_EXE_LINKER_FLAGS " -static")

add_executable(
    Books 
    src/main.cpp
    )
target_link_libraries(
    Books 
    ${PROJECT_NAME}
        -static-libgcc -static-libstdc++
    )

# TESTING
add_executable(
    book_test
    src/testing/book_test.cpp
    )
add_executable(
    library_test
    src/testing/library_prof_test.cpp
    )
add_executable(
        ce_test
        src/testing/cheatengine_test.cpp
)
target_link_libraries(book_test ${PROJECT_NAME})
target_link_libraries(library_test ${PROJECT_NAME})
target_link_libraries(ce_test ${PROJECT_NAME})
enable_testing()

add_test(
    NAME book_test
    COMMAND $<TARGET_FILE:book_test>
)
add_test(
    NAME library_test
    COMMAND $<TARGET_FILE:library_test>
)
add_test(
        NAME ce_test
        COMMAND $<TARGET_FILE:ce_test>
)

