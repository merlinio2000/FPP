cmake_minimum_required(VERSION 2.6)
project(fpp4)

add_executable(fpp4 main.cpp source/parser.cpp source/sl.cpp source/var.cpp source/variables.cpp)

install(TARGETS fpp4 RUNTIME DESTINATION bin)
