#include <iostream>
#include <string>

#include "../include/Course.hpp"
#include "../include/BinarySearchTree.hpp"
#include <csv.hpp>

using namespace std;

void displayCourse(Course course) {
    cout << course.id << ", " << course.title << endl;
}

void displayPrerequisites(Course course) {
    if (course.prereqs.empty()) {
        cout << "This course does not have prerequisites" << endl;
        cout << endl;
        return;
    }

    cout << "Prerequisites: ";

    for (size_t i = 0; i < course.prereqs.size(); ++i) {
        cout << course.prereqs[i] << ", ";
    }

    cout << endl;
    cout << endl;
}
