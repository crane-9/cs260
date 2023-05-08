#ifndef AUTOLIST_HEADER
#define AUTOLIST_HEADER


#include <iostream>
#include <sstream>
#include <string>


/// @brief Error throws when a given value does not exist in a list.
class ValueNotFoundError : public std::exception {
    private:
        int hint;

    public:
        ValueNotFoundError(int data);
        std::string what();
};


/// @brief Represents a single item on a list.
struct Node
{
    int data;
    Node *next;
};


/// @brief A list that automatically sorts each and every new value into place.
class AutoList {
    private:
        Node *head;
        int _len;

        // /**
        //  * Search algorithm.
        //  * @param Value to search for.
        //  * @return The node holding the desired 
        // */
        // Node *search(int value);

    public:
        /**
         * Constructs an empty list.
        */
        AutoList();

        /**
         * Returns the index of the given value, if any.
         * @param value The value to locate in the list.
         * @throws ValueNotFoundError, if the list does not contain the given value.
         * @return Index of the value.
        */
        int index(int value);

        /**
         * Adds a new value to the list, and sorts it.
         * @param data New value.
         * @return No return value.
        */
        void insert(int data);

        /**
         * Gets the length of the list.
         * @return Number of items in the list.
        */
        int length() const { return _len; }

        /**
         * Removes the given value from the list.
         * @param value The value to remove from the list.
         * @throws ValueNotFoundError, if the list does not contain the given value.
         * @return The removed value. 
        */
        int remove(int value);

        /**
         * Creates a string representation of the list.
         * @return String.
        */
        std::string toString();
};


#endif
