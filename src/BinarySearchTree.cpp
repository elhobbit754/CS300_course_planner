//============================================================================
// Name        : BinarySearchTree.cpp
// Author      : Oleksii (Alex) Hubin
// Version     : 1.0
// Copyright   : Copyright � 2023 SNHU COCE
// Description : Lab 5-2 Binary Search Tree
//============================================================================

#include <iostream>

#include "../include/CSVparser.hpp"
#include "../include/BinarySearchTree.hpp"
#include "../include/Bid.hpp"

using namespace std;

static const string SEPARATOR = " | ";

//============================================================================
// Binary Search Tree class definition
//============================================================================

/**
 * Default constructor
 */
BinarySearchTree::BinarySearchTree() {
    root = nullptr;
}

/**
 * Destructor
 */
BinarySearchTree::~BinarySearchTree() {
    destroy(root);
}

/**
 * Traverse the tree in order
 */
void BinarySearchTree::InOrder() {
    inOrder(root);
}

/**
 * Traverse the tree in post-order
 */
void BinarySearchTree::PostOrder() {
    postOrder(root);
}

/**
 * Traverse the tree in pre-order
 */
void BinarySearchTree::PreOrder() {
    preOrder(root);
}

/**
 * Insert a bid
 */
void BinarySearchTree::Insert(Bid bid) {
    if (root == nullptr) {
        root = new Node(bid);
    } else {
        addNode(root, bid);
    }
}

/**
 * Remove a bid
 */
void BinarySearchTree::Remove(string bidId) {
    root = removeNode(root, bidId);
}

/**
 * Search for a bid
 */
Bid BinarySearchTree::Search(string bidId) {
    Node* current = root;

    while (current != nullptr) {
        if (current->bid.bidId == bidId) {
            return current->bid;
        }

        if (bidId < current->bid.bidId) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    return Bid();
}

/**
 * Add a bid to some node (recursive)
 *
 * @param node Current node in tree
 * @param bid Bid to be added
 */
void BinarySearchTree::addNode(Node* node, Bid bid) {
    if (bid.bidId < node->bid.bidId) {
        if (node->left == nullptr) {
            node->left = new Node(bid);
        } else {
            addNode(node->left, bid);
        }
    } else {
        if (node->right == nullptr) {
            node->right = new Node(bid);
        } else {
            addNode(node->right, bid);
        }
    }
}

void BinarySearchTree::inOrder(Node* node) {
    if (node == nullptr) {
        return;
    }

    inOrder(node->left);

    cout << node->bid.bidId << SEPARATOR
         << node->bid.title << SEPARATOR
         << node->bid.amount << SEPARATOR
         << node->bid.fund << endl;

    inOrder(node->right);
}

void BinarySearchTree::postOrder(Node* node) {
    if (node == nullptr) {
        return;
    }

    postOrder(node->left);
    postOrder(node->right);

    cout << node->bid.bidId << SEPARATOR
         << node->bid.title << SEPARATOR
         << node->bid.amount << SEPARATOR
         << node->bid.fund << endl;
}

void BinarySearchTree::preOrder(Node* node) {
    if (node == nullptr) {
        return;
    }

    cout << node->bid.bidId << SEPARATOR
         << node->bid.title << SEPARATOR
         << node->bid.amount << SEPARATOR
         << node->bid.fund << endl;

    preOrder(node->left);

    preOrder(node->right);
}

/**
 * Remove a bid from some node (recursive)
 */
Node* BinarySearchTree::removeNode(Node* node, string bidId) {
    if (node == nullptr) {
        return node;
    }

    if (bidId < node->bid.bidId) {
        node->left = removeNode(node->left, bidId);

        return node;
    }

    if (bidId > node->bid.bidId) {
        node->right = removeNode(node->right, bidId);

        return node;
    }

    if (node->left == nullptr && node->right == nullptr) {
        delete node;

        return nullptr;
    }

    if (node->left == nullptr) {
        Node* temp = node->right;

        delete node;

        return temp;
    }

    if (node->right == nullptr) {
        Node* temp = node->left;

        delete node;

        return temp;
    }

    Node* successor = node->right;

    while (successor->left != nullptr) {
        successor = successor->left;
    }

    node->bid = successor->bid;
    node->right = removeNode(node->right, successor->bid.bidId);

    return node;
}

void BinarySearchTree::destroy(Node* node) {
    if (node == nullptr) {
        return;
    }

    destroy(node->left);
    destroy(node->right);
    delete node;
}
