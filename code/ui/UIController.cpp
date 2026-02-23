#include "UIController.h"

SchedulerEngine& UIController::engine() {
    return m_engine;
}

void UIController::addTask(TaskType type, const std::string& title, int minutes,
                           std::chrono::system_clock::time_point deadline) {
    m_engine.addTask(type, title, minutes, deadline);
}

void UIController::generate() {
    m_engine.recalcSchedule();
}
