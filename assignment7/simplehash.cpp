#include <iostream>
#include <sstream>
#include <string>

#include "error.h"
#include "simplehash.h"

using std::string, std::stringstream;


SimpleHash::SimpleHash() {
    size = 0;
}

SimpleHash::~SimpleHash() {
    delete [] &table;
}

int SimpleHash::hash(string data) {
    int value;

    for (char i : data) {
        value += i;
    }

    return value % capacity;
}

string SimpleHash::display(const bool showEmpty) {
    // Guard claus--save the effort.
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

void SimpleHash::insert(string data) {
    int idx = hash(data);

    // THIS OVERWRITES RIGHT NOW!
    table[idx] = data;
    ++size;
}

string SimpleHash::position(int index) {
    if (index >= capacity) { 
        throw DataNotFound("Index " + std::to_string(index));
    }
    
    // safe :)
    return table[index];
}

string SimpleHash::remove(string data) {
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

bool SimpleHash::search(string data) {
    int idx = hash(data);
    string value = table[idx];

    return value == data;
}
