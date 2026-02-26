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

void loadData(const string& csvPath, BinarySearchTree& bst) {
    csv::CSVReader reader(csvPath);

    size_t counter = 0;

    for (auto& row : reader) {
        Course course;
        course.id = row[0].get<>();
        course.title = row[1].get<>();

        for (size_t i = 2; i < row.size(); ++i) {
            string prereq = row[i].get<>();

            if (!prereq.empty()) {
                course.prereqs.push_back(prereq);
            }
        }

        bst.Insert(course);
        counter++;
    }

    cout << counter << " courses read" << endl;
}
