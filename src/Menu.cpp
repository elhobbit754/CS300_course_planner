#include <iostream>
#include <limits>
#include <string>

#include "../include/Bid.hpp"
#include "../include/Menu.hpp"
#include "BinarySearchTree.hpp"

using namespace std;

void Menu::run(int argc, char* argv[]) {
    BinarySearchTree bst;
    int choice = 0;
    const string DEFAULT_BID_ID = "80687";
    string csvPath = argc > 1 ? argv[1] : string(DATA_DIR) + "/eBid_Monthly_Sales.csv";

    while (choice != 9) {
        printOptions();

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number" << endl;

            continue;
        }

        switch (choice) {
            case 1:
                loadBidsAndTrackTime(csvPath, bst);
                break;

            case 2:
                bst.InOrder();
                break;

            case 3: {
                std::string bidKey = promptBidId(DEFAULT_BID_ID);
                findBidAndTrackTime(&bst, bidKey);
                break;
            }

            case 4: {
                std::string bidKey = promptBidId(DEFAULT_BID_ID);
                bst.Remove(bidKey);
                break;
            }

            case 9:
                cout << "Good bye." << endl;
                break;

            default:
                cout << "Invalid choice. Try again" << endl;
        }
    }
}

void Menu::findBidAndTrackTime(BinarySearchTree* bst, const std::string& bidKey) {
    clock_t ticks = clock();
    const Bid bid = bst->Search(bidKey);
    ticks = clock() - ticks; // current clock ticks minus starting clock ticks

    if (!bid.bidId.empty()) {
        displayBid(bid);
    } else {
        cout << "Bid Id " << bidKey << " not found." << endl;
    }

    cout << "time: " << ticks << " clock ticks" << endl;
    cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
}

void Menu::loadBidsAndTrackTime(const string& csvPath, BinarySearchTree& bst) {
    // Initialize a timer variable before loading bids
    clock_t ticks = clock();

    cout << endl;
    cout << "Loading CSV file " << csvPath << endl;
    cout << endl;
    loadBids(csvPath, bst);

    // Calculate elapsed time and display result
    ticks = clock() - ticks; // current clock ticks minus starting clock ticks
    cout << "time: " << ticks << " clock ticks" << endl;
    cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
    cout << endl;
}

void Menu::printOptions() {
    cout << "Menu:" << endl;
    cout << "  1. Load Bids" << endl;
    cout << "  2. Display All Bids" << endl;
    cout << "  3. Find Bid" << endl;
    cout << "  4. Remove Bid" << endl;
    cout << "  9. Exit" << endl;
    cout << "Enter choice: ";
}

string Menu::promptBidId(const string& defaultId) {
    string bidId;

    cout << "Enter Bid ID (or press Enter for default): ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, bidId);

    return bidId.empty() ? defaultId : bidId;
}
