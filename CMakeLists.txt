cmake_minimum_required(VERSION 3.14)

project(calc_math LANGUAGES CXX)

add_library(calc_math INTERFACE)

target_include_directories(calc_math INTERFACE
	"${CMAKE_CURRENT_SOURCE_DIR}/include")

target_compile_features(calc_math INTERFACE cxx_std_17)
