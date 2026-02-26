#pragma once

#include <string>
#include "Course.hpp"

// Internal structure for tree node
struct Node {
    Course course;
    Node *left;
    Node *right;

    // default constructor
    Node() {
        left = nullptr;
        right = nullptr;
    }

    // initialize with a course
    Node(Course data) :
            Node() {
        course = data;
    }
};

/**
 * Implements a Binary Search Tree (BST) for storing Courses
 */
class BinarySearchTree {
    private:
        /**
         * Pointer to the root node of the tree.
         */
        Node* root;

        /**
         * Recursively inserts a bid into the tree.
         * @param node Current node
         * @param course The course to insert
         */
        void addNode(Node* node, Course course);

        /**
         * Performs an in-order traversal starting at a specified node.
         * @param node Current node
         */
        void inOrder(Node* node);

       /**
        * Recursively deletes all nodes in the tree.
        * @param node Current node
        */
        void destroy(Node* node);

    public:
        /**
         * Constructor
         */
        BinarySearchTree();

        /**
         * Destructor
         */
        virtual ~BinarySearchTree();

        /**
         * Performs in-order traversal of the tree
         */
        void InOrder();

        /**
         * Inserts a new course into the tree.
         * @param course The course to insert.
         */
        void Insert(Course course);

        /**
         * Searches the tree for a specific course
         * @param courseId The ID of the course
         * @return The matching course or an empty Bid
         */
        Course Search(std::string courseId);
};
