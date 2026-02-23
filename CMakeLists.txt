add_executable(runTests
    test_TaskFactory.cpp
    test_SchedulerEngine.cpp
    test_FileHandler_Mock.cpp
)

target_link_libraries(runTests
    Qt6::Core
    Qt6::Widgets
    gtest
    gtest_main
    gmock
    core
    data_layer
)

include(GoogleTest)
gtest_discover_tests(runTests)
