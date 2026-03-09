cmake_minimum_required(VERSION 3.16)
project(CppInterviewExercise LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(CTest)
enable_testing()

add_library(price_calculator
    src/PriceCalculator.cpp
)

target_include_directories(price_calculator
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(price_calculator_tests
    tests/PriceCalculatorTests.cpp
)

target_include_directories(price_calculator_tests
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/tests
)

target_link_libraries(price_calculator_tests
    PRIVATE
        price_calculator
)

find_package(GTest CONFIG QUIET)

if (NOT GTest_FOUND)
    message(FATAL_ERROR
        "GTest was not found. Install a system GTest package before building.")
endif()

if (TARGET GTest::gtest_main)
    target_link_libraries(price_calculator_tests PRIVATE GTest::gtest_main)
else()
    target_link_libraries(price_calculator_tests PRIVATE gtest_main)
endif()

include(GoogleTest)
gtest_discover_tests(price_calculator_tests)
