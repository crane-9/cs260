#ifndef HASH_HEADER
#define HASH_HEADER

#include <string>

using std::string;


/// @brief An error to throw on Hashtable::remove() if the given data is not found on the table.
class DataNotFound : public std::exception {
    private:
        string hint;

    public:
        DataNotFound(string data);

        /// @brief Error message.
        string what();
};


/// @brief A simple hashtable.
class Hashtable {
    private:
        const char *EMPTY = "";
        static const int capacity = 16;
        string table[capacity] = {EMPTY};
        
        int size;

        /// @brief First hash function.
        int hash1(string data);

        /// @brief Second hash function.
        int hash2(string data);

        /**
         * Private hash method for hashing data.
         * @param data The string to hash.
         * @return Hashed value -- an index on the table.
        */
        int doubleHash(string data);

    public:
        /// @brief Constructs an empty hashtable.
        Hashtable();

        /// @brief Deconstructs hashtable.
        ~Hashtable();

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
