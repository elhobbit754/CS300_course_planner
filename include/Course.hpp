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

/**
 * Load a CSV file containing courses
 *
 * @param csvPath the path to the CSV file to load
 * @param bst binary search tree to store loaded bids
 */
void loadData(const std::string& csvPath, BinarySearchTree& bst);
