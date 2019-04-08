cmake_minimum_required (VERSION 3.9)

project(Hello)

set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Wall")

find_package(OpenMP)

add_library(Hello
  hello.h
  hello.c
  greeting.c
  factorial.c
  hello_openmp.c)
target_compile_features(Hello PUBLIC c_std_99)

link_libraries(Hello)
add_executable(hello hello.c)
add_executable(hello_openmp hello_openmp.c)
target_link_libraries(hello_openmp OpenMP::OpenMP_C)
