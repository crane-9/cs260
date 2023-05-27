#ifndef HASH_ERROR_HEADER
#define HASH_ERROR_HEADER

#include <string>

using std::string;


/// @brief An error to throw on Hashtable::remove() if the given data is not found on the table.
class DataNotFound : public std::exception {
    private:
        string hint;

    public:
        DataNotFound(string data) {
            hint = data;
        }

        /// @brief Error message.
        string what() {
            return "'" + hint + "' was not found in the hashtable.";
        }
};
    

/// @brief An error to throw on insert() on a full table.
class FullTableError : public std::exception {
    public:
        string what() {
            return "Cannot insert, table is full.";
        }
};

#endif
