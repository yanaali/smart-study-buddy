#pragma once
#include <vector>
#include <memory>
#include "Task.h"
#include "StudySession.h"

class Schedule {
public:
    void addTask(std::unique_ptr<Task> t) { m_tasks.push_back(std::move(t)); }
    const std::vector<std::unique_ptr<Task>>& tasks() const { return m_tasks; }

    void addSession(const StudySession& s) { m_sessions.push_back(s); }
    const std::vector<StudySession>& sessions() const { return m_sessions; }

    void clearSessions() { m_sessions.clear(); }

private:
    std::vector<std::unique_ptr<Task>> m_tasks;
    std::vector<StudySession> m_sessions;
};
