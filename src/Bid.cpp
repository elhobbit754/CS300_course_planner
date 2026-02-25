#include <iostream>
#include <string>

#include "../include/CSVparser.hpp"
#include "../include/Bid.hpp"
#include "BinarySearchTree.hpp"

using namespace std;

double strToDouble(string str, char ch) {
    str.erase(remove(str.begin(), str.end(), ch), str.end());

    return atof(str.c_str());
}

void displayBid(Bid bid) {
    cout << bid.bidId << ": " << bid.title << " | " << bid.amount << " | "
            << bid.fund << endl;
}

void loadBids(const std::string& csvPath, BinarySearchTree& bst) {
    // initialize the CSV Parser using the given path
    csv::Parser file = csv::Parser(csvPath);

    size_t counter = 0;

    try {
        // loop to read rows of a CSV file
        for (unsigned int i = 0; i < file.rowCount(); i++) {
            // Create a data structure and add to the collection of bids
            Bid bid;
            bid.bidId = file[i][1];
            bid.title = file[i][0];
            bid.fund = file[i][8];
            bid.amount = strToDouble(file[i][4], '$');

            // push this bid to the end
            bst.Insert(bid);
            ++counter;
        }
    } catch (csv::Error &e) {
        cerr << e.what() << endl;
    }

    cout << counter << " bids read" << endl;
}
