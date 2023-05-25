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

        /**
         * Private hash method for hashing data.
         * @param data The string to hash.
         * @return Hashed value -- an index on the table.
        */
        int hash(string data);

    public:
        /// @brief Constructs an empty hashtable.
        Hashtable();

        /// @brief Deconstructs hashtable.
        ~Hashtable();

        /**
         * Displays the current table by printing it to terminal.
         * @return No return value, only prints..... for now.
        */
        void display();

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
         * Searches for a value within the table. Throws no errors.
         * @param data Value to search the table for.
         * @return True if the given data is present.
        */
        bool search(string data);
};

#endif
