#include "TaskFactory.h"

std::unique_ptr<Task> TaskFactory::create(
    TaskType type, const std::string& title, int durationMinutes,
    std::chrono::system_clock::time_point deadline)
{
    switch (type) {
        case TaskType::Assignment:
            return std::make_unique<AssignmentTask>(title, type, durationMinutes, deadline);
        case TaskType::Exam:
            return std::make_unique<ExamTask>(title, type, durationMinutes, deadline);
        case TaskType::Reading:
            return std::make_unique<ReadingTask>(title, type, durationMinutes, deadline);
        default:
            return nullptr;
    }
}
