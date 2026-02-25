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
         * @param defaultId The bid ID to use if the user presses Enter.
         * @return The user-provided bid ID or the default value.
         */
        static std::string promptBidId(const std::string& defaultId);

        /**
         * Reads bid records from the specified CSV file, inserts them
         * into a provided tree, and reports the elapsed time.
         *
         * @param csvPath Path to the CSV file containing bid data.
         * @param bst Pointer to the tree receiving the bids.
         */
        static void loadBidsAndTrackTime(const std::string& csvPath, BinarySearchTree& bst);

        /**
         * Search for a bid and measure execution time.
         *
         * @param bst Pointer to the tree to search.
         * @param bidKey The bid key to search for.
         */
        static void findBidAndTrackTime(BinarySearchTree* bst, const std::string& bidKey);

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
