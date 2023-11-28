cmake_minimum_required(VERSION 3.26)
project(Ejercicio_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(integrador main.cpp json11.cpp json11.hpp)
add_executable(mensaje mensaje.cpp)

