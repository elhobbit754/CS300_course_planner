#include <iostream>
#include <limits>
#include <string>

#include "../include/Course.hpp"
#include "../include/View.hpp"
#include "../include/Constants.hpp"
#include "../include/DataService.hpp"

using namespace std;

static const string EMPTY_SPACE = " ";

void View::render(int argc, char* argv[]) {
    DataService dataService;
    int choice = 0;
    string csvPath = argc > 1 ? argv[1] : string(DATA_DIR) + "/" + Constants::DEFAULT_FILE_PATH;

    cout << UI_MESSAGES::WELCOME_TO_THE_COURSE_PLANNER << endl;

    while (static_cast<UserActionTypes>(choice) != UserActionTypes::EXIT_PROGRAM) {
        showMenu();

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
                cout << endl;
                cout << UI_MESSAGES::HERE_IS_A_SAMPLE_SCHEDULE << endl;
                dataService.showCourses();
                cout << endl;
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

void View::showCourseDetails(DataService& dataService) {
    string id = promptCourseId();
    Course course = dataService.searchCourse(id);

    if (!course.id.empty()) {
        cout << endl;
        showBasicCourseInfo(course);
        showCoursePrerequisites(course);
    } else {
        cout << UI_MESSAGES::courseNotFound(course.id) << endl;
    }
}

void View::showBasicCourseInfo(Course course) {
    cout << course.id << ", " << course.title << endl;
}

void View::showCoursePrerequisites(Course course) {
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

void View::showMenu() {
    cout << UI_MESSAGES::LOAD_DATA_STRUCTURE << endl;
    cout << UI_MESSAGES::PRINT_COURSE_LIST << endl;
    cout << UI_MESSAGES::PRINT_COURSE << endl;
    cout << UI_MESSAGES::EXIT << endl;
    cout << UI_MESSAGES::WHAT_WOULD_YOU_LIKE_TO_DO;
}

string View::promptCourseId() {
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
