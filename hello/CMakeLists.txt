cmake_minimum_required (VERSION 3.9)

project(Hello)

# If using a pre-released version for development, uncomment:
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_FLAGS "-Wall")
# If using the released version, uncomment:
# set(CMAKE_BUILD_TYPE Release)

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
