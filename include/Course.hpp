#pragma once

#include <string>

// define a structure to hold course information
struct Course {
    std::string id;

    std::string title;

    std::vector<std::string> prereqs;
};
