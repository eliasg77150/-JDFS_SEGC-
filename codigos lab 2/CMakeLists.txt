cmake_minimum_required(VERSION 3.10)
project(TareaCorte2 CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(design_twitter twitter.cpp)
add_executable(design_spreadsheet spreadsheet.cpp)
add_executable(robot_simulator robot_simulator.cpp)
add_executable(queen_attack queen_attack.cpp)
