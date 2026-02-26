#include <iostream>
#include <limits>
#include <string>

#include "../include/Course.hpp"
#include "../include/Menu.hpp"
#include "../include/BinarySearchTree.hpp"

using namespace std;

static const string DEFAULT_FILE_PATH = "CS 300 ABCU_Advising_Program_Input.csv";

void Menu::show(int argc, char* argv[]) {
    BinarySearchTree bst;
    int choice = 0;
    string csvPath = argc > 1 ? argv[1] : string(DATA_DIR) + "/" + DEFAULT_FILE_PATH;

    cout << "Welcome to the course planner." << endl;

    while (choice != 9) {
        printActions();

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number" << endl;

            continue;
        }

        switch (choice) {
            case 1:
                loadCourses(csvPath, bst);
                break;

            case 2:
                cout << "Here is a sample schedule:" << endl;
                bst.InOrder();
                break;

            case 3: {
                string id = promptCourseId();
                showCourseDetails(&bst, id);
                break;
            }

            case 9:
                cout << "Thank you for using the course planner!" << endl;
                break;

            default:
                cout << choice << " is not a valid option." << endl;
        }
    }
}

void Menu::showCourseDetails(BinarySearchTree* bst, const std::string& courseId) {
    const Course course = bst->Search(courseId);

    if (!course.id.empty()) {
        cout << endl;
        displayCourse(course);
        displayPrerequisites(course);
    } else {
        cout << "Course Id " << courseId << " not found." << endl;
    }
}

void Menu::loadCourses(const string& csvPath, BinarySearchTree& bst) {
    cout << "Loading CSV file " << csvPath << endl;
    cout << endl;
    loadData(csvPath, bst);
    cout << endl;
}

void Menu::printActions() {
    cout << "  1. Load Data Structure." << endl;
    cout << "  2. Print Course List." << endl;
    cout << "  3. Print Course." << endl;
    cout << "  9. Exit" << endl;
    cout << "What would you like to do? ";
}

string Menu::promptCourseId() {
    string id;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (true) {
        cout << "What course do you want to know about?: ";
        getline(cin, id);

        if (!id.empty()) {
            return id;
        }

        cout << "Course ID cannot be empty. Please try again." << endl;
    }
}
