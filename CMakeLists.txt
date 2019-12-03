cmake_minimum_required(VERSION 3.13)
project(NCursesConnectN.out)

set(CMAKE_C_STANDARD 11)
set(CURSES_USE_NCURSES TRUE)

find_package(Curses)

add_executable(NCursesConnectN.out main.c gamemaker.c gamemaker.h cursewindow.c cursewindow.h move.c move.h wincondition.c wincondition.h)

target_link_libraries(NCursesConnectN.out PRIVATE ${CURSES_LIBRARIES})

target_include_directories(NCursesConnectN.out PRIVATE ${CURSES_INCLUDE_DIRS})
