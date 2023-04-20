#include "array_queue.h"

#include <sstream>
#include <string>
#include <iostream>

using namespace std;


string singleTest() {
    int testValue = 2;
    ArrayQueue testQueue;

    testQueue.enqueue(testValue);

    int value = testQueue.dequeue();
    if (value == testValue) {
        return "SUCCESS Returned expected value.";
    }
    stringstream message;
    message << "FAILED returned unexpected value: " << value;

    return message.str();
}


/**
 * Places three known values in the queue, and retrieves them.
 * 
 * @return Pass/fail message.
*/
string tripleTest() {
    ArrayQueue testQueue;

    testQueue.enqueue(1);
    testQueue.enqueue(2);
    testQueue.enqueue(3);

    bool trialOne, trialTwo, trialThree;

    try {
        trialOne = testQueue.dequeue() == 1;
        trialTwo = testQueue.dequeue() == 2;
        trialThree = testQueue.dequeue() == 3;
    } catch (EmptyQueueError) {
        return "FAILED Dequeue threw error.";
    }

    if (trialOne and trialTwo and trialThree) {
        return "SUCCESS Three values queued and retrieved as expected.";
    }

    stringstream message;
    message << "FAILED Not all values enqueued were retrieved as expected.";

    // Provide details. None are mutually exclusive, hence "if, if, if".
    if (!trialOne) {
        message << " First dequeue failed.";
    }
    if (!trialTwo) {
        message << " Second dequeue failed.";
    }
    if (!trialThree) {
        message << " Third dequeue failed.";
    }

    return message.str();
}


string emptyTest() {
    ArrayQueue testQueue;

    int mysteryValue;
    try {
        mysteryValue = testQueue.dequeue();
    } catch (EmptyQueueError e) {
        return "SUCCESS Dequeuing empty queue raised the appropriate error.";
    }

    stringstream message;
    message << "FAILURE Dequeuing empty queue returned: " << mysteryValue; 

    return message.str();
}


string fullTest() {
    ArrayQueue testQueue;

    for (int i = 1; testQueue.length() < 10; i++) {
        testQueue.enqueue(i^2);
    }

    try {
        testQueue.enqueue(9);
    } catch (FullQueueError) {
        return "SUCCESS FullQueueError thrown.";
    }

    return "FAIL FullQueueError not thrown.";
}


string lengthTest() {
    ArrayQueue testQueue;

    // Flag to check after loops.
    bool failed = false;

    // Test that length grows.
    for (int i = 0; i < 10; i++) {
        if (testQueue.length() != i) {
            failed = true;
            break;
        }
        testQueue.enqueue(i * 3);
    }

    if (failed) {
        return "FAILED .length() did not return as expected during repeated enqueuing.";
    } 

    // Test that length shrinks.
    for (int i = testQueue.length(); i > 0; i--) {
        if (testQueue.length() != i) {
            failed = true;
            break;
        }
        testQueue.dequeue();
    }
    
    if (failed) {
        return "FAILED .length() did not return as expected during dequeuing.";
    } else {
        return "SUCCESS .length() behaved as expected.";
    }
}


string peekTest() {
    ArrayQueue testQueue;
    int testValue = 9;

    testQueue.enqueue(testValue);

    bool trialOne, trialTwo;

    try {
    trialOne = testQueue.peek() == testValue;  // Is the value as expected?
    } catch (EmptyQueueError) {
        return "FAILED .peek() threw EmptyQueueError: .enqueue() may have failed.";
    }

    trialTwo = testQueue.length() == 1;  // Is the queue still populated?

    if (trialOne and trialTwo) {
        return "SUCCESS .peek() returned expected value and did not altered length.";
    } else {
        return "FAILED .peek() did not return expected value and/or altered length.";
    }
}


string wiggleTest() {
    ArrayQueue testQueue;

    // Enqueue 4
    for (int i = 1; i < 5; i ++) {
        testQueue.enqueue(i);
    }

    // Dequeue 1
    cout << testQueue.dequeue() << endl;

    // Enqueue 2
    for (int i = 1; i < 3; i++) {
        testQueue.enqueue(i);
    }

    // Dequeue 3
    for (int i = 1; i < 4; i++) {
        cout << testQueue.dequeue() << endl;
    }

    // Enqueue 1
    testQueue.enqueue(1);

    // Dequeue until empty
    while (!testQueue.isEmpty()) {
        cout << testQueue.dequeue() << endl;
    }

    return "presumably SUCCESS!";  // dynamic message needed
}


int main() {
    cout << singleTest() << endl;
    cout << tripleTest() << endl;
    cout << emptyTest() << endl;
    cout << fullTest() << endl;
    cout << lengthTest() << endl;
    cout << peekTest() << endl;
    cout << wiggleTest() << endl;

    return 0;
}
