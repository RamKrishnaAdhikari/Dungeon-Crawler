cmake_minimum_required(VERSION 3.5)

project(Praktikum_2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Praktikum_2 main.cpp
    character.h character.cpp
    tile.h tile.cpp
    level.h level.cpp
    abstractui.h abstractui.cpp
    dungeoncrawler.h dungeoncrawler.cpp
    floor.h floor.cpp
    wall.h wall.cpp
    portal.h portal.cpp
    terminalui.h terminalui.cpp
    input.h input.cpp)

include(GNUInstallDirs)
install(TARGETS Praktikum_2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
