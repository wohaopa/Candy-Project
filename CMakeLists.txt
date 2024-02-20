cmake_minimum_required(VERSION 3.27)
project(Candy)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(INSTALL_DIR ${CMAKE_BINARY_DIR}/install)

# 设置动态库的搜索路径，添加根目录
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR})

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        Network
        REQUIRED)

add_subdirectory(Share)
add_subdirectory(Components)
add_subdirectory(Launcher)