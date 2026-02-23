#pragma once
#include <chrono>
#include <string>

class StudySession {
public:
    StudySession(std::string taskTitle,
                 std::chrono::system_clock::time_point start,
                 std::chrono::system_clock::time_point end)
        : m_taskTitle(std::move(taskTitle)), m_start(start), m_end(end) {}

    const std::string& taskTitle() const { return m_taskTitle; }
    std::chrono::system_clock::time_point start() const { return m_start; }
    std::chrono::system_clock::time_point end() const { return m_end; }

private:
    std::string m_taskTitle;
    std::chrono::system_clock::time_point m_start;
    std::chrono::system_clock::time_point m_end;
};
