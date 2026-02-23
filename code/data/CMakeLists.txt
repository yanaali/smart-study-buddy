add_library(data_layer
    FileHandler.cpp
)
target_include_directories(data_layer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(data_layer PUBLIC core)
