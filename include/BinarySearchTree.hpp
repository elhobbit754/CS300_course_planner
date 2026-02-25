#pragma once

#include <string>
#include "Bid.hpp"

// Internal structure for tree node
struct Node {
    Bid bid;
    Node *left;
    Node *right;

    // default constructor
    Node() {
        left = nullptr;
        right = nullptr;
    }

    // initialize with a bid
    Node(Bid aBid) :
            Node() {
        bid = aBid;
    }
};

/**
 * Implements a Binary Search Tree (BST) for storing Bids
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
         * @param bid The bid to insert
         */
        void addNode(Node* node, Bid bid);

        /**
         * Performs an in-order traversal starting at a specified node.
         * @param node Current node
         */
        void inOrder(Node* node);

        /**
         * Performs a post-order traversal at a specified node
         * @param node Current node
         */
        void postOrder(Node* node);

        /**
         * Performs a pre-order traversal starting at a specified node
         * @param node Current node
         */
        void preOrder(Node* node);

        /**
         * Recursively removes a node with the bid ID.
         * @param node Current subtree root.
         * @param bidId ID of the bid to remove.
         * @return Pointer to the updated subtree root.
         */
        Node* removeNode(Node* node, std::string bidId);

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
         * Performs post-order traversal of the tree.
         */
        void PostOrder();

        /**
         * Performs pre-order traversal of the tree.
         */
        void PreOrder();

        /**
         * Inserts a new bid into the tree.
         * @param bid The bid to insert.
         */
        void Insert(Bid bid);

        /**
         * Removes a bid from the tree
         * @param bidId ID of the bid
         */
        void Remove(std::string bidId);

        /**
         * Searches the tree for a specific bid
         * @param bidId The ID of the bid
         * @return The matching Bid or an empty Bid
         */
        Bid Search(std::string bidId);
};
