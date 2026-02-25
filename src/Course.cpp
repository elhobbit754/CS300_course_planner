#include <iostream>
#include <string>

#include "../include/CSVparser.hpp"
#include "../include/Course.hpp"
#include "../include/BinarySearchTree.hpp"

using namespace std;

void displayCourse(Course course) {
    cout << course.id << ": " << course.title << endl;
}

void loadData(const std::string& csvPath, BinarySearchTree& bst) {
    csv::Parser file = csv::Parser(csvPath);

    size_t counter = 0;

    try {
        // loop to read rows of a CSV file
        for (unsigned int i = 0; i < file.rowCount(); i++) {
            Course course;
            course.id = file[i][0];
            course.title = file[i][1];

            bst.Insert(course);
            ++counter;
        }
    } catch (csv::Error &e) {
        cerr << e.what() << endl;
    }

    cout << counter << " courses read" << endl;
}
