cmake_minimum_required(VERSION 3.16)
project(chess)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(chess
    chess.cpp
)

target_link_libraries(chess PRIVATE
    Qt6::Widgets
)