cmake_minimum_required(VERSION 3.5)

project(praktikum2finalcode LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(praktikum2finalcode main.cpp
    character.h character.cpp
    tile.h tile.cpp
    level.h level.cpp
    floor.h floor.cpp
    wall.h wall.cpp
    portal.h portal.cpp
    abstractview.h abstractview.cpp
    terminalui.h terminalui.cpp
    input.h input.cpp
    dungeoncrawler.h dungeoncrawler.cpp
      active.h active.cpp
  passive.h passive.cpp

   door.h door.cpp
   switch.h switch.cpp
   abstractcontroller.h abstractcontroller.cpp
   pit.h pit.cpp
   ramp.h ramp.cpp)

include(GNUInstallDirs)
install(TARGETS praktikum2finalcode
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
