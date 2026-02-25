#include <iostream>
#include <limits>
#include <string>

#include "../include/Course.hpp"
#include "../include/Menu.hpp"
#include "../include/BinarySearchTree.hpp"

using namespace std;

void Menu::run(int argc, char* argv[]) {
    BinarySearchTree bst;
    int choice = 0;
    const string DEFAULT_BID_ID = "80687";
    string csvPath = argc > 1 ? argv[1] : string(DATA_DIR) + "/CS 300 ABCU_Advising_Program_Input.csv";

    cout << "Welcome to the course planner." << endl;

    while (choice != 9) {
        printOptions();

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number" << endl;

            continue;
        }

        switch (choice) {
            case 1:
                loadCourseList(csvPath, bst);
                break;

            case 2:
                cout << "Here is a sample schedule:" << endl;
                bst.InOrder();
                break;

            case 3: {
                std::string bidKey = promptCourseId(DEFAULT_BID_ID);
                findCourse(&bst, bidKey);
                break;
            }

            case 9:
                cout << "Good bye." << endl;
                break;

            default:
                cout << choice << " is not a valid option." << endl;
        }
    }
}

void Menu::findCourse(BinarySearchTree* bst, const std::string& courseId) {
    const Course course = bst->Search(courseId);

    if (!course.id.empty()) {
        displayCourse(course);
    } else {
        cout << "Course Id " << courseId << " not found." << endl;
    }
}

void Menu::loadCourseList(const string& csvPath, BinarySearchTree& bst) {
    cout << "Loading CSV file " << csvPath << endl;
    cout << endl;
    loadData(csvPath, bst);
    cout << endl;
}

void Menu::printOptions() {
    cout << "  1. Load Data Structure." << endl;
    cout << "  2. Print Course List." << endl;
    cout << "  3. Print Course." << endl;
    cout << "  9. Exit" << endl;
    cout << "What would you like to do? ";
}

string Menu::promptCourseId(const string& defaultId) {
    string id;

    cout << "What course do you want to know about?: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, id);

    return id.empty() ? defaultId : id;
}
