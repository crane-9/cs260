#include <iostream>
#include <string>
#include <sstream>

#include "may19.h"

using namespace std;


Hashtable::Hashtable(int initCapacity) {
    capacity = initCapacity;
    size = 0;

    values = new string[capacity];
}

Hashtable::~Hashtable() {
    delete[] values;
}

int Hashtable::hash(string key) {
    int result = 0;

    for (char letter : key) {
        result += letter;
    }

    return result % capacity;
}

string Hashtable::access(int position) {

}

int Hashtable::add(string newValue) {
    int idx = hash(newValue);
    values[idx] = newValue;

    ++size;
    return 0;
}

string Hashtable::find(string value) {
    int idx = hash(value);
    string result = values[idx];

    // check that it is as expected? otherwise a collisiosn or whatdever. ogh.
    return result;
}

string Hashtable::remove(string value) {
    int idx = hash(value);

    if (values[idx] != value && values[idx] != "") {
        return "collision!";
    }

    string result = values[idx];
    values[idx] = "";
    
    --size;
    return result;
}

