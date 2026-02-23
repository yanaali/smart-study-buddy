#pragma once
#include <string>
#include <chrono>
#include "TaskTypes.h"

class Task {
public:
    Task(std::string title, TaskType type, int durationMinutes,
         std::chrono::system_clock::time_point deadline);

    virtual ~Task() = default;

    const std::string& title() const { return m_title; }
    TaskType type() const { return m_type; }
    int durationMinutes() const { return m_duration; }
    std::chrono::system_clock::time_point deadline() const { return m_deadline; }
    TaskStatus status() const { return m_status; }

    void markComplete() { m_status = TaskStatus::Completed; }

protected:
    std::string m_title;
    TaskType m_type;
    int m_duration; // minutes
    std::chrono::system_clock::time_point m_deadline;
    TaskStatus m_status{TaskStatus::Pending};
};

// Specialized tasks (for Factory demo)
struct AssignmentTask : public Task {
    using Task::Task;
};
struct ExamTask : public Task {
    using Task::Task;
};
struct ReadingTask : public Task {
    using Task::Task;
};
