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


struct Node {
    int value;
    Node* next;
    Node* prev;
};


/// @brief A list of unrestricted length.
class LinkedList {
    private:
        Node* firstNode;
        Node* lastNode;
        int _length;
        
        /**
         * Get the node at the desired index on the list.
         * @param idx Index of the list.
         * @return Pointer to the desired node.
        */
        Node* fetchNode(int idx);

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
         * Get the value at the desired index. Value remains in the list.
         * @param idx Index to retrieve.
         * @return The value at the given index. 
        */
        int get(int idx);

        /**
         * Insert a value at a specific place in the list.
         * @param idx The index to insert the value at. 
         * @param newValue The value to insert.
         * @return No return value.
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
         * View the entire list.
         * @note For debug, not really useful.
         * @return The entire list written out as a string.
        */
        std::string peek();
        
        /**
         * Remove and return the value at the desired index.
         * @param idx The index of the value to remove and return.
         * @return The value at the given index.
        */
        int pop(int idx);
        
        /**
         * Replace the value at the given position with a new value.
         * @param idx The position to remove, and the new position of the given value.
         * @param newValue The value that will take the position of the previous.
         * @return The old value at the given index.
        */
        int replace(int idx, int newValue);
};


#endif
