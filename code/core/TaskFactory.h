#pragma once
#include <memory>
#include <string>
#include <chrono>
#include "Task.h"
#include "TaskTypes.h"

class TaskFactory {
public:
    static std::unique_ptr<Task> create(TaskType type,
        const std::string& title,
        int durationMinutes,
        std::chrono::system_clock::time_point deadline);
};
