#pragma once
#include <string>
#include "Schedule.h"

class FileHandler {
public:
    // Stubs for D2; implement in D3
    bool save(const Schedule&, const std::string&) { return false; }
    bool load(Schedule&, const std::string&) { return false; }
};
