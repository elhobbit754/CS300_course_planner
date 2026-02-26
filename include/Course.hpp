#pragma once

#include <string>

class BinarySearchTree;

// define a structure to hold course information
struct Course {
    std::string id;

    std::string title;

    std::vector<std::string> prereqs;
};

/**
 * Print the course information
 *
 * @param course struct containing the course info
 */
void displayCourse(Course course);

/**
 * Print the course prerequisites
 *
 * @param course struct containing the course info
 */
void displayPrerequisites(Course course);
