#include "linked_list.h"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;


string appendTest() {
    LinkedList testList;

    // Populate list.
    for (int i = 0; i < 4; i ++) {
        testList.append(i);
    }

    // Test a known value.
    int testValue = 9;
    testList.append(testValue);

    // Peek at the end of the list.
    int endIdx = testList.length() - 1;

    bool check = testValue == testList.get(endIdx);

    if (check) {
        return "SUCCESS Appending a value adds to the back of the list.";
    } else {
        stringstream message;
        message << "FAILED Appending a value does not behave as expected: ";

        // Debug message.
        int testValueIdx = testList.index(testValue);

        if (testValueIdx != -1) {
            message << "test value was found at index " << testValueIdx;
        } else {
            message << "test value was not found on the list.";
        }

        return message.str();
    }
}


string countTest() {
    const int knownValue = 63;
    const int knownAmount = 6;
    
    LinkedList testList;
    
    // Add an assortment of values, a range that I know doesn't include 63.
    for (int i = 0; i < knownAmount; i++) {
        testList.append(i);
    }

    // Add a given amount of a known value.
    for (int i = 0; i < knownAmount; i++) {
        testList.append(knownValue);
    }

    // Count.
    int count = testList.count(knownValue);

    if (count == knownAmount) {
        return "SUCCESS Counting a value behaves as expected.";
    } else {
        stringstream message;

        message << "FAILED The test value was counted " << count << " times, out of the expected " << knownAmount;

        return message.str();
    }
}


string getTest() {
    LinkedList testList;
    
    // Hard-coding certain values
    testList.append(4);
    testList.append(5);
    testList.append(6);

    int beforeLength = testList.length();

    // Hard-coded expected value.
    bool testGet = testList.get(1) == 5;
    bool testLength = beforeLength == testList.length();

    if (testGet && testLength) {
        return "SUCCESS .get() returns expected value, and does not alter list length.";
    } else if (testGet) {
        return "FAILED .get() returns expected value, but alters list length.";
    } else {
        return "FAILED .get() does not return expected value."; 
    }
}


string indexTest() {
    LinkedList testList;

    // Populate
    for (int i = 0; i < 10; i++) {
        testList.append(i);
    }

    // Define testing variables.
    int testIdx = 4;
    int testValue = 34;

    testList.insert(testIdx, testValue);

    int resultIdx = testList.index(testValue);

    if (resultIdx == testIdx) {
        return "SUCCESS Getting the index of a known value behaved as expected.";
    } else {
        stringstream message;

        message << "FAILED ";

        if (resultIdx == -1) {
            message << "The test value was not found on the list.";
        } else {
            message << "The test value was found at index " << resultIdx << " instead of index " << testIdx;
        }

        return message.str();
    }
}


string insertTest() {
    LinkedList testList;

    // Add a couple items to a list.
    for (int i = 0; i < 5; i ++) {
        testList.append(i);
    }

    int knownIndex = 2;
    int knownValue = 9;

    // Insert in the middle of the list
    testList.insert(knownIndex, knownValue);

    // Get and check value.
    int result = testList.get(knownIndex);

    if (result == knownValue) {
        return "SUCCESS Value was inserted into the list as expected.";
    } else {
        stringstream message;
        message << "FAILED Value not found. " << result << " found instead of " << knownValue;

        return message.str();
    }
}


string popTest() {
    // Add a bunch of items to a list.
    LinkedList testList;
    
    // Hard-coding certain values
    testList.append(4);
    testList.append(5);
    testList.append(6);

    int beforeLength = testList.length();

    // Hard-coded expected value.
    int popResult = testList.pop(1);

    if (popResult == 5) {
        stringstream message;
        message << "SUCCESS Expected value returned when popped, ";

        if (beforeLength == testList.length() - 1) {
            message << "and removed from list as expected.";
        } else {
            message << "HOWEVER it was not removed from the list.";
        }

        return message.str();
    } else {
        return "FAILED Expected value not returned from pop.";
    }
}


string replaceTest() {
    const int knownIndex = 3;
    const int knownValue = 16;

    LinkedList testList;

    // Add a bunch of items to a list.
    

    // Get length.

    // Replace a known index with a new known value.

    // Get known index and check the value matches.

    // Compare length.

    return "";

}


string indexErrorTest() {
    LinkedList testList;

    const int testLength = 4;

    for (int i = 0; i < testLength; i++) {
        testList.append(i ^ 2);
    }

    int mysteryValue;

    try {
        mysteryValue = testList.get(testLength + 1);
    } catch (IndexError) {
        return "SUCCESS Index error thrown as expected.";
    }

    // No error is not what we want.
    stringstream message;
    message << "FAILED Index error not thrown as expected. " << mysteryValue << " returned.";
    return message.str();
}


int main() {
    cout << appendTest() << endl;
    cout << countTest() << endl;
    cout << getTest() << endl;
    cout << indexTest() << endl;
    cout << insertTest() << endl;
    cout << popTest() << endl;
    cout << replaceTest() << endl;
    cout << indexErrorTest() << endl;

    return 0;
}
