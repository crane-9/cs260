#include <iostream>
#include <string>

#include "hashtable.h"

using std::cout, std::endl, std::string;


DataNotFound::DataNotFound(string data) {
    hint = data;
}

string DataNotFound::what() {
    return "'" + hint + "' was not found in the hashtable.";
}


Hashtable::Hashtable() {
    size = 0;
}

Hashtable::~Hashtable() {
    delete table;
}

int Hashtable::hash(string data) {
    int value;

    for (char i : data) {
        value += i;
    }

    return value % capacity;
}

void Hashtable::display() {
    for (string data : table) {
        cout << data;
    }
    cout << endl;
}

void Hashtable::insert(string data) {
    int idx = hash(data);

    // THIS OVERWRITES RIGHT NOW!
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
    int idx = hash(data);

    string value = table[idx];

    if (value != data) {
        throw DataNotFound(data);
    }

    table[idx] = EMPTY;

    return value;
}

bool Hashtable::search(string data) {
    int idx = hash(data);
    string value = table[idx];

    return value == data;
}
