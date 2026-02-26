#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

// This is a namespace with application constants
namespace Constants {
    constexpr int NO_ITEMS_FOUND = 0;
    inline std::string DEFAULT_FILE_PATH = "CS 300 ABCU_Advising_Program_Input.csv";
}

// This is a namespace with messages shown to the user
namespace UI_MESSAGES {
    inline std::string THANK_YOU_FOR_USING_THE_COURSE_PLANNER = "Thank you for using the course planner!";
    inline std::string IS_NOT_A_VALID_OPTION = "is not a valid option.";
    inline std::string INVALID_INPUT_ENTER_NUMBER = "Invalid input. Please enter a number";
    inline std::string WELCOME_TO_THE_COURSE_PLANNER = "Welcome to the course planner.";
    inline std::string HERE_IS_A_SAMPLE_SCHEDULE = "Here is a sample schedule:";
    inline std::string COURSE_ID_CANNOT_BE_EMPTY_PLEASE_TRY_AGAIN = "Course ID cannot be empty. Please try again.";
    inline std::string WHAT_COURSE_DO_YOU_WANT_TO_KNOW_ABOUT = "What course do you want to know about?:";
    inline std::string WHAT_WOULD_YOU_LIKE_TO_DO = "What would you like to do? ";
    inline std::string LOAD_DATA_STRUCTURE = " 1. Load Data Structure.";
    inline std::string PRINT_COURSE_LIST = " 2. Print Course List.";
    inline std::string PRINT_COURSE = " 3. Print Course.";
    inline std::string EXIT = " 9. Exit";

    inline std::string courseNotFound(std::string_view id) {
        return std::string("Course Id ") +
               std::string(id) +
               std::string(" not found.");
    }
    inline std::string loadingCVSFile(std::string_view csvPath) {
        return std::string("Loading CSV file ") +
               std::string(csvPath);
    }
}

// This enum has actions that are available to the user to manage the app
enum class UserActionTypes : int {
    LOAD_DATA = 1,
    PRINT_COURSE_LIST = 2,
    PRINT_COURSE_DETAILS = 3,
    EXIT_PROGRAM = 9,
};

#endif //CONSTANTS_H
