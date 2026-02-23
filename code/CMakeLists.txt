cmake_minimum_required(VERSION 3.16)
project(SmartStudyBuddy LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_subdirectory(core)
add_subdirectory(ui)
add_subdirectory(data)
add_subdirectory(../tests tests)

add_executable(SmartStudyBuddy
    main.cpp
)

set_target_properties(SmartStudyBuddy PROPERTIES
    AUTOMOC ON
)

target_link_libraries(SmartStudyBuddy PRIVATE
    Qt6::Widgets
    core
    ui_layer
    data_layer
)
