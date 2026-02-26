#pragma once

#include <string>
#include "DataService.hpp"

/**
 * Command-line menu controller for the bid application.
 * This class is implemented as a static utility and does not maintain state.
 */
class View {
    public:
        /**
         * Initializes required resources, processes command-line arguments,
         * and enters the main input loop until the user exits.
         *
         * @param argc Argument count from the command line.
         * @param argv Argument values from the command line.
         */
        static void render(int argc, char* argv[]);

        /**
         * Print the course information
         *
         * @param course struct containing the course info
         */
        static void displayCourse(Course course);

        /**
         * Print the course prerequisites
         *
         * @param course struct containing the course info
         */
        static void displayPrerequisites(Course course);

    private:
        /**
         * Displays the numbered actions that the user can select from
         * when interacting with the application.
         */
        static void showMenu();

        /**
         * If the user provides an empty input, the supplied default ID
         * is returned instead.
         *
         * @return The user-provided course ID or the default value.
         */
        static std::string promptCourseId();

        static void showCourseDetails(DataService& dataService);
};
