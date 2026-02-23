# Smart Study Buddy

Smart Study Buddy is a lightweight desktop application that helps students manage their study sessions and tasks. It provides an adaptive scheduling engine that balances tasks based on due dates and estimated difficulty. Users can add different types of tasks (reading, exercises, projects, revision), and the system generates an optimized study schedule.

## Features

- **Adaptive scheduling engine:** Automatically prioritizes tasks based on due dates, duration, and weights.
- **Task management:** Create tasks with titles, descriptions, estimated duration, and due dates. Supports multiple task types via a simple factory pattern.
- **Session tracking:** Breaks tasks into study sessions with recommended start times and durations.
- **Simple user interface:** A Qt-based interface to view schedules, add tasks, and track progress.
- **Persistent storage:** Saves and loads task data from disk, so your schedule is always available.

## Architecture

The project follows a clean layered architecture with clear separation of responsibilities:

- **UI layer:** Handles the Qt user interface components in `code/ui`. `MainWindow` displays schedules and allows users to manage tasks. The `UIController` mediates between the UI and the core logic.
- **Core layer:** Contains domain logic in `code/core`. This includes models such as `Task`, `Schedule`, and `StudySession`, and services like the `SchedulerEngine` which generates schedules. A `TaskFactory` implements a factory pattern to create different task types and encapsulate their creation logic.
- **Data layer:** Provides persistence utilities in `code/data` such as a `FileHandler` that loads and saves tasks to disk.

The design rationale document outlines the motivation for this architecture and discusses the use of design patterns like Factory Method (for tasks), a builder-like pattern (for constructing schedules), and the facade pattern (through `SchedulerEngine`) to simplify complex scheduling logic.

## Building and Running

Smart Study Buddy is implemented in C++ and uses CMake to manage the build process.

```bash
# Generate build files
cmake -S . -B build

# Build the project
cmake --build build

# Run the application (replace with the correct binary if necessary)
./build/SmartStudyBuddy
```

The application depends on the Qt framework. Ensure Qt is installed and configured on your system before building.

## Tests

Unit tests are provided in the `tests` directory and use Google Test. To build and run the tests:

```bash
cmake -S . -B build -DBUILD_TESTS=ON
cmake --build build
./build/tests
```

---

Smart Study Buddy was developed as a personal project to experiment with Qt and software design principles. Feel free to fork and contribute!
