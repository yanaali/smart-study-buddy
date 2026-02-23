#include "SchedulerEngine.h"

void SchedulerEngine::addTask(TaskType type, const std::string& title, int durationMinutes,
                              std::chrono::system_clock::time_point deadline) {
    m_schedule.addTask(TaskFactory::create(type, title, durationMinutes, deadline));
}

void SchedulerEngine::recalcSchedule() {
    using TP = std::chrono::system_clock::time_point;
    using Min = std::chrono::minutes;

    auto& tasks = const_cast<std::vector<std::unique_ptr<Task>>&>(m_schedule.tasks());
    std::sort(tasks.begin(), tasks.end(), [](const auto& a, const auto& b){
        return a->deadline() < b->deadline();
    });

    m_schedule.clearSessions();
    TP cursor = std::chrono::system_clock::now();
    for (const auto& t : tasks) {
        TP start = cursor;
        TP end = start + Min(t->durationMinutes());
        m_schedule.addSession(StudySession(t->title(), start, end));
        cursor = end + Min(10);
    }
}
