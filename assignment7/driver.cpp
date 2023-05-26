#include <iostream>
#include <sstream>
#include <string>

#include "simplehash.h"

using namespace std;


/**
 * Returns error debug message with table's contents.
 * @param ht The relevant hashtable.
 * @param info Debug message.
 * @return Error message with the given message and table contents. 
*/
string failDebugMessage(SimpleHash *ht, string info) {
    stringstream message;

    message << "FAILED " << info << " ";
    message << "Table.display(): '" << ht->display() << "'";

    return message.str();
}


/// @brief Tests insertion, returns pass/fail message.
string insertionTest(SimpleHash *ht) {
    ht->insert("broccoli");
    ht->insert("tomato");

    if (ht->display() == "tomato, broccoli") {
        return "PASSED Success inserting 'broccoli' and 'tomato' into table";
    }
    return failDebugMessage(ht, "Insertion not as expected.");
}

/// @brief Tests search, returns pass/fail message. 
string searchTest(SimpleHash *ht) {
    if (ht->search("tomato")) {
        return "PASSED Tomato on the table.";
    }
    return failDebugMessage(ht, "Tomato not on the table.");
}

/// @brief Tests removal, returns pass/fail message. 
string removalTest(SimpleHash *ht) {
    ht->remove("broccoli");
    try {
        ht->remove("broccoli");
    } catch (DataNotFound) {
        return "PASSED Removal method behaves as expected.";
    }
    return failDebugMessage(ht, "Removal method does not remove and/or raise error on invalid input.");
}

/// @brief Tests get by position, returns pass/fail message. 
string positionTest(SimpleHash *ht) {
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
string anagramTest(SimpleHash *ht) {
    string anagrams[] = {"points", "pinots", "piston"};
    
    stringstream message;
    
    message << "Initial: " << ht->display() << "\n";

    for (string word : anagrams) {
        ht->insert(word);
        message << "After '" << word << "': " << ht->display(true) << "\n";
    }
    
    return message.str();
}


int main() {
    SimpleHash *table = new SimpleHash;

    cout << insertionTest(table) << endl;
    cout << searchTest(table) << endl;
    cout << removalTest(table) << endl;
    cout << positionTest(table) << endl;

    cout << anagramTest(table) << endl;

    return 0;
}
