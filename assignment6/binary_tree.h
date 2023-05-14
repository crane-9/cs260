#ifndef BINARY_TREE_HEADER
#define BINARY_TREE_HEADER

#include <string>


/// @brief Binary tree node, holding an integer.
struct Node {
    int value;
    Node *left, *right;
};


/// @brief Error indicates a value is missing from a tree.
class MissingValueError : public std::exception {
    private:
        int _value;

    public:
        MissingValueError(int value);
        std::string what();
};


/// @brief Binary search tree with three basic methods.
class BSTree {
    private:
        /// @brief Root of the tree.
        Node* root;
        
        /// @brief Depth of the tree, root level at 0.
        int depth;

        /// @brief Count of items in the tree.
        int items;

        // bool recurSearch(int value, Node *branch);

    public:
        /**
         * Constructs a binary search tree with a root of the given value.
         * @param _root The tree's root's value.
        */
        BSTree(int _root);

        /**
         * Adds a value to the tree.
         * @param value The value to add to the tree.
        */
        void add(int value);

        /**
         * Removes the given value from the tree.
         * @param value Value to remove from the tree.
         * @throws MissingValueError, if the given value cannot be found in the tree.
         * @return The removed value.
        */
        int remove(int value);

        /**
         * Searches for the given value, without raising an error.
         * @param value The sought value.
         * @return True if present in the tree, false if absent.
        */
        bool search(int value);
};


/// @brief A namespace to organize traversal functions.
namespace traversals {
    /**
     * Traverses the tree in pre-order.
     * @param root The root of the tree.
     * @return A string of the tree's values pre-order.
    */
    std::string preOrder(Node *root);

    /**
     * Traverses the tree in-order.
     * @param root The root of the tree.
     * @return A string of the tree's values in-order.
    */
    std::string inOrder(Node *root);

    /**
     * Traverses the tree post-order.
     * @param root The root of the tree.
     * @return A string of the tree's values post-order.
    */
    std::string postOrder(Node *root);
    
    /**
     * Traverses the tree breadth-first.
     * @param root The root of the tree.
     * @return A string of the tree's values, breadth-first.
    */
    std::string breadthFirst(Node *root);
};


#endif
