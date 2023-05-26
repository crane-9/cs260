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

int Hashtable::hash1(string data) {
    int value;

    for (char i : data) {
        value += i;
    }
    return value;
}

int Hashtable::hash2(string data) {

}

int Hashtable::doubleHash(string data) {
    int value; // Eventual return value.

    int h1 = hash1(data);
    int h2 = hash2(data);

    int i = 0;
    do {
        value = (h1 + i * h2) % capacity;
        ++i;
    } while (table[value] != "" || table[value] != data); // this doesn't work actually, as the condition changes between insert and search/remove. hm
    // also what about when `i` leaves valid table range?

    return value;
}

string Hashtable::display(const bool showEmpty) {
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

void Hashtable::insert(string data) {
    int idx = doubleHash(data);

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
    int idx = doubleHash(data);
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
    int idx = doubleHash(data);
    string value = table[idx];

    return value == data;
}
