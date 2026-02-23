#pragma once
#include <algorithm>
#include <chrono>
#include <vector>
#include <memory>
#include "Schedule.h"
#include "TaskFactory.h"

class SchedulerEngine {
public:
    Schedule& schedule() { return m_schedule; }

    void addTask(TaskType type, const std::string& title, int durationMinutes,
                 std::chrono::system_clock::time_point deadline);

    void recalcSchedule();

private:
    Schedule m_schedule;
};
