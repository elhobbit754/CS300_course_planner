#pragma once

#include <string>

class BinarySearchTree;

// define a structure to hold bid information
struct Bid {
    std::string bidId; // unique identifier

    std::string title;

    std::string fund;

    double amount;

    Bid() {
        amount = 0.0;
    }
};

/**
* Simple C function to convert a string to a double
 * after stripping out unwanted char
 *
 * credit: http://stackoverflow.com/a/24875936
 *
 * @param ch The character to strip out
 */
double strToDouble(std::string str, char ch);

/**
 * Print the bid information
 *
 * @param bid struct containing the bid info
 */
void displayBid(Bid bid);

/**
 * Load a CSV file containing bids into the hash table
 *
 * @param csvPath the path to the CSV file to load
 * @param bst binary search tree to store loaded bids
 */
void loadBids(const std::string& csvPath, BinarySearchTree& bst);
