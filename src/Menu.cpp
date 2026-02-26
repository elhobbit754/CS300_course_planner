#include <iostream>
#include <limits>
#include <string>

#include "../include/Course.hpp"
#include "../include/Menu.hpp"
#include "../include/BinarySearchTree.hpp"
#include "../include/Constants.hpp"

using namespace std;

static const string EMPTY_SPACE = " ";

void Menu::show(int argc, char* argv[]) {
    BinarySearchTree bst;
    int choice = 0;
    string csvPath = argc > 1 ? argv[1] : string(DATA_DIR) + "/" + Constants::DEFAULT_FILE_PATH;

    cout << UI_MESSAGES::WELCOME_TO_THE_COURSE_PLANNER << endl;

    while (static_cast<UserActionTypes>(choice) != UserActionTypes::EXIT_PROGRAM) {
        printActions();

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << UI_MESSAGES::INVALID_INPUT_ENTER_NUMBER << endl;

            continue;
        }

        switch (choice) {
            case static_cast<int>(UserActionTypes::LOAD_DATA):
                loadCourses(csvPath, bst);
                break;

            case static_cast<int>(UserActionTypes::PRINT_COURSE_LIST):
                cout << UI_MESSAGES::HERE_IS_A_SAMPLE_SCHEDULE << endl;
                bst.InOrder();
                break;

            case static_cast<int>(UserActionTypes::PRINT_COURSE_DETAILS): {
                string id = promptCourseId();
                showCourseDetails(&bst, id);
                break;
            }

            case static_cast<int>(UserActionTypes::EXIT_PROGRAM):
                cout << UI_MESSAGES::THANK_YOU_FOR_USING_THE_COURSE_PLANNER << endl;
                break;

            default:
                cout << choice << EMPTY_SPACE << UI_MESSAGES::IS_NOT_A_VALID_OPTION << endl;
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
        cout << UI_MESSAGES::courseNotFound(courseId) << endl;
    }
}

void Menu::loadCourses(const string& csvPath, BinarySearchTree& bst) {
    cout << UI_MESSAGES::loadingCVSFile(csvPath) << endl;
    cout << endl;
    loadData(csvPath, bst);
    cout << endl;
}

void Menu::printActions() {
    cout << UI_MESSAGES::LOAD_DATA_STRUCTURE << endl;
    cout << UI_MESSAGES::PRINT_COURSE_LIST << endl;
    cout << UI_MESSAGES::PRINT_COURSE << endl;
    cout << UI_MESSAGES::EXIT << endl;
    cout << UI_MESSAGES::WHAT_WOULD_YOU_LIKE_TO_DO;
}

string Menu::promptCourseId() {
    string id;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (true) {
        cout << UI_MESSAGES::WHAT_COURSE_DO_YOU_WANT_TO_KNOW_ABOUT << EMPTY_SPACE;
        getline(cin, id);

        if (!id.empty()) {
            return id;
        }

        cout << UI_MESSAGES::COURSE_ID_CANNOT_BE_EMPTY_PLEASE_TRY_AGAIN << endl;
    }
}
