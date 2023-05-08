#include <iostream>
#include <sstream>
#include <string>

#include "autosort_list.h"

using namespace std;


/// @brief Inserts values in a scrambled order, then tests that output is as expected.
/// @return Pass/fail status.
string insertTest() {
    AutoList testList;
    const string expectedOutput = "[5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24]";

    for (int i = 10; i < 20; i ++) {
        testList.insert(i + 5);
        testList.insert(i - 5);
    }

    if (testList.toString() == expectedOutput) {
        return "PASSED Values were sorted appropriately on insert";
    } else {
        return "FAILED Values were not sorted as expected.";
    }
}


/// @brief Tests that value searching works as expected.
/// @return Pass/fail message.
string indexTest() {
    AutoList testList;

    // Insert 19 values, where the value is always 1 more than the position. Ex: idx 1 == 2.
    for (int i = 1; i < 20; i++) {
        testList.insert(i);
    }

    bool testOne = testList.index(1) == 0;
    bool testTwo = testList.index(10) == 9;
    bool testThree = testList.index(19) == 18;

    if (testOne && testTwo && testThree) {
        return "PASSED Value searching with .index() works as expected for the beginning, middle, and end of a list.";
    } else {
        return "FAILED Value searching with .index() does not work as it should.";
    }
}


/// @brief Tests that removing a value works as expected. Also tests ValueNotFoundError.
/// @return Pass/fail message.
string removeTest() {
    AutoList testList;

    // Insert values 0 - 9. Value == position.
    for (int i = 0; i < 10; i++) {
        testList.insert(i);
    }

    int removedValue = testList.remove(5);

    int mysteryValue;
    try {
        mysteryValue = testList.index(5);
    } catch (ValueNotFoundError e) {  // Test passes!
        return "PASSED Value was removed from list successfully. ValueNotFoundError caught.";
    } 

    // Test failed.
    stringstream message;
    message << "FAILED Value was found on the list at position " << mysteryValue << " after intended removal.";
    return message.str();
}


int main() {
    cout << insertTest() << endl;
    cout << indexTest() << endl;
    cout << removeTest() << endl;
    
    return 0;
}