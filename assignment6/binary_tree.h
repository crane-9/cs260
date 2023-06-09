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

        /// @brief Count of items in the tree.
        int items;

        /**
         * Finds and returns a node with the given value.
         * @param value The desired value of the node.
         * @throws MissingValueError if the given value does not exist in the tree.
         * @return The first node with the given value.
        */
        Node* findByValue(int value);

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

        /**
         * Getter method for the number of items on a tree.
         * @return Integer for number of items in a tree.  
        */
        int size() const { return items; }

        /**
         * Traverses the tree pre-order.
         * @return A string of the tree's values pre-order.
        */
        std::string traversePreOrder();

        /**
         * Traverses the tree in-order.
         * @return A string of the tree's values in-order.
        */
        std::string traverseInOrder();

        /**
         * Traverses the tree post-order.
         * @return A string of the tree's values post-order.
        */
        std::string traversePostOrder();

        /**
         * Traverses the tree breadth-first.
         * @return A string of the tree's values breadth-first.
        */
        std::string traverseBreadthFirst();
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
