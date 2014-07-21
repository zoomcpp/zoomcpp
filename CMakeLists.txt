cmake_minimum_required(VERSION 2.8.11)

add_executable(editor main.cpp status_bar.cpp)
target_link_libraries(editor ncurses)
