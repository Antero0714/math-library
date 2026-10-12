cmake_minimum_required(VERSION 3.14)
project(calc_math LANGUAGES CXX)

add_library(calc_math INTERFACE)

target_include_directories(calc_math INTERFACE
	"${CMAKE_CURRENT_SOURCE_DIR}/include")

target_compile_features(calc_math INTERFACE cxx_std_17)

find_program(CLANG_FORMAT_EXECUTABLE NAMES clang-format)

if(NOT CLANG_FORMAT_EXECUTABLE)
    message(FATAL_ERROR "clang-format was not found")
endif()

add_custom_target(format_math ALL
    COMMAND "${CLANG_FORMAT_EXECUTABLE}" -i
        "${CMAKE_CURRENT_SOURCE_DIR}/include/calc_math/math.h"
    VERBATIM
)

add_dependencies(calc_math format_math)
