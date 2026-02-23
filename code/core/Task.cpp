#include "Task.h"

Task::Task(std::string title, TaskType type, int durationMinutes,
           std::chrono::system_clock::time_point deadline)
    : m_title(std::move(title)),
      m_type(type),
      m_duration(durationMinutes),
      m_deadline(deadline) {}
