add_library(core
    Task.cpp
    TaskFactory.cpp
    Schedule.cpp
    StudySession.cpp
    SchedulerEngine.cpp
)
target_include_directories(core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
