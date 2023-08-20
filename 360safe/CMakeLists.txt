cmake_minimum_required(VERSION 3.10)

set(PROJECT "360safe")
project(${PROJECT})

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 COMPONENTS Core Gui Widgets Network)

qt_add_resources(QRC_FILES Resources/360safe.qrc)

file(GLOB HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
file(GLOB SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_executable(${PROJECT} ${HEADER_FILES} ${SOURCE_FILES} ${QRC_FILES})

target_link_libraries(${PROJECT} PRIVATE Qt::Core Qt::Gui Qt::Widgets Qt::Network)
