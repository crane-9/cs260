#include <iostream>
#include <sstream>
#include <string>

#include "hashtable.h"
#include "error.h"

using std::string, std::stringstream;


Hashtable::Hashtable() {
    size = 0;
}

Hashtable::~Hashtable() {
    delete [] &table;
}

int Hashtable::hash1(string data) { 
    int value;

    for (char i : data) {
        value += i;
    }
    return value % capacity; // Output range of [0 -- capacity-1]
}

int Hashtable::hash2(string data) { 
    int value;

    for (int i = 0; i < data.size(); ++i) {
        value += (i + 1) * data[i];
    }
    return value % (capacity - 1) + 1; // Output range of [1 -- capacity-1]
}

int Hashtable::doubleHash(string data, int i) {
    if (i == 0) {
        return hash1(data);
    }

    return (hash1(data) + i * hash2(data)) % capacity;
}

int Hashtable::findIndexOf(string data, string target) {
    int idx;
    for (int i = 0; i < capacity; ++i) { // [no idea if i < capacity is what it should be]
        idx = doubleHash(data, i);
        if (table[idx] == target) { // Target is expected EMPTY or data.
            return idx;
        }
    }
    throw DataNotFound(data);
}

string Hashtable::display(const bool showEmpty) {
    // Guard.
    if (size == 0) {
        return "[ Empty hashtable. ]";
    }
    
    stringstream stream;
    string data;
    bool emptyStream = true;
    for (string data : table) {

        // Skip or replace if there's no data.
        if (data == "") {
            if (!showEmpty) { continue; }
            data = "__";  // Visual indication of blank space.
        }

        // Unless this is the first item to print, add delimiter.
        if (!emptyStream) {
            stream << ", ";
        }

        stream << data;
        emptyStream = false;
    }

    return stream.str();
}

void Hashtable::insert(string data) {
    int idx;
    try {
        idx = findIndexOf(data, EMPTY);
    } catch (DataNotFound) { // If I can't find an empty space, the table is full.
        throw FullTableError(); // Translate DataNotFound to FullTableError, for coherency.
    }
    
    ++size;
    table[idx] = data;
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
    int idx;
    idx = findIndexOf(data, data);

    // Empty and return.
    string value = table[idx];
    table[idx] = EMPTY;
    --size;
    return value;
}

bool Hashtable::search(string data) {
    try {
        findIndexOf(data, data);
    } catch (DataNotFound) {
        return false;
    }
    return true;
}
