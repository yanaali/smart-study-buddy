#pragma once
#include <string>
#include <chrono>
#include "SchedulerEngine.h"
#include "TaskTypes.h"

class UIController {
public:
    UIController() = default;
    SchedulerEngine& engine();
    void addTask(TaskType type, const std::string& title, int minutes,
                 std::chrono::system_clock::time_point deadline);
    void generate();

private:
    SchedulerEngine m_engine;
};
