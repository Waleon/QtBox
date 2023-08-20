cmake_minimum_required(VERSION 3.10)

set(PROJECT "360safe")
project(${PROJECT})

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 COMPONENTS Core Gui Widgets Network LinguistTools)

set(TsFiles ${CMAKE_CURRENT_SOURCE_DIR}/Resources/360safe_en.ts ${CMAKE_CURRENT_SOURCE_DIR}/Resources/360safe_zh.ts)

qt_add_resources(QRC_FILES Resources/360safe.qrc)

file(GLOB HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
file(GLOB SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_executable(${PROJECT} ${HEADER_FILES} ${SOURCE_FILES} ${QRC_FILES} ${TsFiles})

set_source_files_properties(${TsFiles}
    PROPERTIES OUTPUT_LOCATION "${CMAKE_CURRENT_BINARY_DIR}/translations")

qt_add_lupdate(${PROJECT} TS_FILES ${TsFiles})

qt_add_lrelease(${PROJECT}
    TS_FILES ${TsFiles}
    QM_FILES_OUTPUT_VARIABLE qm_files)

qt_add_resources(${PROJECT} "translations"
    PREFIX "/"
    BASE "${CMAKE_CURRENT_BINARY_DIR}"
    FILES "${qm_files}")

target_link_libraries(${PROJECT} PRIVATE Qt::Core Qt::Gui Qt::Widgets Qt::Network)
