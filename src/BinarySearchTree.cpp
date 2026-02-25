//============================================================================
// Name        : BinarySearchTree.cpp
// Author      : Oleksii (Alex) Hubin
// Version     : 1.0
// Copyright   : Copyright � 2023 SNHU COCE
// Description : Lab 5-2 Binary Search Tree
//============================================================================

#include <iostream>

#include "../include/BinarySearchTree.hpp"
#include "../include/Course.hpp"

using namespace std;

static const string VERTICAL_LINE_DIVIDER = " | ";

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
 * Insert a course
 */
void BinarySearchTree::Insert(Course course) {
    if (root == nullptr) {
        root = new Node(course);
    } else {
        addNode(root, course);
    }
}

/**
 * Search for a course
 */
Course BinarySearchTree::Search(string courseId) {
    Node* current = root;

    while (current != nullptr) {
        if (current->course.id == courseId) {
            return current->course;
        }

        if (courseId < current->course.id) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    return Course();
}

/**
 * Add a course to some node (recursive)
 *
 * @param node Current node in tree
 * @param course course to be added
 */
void BinarySearchTree::addNode(Node* node, Course course) {
    if (course.id < node->course.id) {
        if (node->left == nullptr) {
            node->left = new Node(course);
        } else {
            addNode(node->left, course);
        }
    } else {
        if (node->right == nullptr) {
            node->right = new Node(course);
        } else {
            addNode(node->right, course);
        }
    }
}

void BinarySearchTree::inOrder(Node* node) {
    if (node == nullptr) {
        return;
    }

    inOrder(node->left);

    cout << node->course.id << VERTICAL_LINE_DIVIDER
         << node->course.title << endl;

    inOrder(node->right);
}

void BinarySearchTree::destroy(Node* node) {
    if (node == nullptr) {
        return;
    }

    destroy(node->left);
    destroy(node->right);
    delete node;
}
