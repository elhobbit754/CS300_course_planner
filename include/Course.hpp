#pragma once

#include <string>

class BinarySearchTree;

// define a structure to hold bid information
struct Course {
    std::string bidId; // unique identifier

    std::string title;

    std::string fund;

    double amount;

    Course() {
        amount = 0.0;
    }
};

/**
* Simple C function to convert a string to a double
 * after stripping out unwanted char
 *
 * credit: http://stackoverflow.com/a/24875936
 *
 * @param ch The character to strip out
 */
double strToDouble(std::string str, char ch);

/**
 * Print the course information
 *
 * @param course struct containing the course info
 */
void displayCourse(Course course);

/**
 * Load a CSV file containing courses
 *
 * @param csvPath the path to the CSV file to load
 * @param bst binary search tree to store loaded bids
 */
void loadData(const std::string& csvPath, BinarySearchTree& bst);
