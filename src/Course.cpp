#include <iostream>
#include <string>

#include "../include/CSVparser.hpp"
#include "../include/Course.hpp"
#include "../include/BinarySearchTree.hpp"

using namespace std;

double strToDouble(string str, char ch) {
    str.erase(remove(str.begin(), str.end(), ch), str.end());

    return atof(str.c_str());
}

void displayCourse(Course course) {
    cout << course.bidId << ": " << course.title << " | " << course.amount << " | "
            << course.fund << endl;
}

void loadData(const std::string& csvPath, BinarySearchTree& bst) {
    // initialize the CSV Parser using the given path
    csv::Parser file = csv::Parser(csvPath);

    size_t counter = 0;

    try {
        // loop to read rows of a CSV file
        for (unsigned int i = 0; i < file.rowCount(); i++) {
            // Create a data structure and add to the collection of bids
            Course course;
            course.bidId = file[i][1];
            course.title = file[i][0];
            course.fund = file[i][8];
            course.amount = strToDouble(file[i][4], '$');

            // push this bid to the end
            bst.Insert(course);
            ++counter;
        }
    } catch (csv::Error &e) {
        cerr << e.what() << endl;
    }

    cout << counter << " courses read" << endl;
}
