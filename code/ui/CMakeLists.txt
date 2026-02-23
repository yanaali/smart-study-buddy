add_library(ui_layer
    MainWindow.cpp
    UIController.cpp
)
target_include_directories(ui_layer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(ui_layer PUBLIC Qt6::Widgets core)
