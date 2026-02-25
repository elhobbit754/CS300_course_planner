#pragma once

#include <string>
#include "BinarySearchTree.hpp"

/**
 * Command-line menu controller for the bid application.
 * This class is implemented as a static utility and does not maintain state.
 */
class Menu {
    private:
        /**
         * Displays the numbered actions that the user can select from
         * when interacting with the application.
         */
        static void printOptions();

        /**
         * If the user provides an empty input, the supplied default ID
         * is returned instead.
         *
         * @param defaultId The course ID to use if the user presses Enter.
         * @return The user-provided course ID or the default value.
         */
        static std::string promptCourseId(const std::string& defaultId);

        /**
         * Reads course records from the specified CSV file, inserts them
         * into a provided tree, and reports the elapsed time.
         *
         * @param csvPath Path to the CSV file containing course data.
         * @param bst Pointer to the tree receiving the courses.
         */
        static void loadDataAndTrackTime(const std::string& csvPath, BinarySearchTree& bst);

        /**
         * Search for a bid and measure execution time.
         *
         * @param bst Pointer to the tree to search.
         * @param id The course id to search for.
         */
        static void findBidAndTrackTime(BinarySearchTree* bst, const std::string& id);

    public:
        /**
         * Initializes required resources, processes command-line arguments,
         * and enters the main input loop until the user exits.
         *
         * @param argc Argument count from the command line.
         * @param argv Argument values from the command line.
         */
        static void run(int argc, char* argv[]);
};
