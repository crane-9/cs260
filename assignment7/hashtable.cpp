#include <iostream>
#include <sstream>
#include <string>

#include "hashtable.h"

using std::cout, std::endl, std::string, std::stringstream;


// Error implementations.

DataNotFound::DataNotFound(string data) {
    hint = data;
}

string DataNotFound::what() {
    return "'" + hint + "' was not found in the hashtable.";
}


// Hashtable implementations.

Hashtable::Hashtable() {
    size = 0;
}

Hashtable::~Hashtable() {
    delete [] &table;
}

int Hashtable::hash(string data) {
    int value;

    for (char i : data) {
        value += i;
    }

    return value % capacity;
}

string Hashtable::display() {
    // Guard claus--save the effort.
    if (size == 0) {
        return "[ Empty hashtable. ]";
    }
    
    stringstream stream;
    string data;
    for (string data : table) {

        // Skip if there's no data.
        if (data == "") {
            continue;
        }

        // Unless this is the first item to print, add delimiter.
        if (stream.tellp() != 0) {  // would it be more efficient to just have a bool flag variable?
            stream << ", ";
        }

        stream << data;
    }

    return stream.str();
}

void Hashtable::insert(string data) {
    int idx = hash(data);

    // THIS OVERWRITES RIGHT NOW!
    table[idx] = data;
    ++size;
}

string Hashtable::position(int index) {
    if (index >= capacity) { 
        throw DataNotFound("Index " + std::to_string(index));
    }
    
    // safe :)
    return table[index];
}

string Hashtable::remove(string data) {
    // Get data.
    int idx = hash(data);
    string value = table[idx];

    // Verify data is as expected.
    if (value != data) {
        throw DataNotFound(data);
    }

    // Empty and return.
    table[idx] = EMPTY;
    --size;
    return value;
}

bool Hashtable::search(string data) {
    int idx = hash(data);
    string value = table[idx];

    return value == data;
}
