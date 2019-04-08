cmake_minimum_required (VERSION 3.9)

project(Hello)

set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Wall")

find_package(OpenMP)

add_library(hello
  hello.h
  hello.c
  greeting.c
  factorial.c
  hello_openmp.c)
target_compile_features(hello PUBLIC c_std_99)

link_libraries(hello)
add_executable(hello hello.c)
add_executable(hello_openmp hello_openmp.c)
