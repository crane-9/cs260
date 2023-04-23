#include "linked_list.h"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;


string appendTest() {
    LinkedList testList;

    for (int i = 0; i < 10; i ++) {
        testList.append(i);
    }

    return testList.peek();
}


string countTest() {
    // Add values

    // Count a known value.

    // yaaay
}


string getTest() {
    LinkedList testList;
    
    testList.append(4);
    testList.append(5);
    testList.append(6);

    int beforeLength = testList.length();

    bool testGet = testList.get(1) == 5;
    bool testLength = beforeLength == testList.length();

    if (testGet && testLength) {
        return "SUCCESS .get() returns expected value, and does not alter list length.";
    } else if (testGet) {
        return "FAILED .get() returns expected value, but alters list length.";
    } else {
        return "FAILED .get() does not return expected value."; 
    } // maybe make these more dynamic?
}


string indexTest() {
    // populate list

    // get a known index

    // compare, return
}


string insertTest() {
    // Add a couple items to a list.

    // Get length.

    // Insert in the middle of the list

    // Get index, check value.

    // Check length.

}


string popTest() {
    // Add a bunch of items to a list.

    // Get length.

    // Pop an index and check for expected value.

    // Compare new length.

}


string replaceTest() {
    // Add a bunch of items to a list.

    // Get length.

    // Replace a known index with a new known value.

    // Get known index and check the value matches.

    // Compare length.

}


int main() {
    cout << appendTest() << endl;
    cout << countTest() << endl;
    cout << getTest() << endl;
    cout << indexTest() << endl;
    cout << insertTest() << endl;
    cout << popTest() << endl;
    cout << replaceTest() << endl;

    return 0;
}
