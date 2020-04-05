cmake_minimum_required(VERSION 3.16)

project(gtkmmfun)

set(SRC main.cpp
        logic.cpp
        controller.cpp
        gui.cpp)

find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-3.0) # defines GTKMM_INCLUDE_DIRS, GTKMM_LIBRARY_DIRS and GTKMM_LIBRARIES 

find_package(Threads REQUIRED)

link_directories(${GTKMM_LIBRARY_DIRS})
include_directories(${GTKMM_INCLUDE_DIRS})
add_executable(${PROJECT_NAME} ${SRC})
target_link_libraries(${PROJECT_NAME} ${GTKMM_LIBRARIES} Threads::Threads)