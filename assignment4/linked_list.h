#ifndef LINK_LIST_HEADER
#define LINK_LIST_HEADER

#include <string>


/// @brief Raise on invalid index.
class IndexError : public std::exception {
    private:
        int hint;

    public:
        IndexError(int data);
        std::string what();
};


/**
 * Node structure. Three values held:
 * @note `value`: Data the node holds.
 * @note `next`: Pointer to the next node in the list.
 * @note `prev`: Pointer to the previous node in the list.
 * @example `node1 = Node{42, nullptr, nullptr};` creates a lone node with value 42.
 * @example `node2 = Node{39, nullptr, &node1};` creates a node with value 39, linked to the first node. `node1` must then be connected to `node2` like so: `node1.next = &node2;`
*/
struct Node {
    int value;
    Node *next;
    Node *prev;
};


/// @brief A list of unrestricted length.
class LinkedList {
    private:
        Node *firstNode;
        Node *lastNode;
        int _length;
        
        /**
         * Get the node at the desired index on the list.
         * @param idx Index of the list.
         * @throws IndexError, if the given index is out of range.
         * @return Pointer to the desired node.
        */
        Node *fetchNode(int idx);

    public:
        /// @brief Construct an empty list.
        LinkedList();

        /**
         * Add to the end of the list.
         * @param newValue The value to add.
         * @return No return value.
        */
        void append(int newValue);
        
        /**
         * Counts the appearances of the given value on the list.
         * @param value The value to count.
         * @return How many times the given value appears on the list.
        */
        int count(int value);

        /**
         * Get the value at the desired index. Value remains in the list.
         * @param idx Index to retrieve.
         * @return The value at the given index.
         * @note Throws IndexError if index is out of range.
        */
        int get(int idx);

        /**
         * Get the index of a given value in the list.
         * @param value The desired value.
         * @return The index of the given value, if on the list.
         * @note Returns index for the first instance of the value on the list.
         * @note Returns -1 if value is not on the list.
        */
       int index(int value);

        /**
         * Insert a value at a specific place in the list.
         * @param idx The index to insert the value at. 
         * @param newValue The value to insert.
         * @return No return value.
         * @note Throws IndexError if the index is invalid.
        */
        void insert(int idx, int newValue);

        /**
         * Check if any items are in the list.
         * @return True if 0 items in the list, otherwise false.
        */
        bool isEmpty();
        
        /**
         * Get the length of the list.
         * @return Length of the list.
        */
        int length() const { return _length; };
        
        /**
         * Remove and return the value at the desired index.
         * @param idx The index of the value to remove and return.
         * @return The value at the given index.
         * @note Throws IndexError if invalid index.
        */
        int pop(int idx);
        
        /**
         * Replace the value at the given position with a new value.
         * @param idx The position to remove, and the new position of the given value.
         * @param newValue The value that will take the position of the previous.
         * @return The old value at the given index.
         * @note Throws IndexError if index is invalid.
        */
        int replace(int idx, int newValue);

        
        /**
         * View the entire list.
         * @note Debug. Not really useful.
         * @return The entire list written out as a string.
        */
        std::string toString();
};


#endif
