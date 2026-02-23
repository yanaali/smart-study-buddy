#pragma once
#include <string>

enum class TaskType { Assignment, Exam, Reading };
enum class TaskStatus { Pending, Completed };

inline std::string to_string(TaskType t) {
    switch (t) {
        case TaskType::Assignment: return "Assignment";
        case TaskType::Exam:       return "Exam";
        case TaskType::Reading:    return "Reading";
    }
    return "Unknown";
}
