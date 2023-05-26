#include <iostream>
#include <sstream>
#include <string>

#include "error.h"
#include "hashtable.h"
#include "simplehash.h"

using namespace std;


/**
 * Returns error debug message with table's contents.
 * @param ht The relevant hashtable.
 * @param info Debug message.
 * @return Error message with the given message and table contents. 
*/
template <typename T>
string failDebugMessage(T *ht, string info) {
    stringstream message;

    message << "FAILED " << info << " ";
    message << "Table.display(): '" << ht->display() << "'";

    return message.str();
}


/// @brief Tests insertion, returns pass/fail message.
template <typename T>
string insertionTest(T *ht) {
    ht->insert("broccoli");
    ht->insert("tomato");

    if (ht->display() == "tomato, broccoli") {
        return "PASSED Success inserting 'broccoli' and 'tomato' into table";
    }
    return failDebugMessage(ht, "Insertion not as expected.");
}

/// @brief Tests search, returns pass/fail message. 
template <typename T>
string searchTest(T *ht) {
    if (ht->search("tomato")) {
        return "PASSED Tomato on the table.";
    }
    return failDebugMessage(ht, "Tomato not on the table.");
}

/// @brief Tests removal, returns pass/fail message. 
template <typename T>
string removalTest(T *ht) {
    ht->remove("broccoli");
    try {
        ht->remove("broccoli");
    } catch (DataNotFound) {
        return "PASSED Removal method behaves as expected.";
    }
    return failDebugMessage(ht, "Removal method does not remove and/or raise error on invalid input.");
}

/// @brief Tests get by position, returns pass/fail message. 
template <typename T>
string positionTest(T *ht) {
    bool test;
    try {
        test = ht->position(4) == "tomato";
    } catch (DataNotFound error) {
        return "FAILED " + error.what();
    }

    if (test) {
        return "PASSED Expected value retrieved with Table.position()";
    }
    return failDebugMessage(ht, "Position method not behaving as expected.");
}

/// @brief Tests collisions using anagrams. 
template <typename T>
string anagramTest(T *ht) {
    string anagrams[] = {"points", "pinots", "piston"};
    
    stringstream message;
    
    message << "Initial: " << ht->display(true) << "\n";

    for (string word : anagrams) {
        ht->insert(word);
        message << "After '" << word << "': " << ht->display(true) << "\n";
    }
    
    return message.str();
}


/// @brief Tests SimpleHash class.
void testSimpleHash() {
    SimpleHash *table = new SimpleHash;

    cout << "! SIMPLE HASH TESTS:" << endl;

    cout << insertionTest(table) << endl;
    cout << searchTest(table) << endl;
    cout << removalTest(table) << endl;
    cout << positionTest(table) << endl;

    cout << anagramTest(table) << endl;
}


/// @brief Tests doublehashing, Hashtable class.
void testDoubleHash() {
    Hashtable *table = new Hashtable;

    cout << "! DOUBLE HASH TESTS:" << endl;

    cout << insertionTest(table) << endl;
    cout << searchTest(table) << endl;
    cout << removalTest(table) << endl;
    cout << positionTest(table) << endl;

    cout << anagramTest(table) << endl;
}

int main() {
    testSimpleHash();
    testDoubleHash();

    return 0;
}
