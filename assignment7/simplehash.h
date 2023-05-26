#ifndef SIMPLE_HASH_HEADER
#define SIMPLE_HASH_HEADER

#include <string>

#include "error.h"

using std::string;


/// @brief A simple hashtable.
class SimpleHash {
    private:
        const char *EMPTY = "";
        static const int capacity = 16;
        string table[capacity] = {EMPTY};
        
        int size;

        /**
         * Private hash method for hashing data.
         * @param data The string to hash.
         * @return Hashed value -- an index on the table.
        */
        int hash(string data);

    public:
        /// @brief Constructs an empty hashtable.
        SimpleHash();

        /// @brief Deconstructs hashtable.
        ~SimpleHash();

        /**
         * Returns the current table as a string.
         * @param showEmpty False by default. True includes empty spaces for debug.
         * @return All items on the table, listed in order.
        */
        string display(const bool showEmpty = false);

        /**
         * Getter for the table's total capacity.
         * @return Table capacity.
        */
        int getCapacity() const { return capacity; }

        /**
         * Getter for the table's current size.
         * @return Number of items currently in the table.
        */
        int getSize() const { return size; }

        /**
         * Inserts new data into the table.
         * @param data Data to add to the table.
         * @return No return value.
        */
        void insert(string data);

        /**
         * Checks if the table is full.
         * @return True if full, false if there are open spaces.
        */
        inline bool isFull() { return size == capacity; }

        /**
         * Returns data from the given index.
         * @param index Desired index.
         * @return The value at the given index. 
        */
        string position(int index);

        /**
         * Returns and removes a given piece of data from the table.
         * @param data Data to remove from the table.
         * @return Data removed from the table.
         * @throws DataNotFound if the given data does not exist on the table. 
        */
        string remove(string data);

        /**
         * Checks if a given value is present within the table.
         * @param data Value to search the table for.
         * @return True if the given data is present.
        */
        bool search(string data);
};

#endif
