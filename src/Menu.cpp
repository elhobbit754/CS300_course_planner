#include <iostream>
#include <limits>
#include <string>

#include "../include/Course.hpp"
#include "../include/Menu.hpp"
#include "../include/Constants.hpp"
#include "../include/DataService.hpp"

using namespace std;

static const string EMPTY_SPACE = " ";

void Menu::show(int argc, char* argv[]) {
    DataService dataService;
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
                cout << UI_MESSAGES::loadingCVSFile(csvPath) << endl;
                cout << endl;
                dataService.loadCourses(csvPath);;
                cout << endl;
                break;

            case static_cast<int>(UserActionTypes::PRINT_COURSE_LIST):
                cout << UI_MESSAGES::HERE_IS_A_SAMPLE_SCHEDULE << endl;
                dataService.showCourses();
                break;

            case static_cast<int>(UserActionTypes::PRINT_COURSE_DETAILS): {
                showCourseDetails(dataService);
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

void Menu::showCourseDetails(DataService& dataService) {
    string id = promptCourseId();
    Course course = dataService.searchCourse(id);

    if (!course.id.empty()) {
        cout << endl;
        displayCourse(course);
        displayPrerequisites(course);
    } else {
        cout << UI_MESSAGES::courseNotFound(course.id) << endl;
    }
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
