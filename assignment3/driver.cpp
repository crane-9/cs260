#include <iostream>
#include <sstream>
#include <string>

#include "queue.h"

using namespace std;


/**
 * Tests a single value in and out of a queue.
 * 
 * @return Pass/fail message
*/
string singleTest() {
    LinkedQueue testQueue;
    int testValue = 5;

    testQueue.enqueue(testValue);

    int value = testQueue.dequeue();

    if (value == testValue) {
        return "SUCCESS Dequeue returned desired test value.";
    } else {
        stringstream message;
        message << "FAILURE Dequeue returned: " << value;
        return message.str();
    }
}


/**
 * Places three known values in the queue, and retrieves them.
 * 
 * @return Pass/fail message.
*/
string tripleTest() {
    LinkedQueue testQueue;

    testQueue.enqueue(1);
    testQueue.enqueue(2);
    testQueue.enqueue(3);

    bool trialOne, trialTwo, trialThree;

    trialOne = testQueue.dequeue() == 1;
    trialTwo = testQueue.dequeue() == 2;
    trialThree = testQueue.dequeue() == 3;

    if (trialOne and trialTwo and trialThree) {
        return "SUCCESS Three values queued and retrieved as expected.";
    } else {
        return "FAILURE Not all values enqueued were retrieved as expected.";
        // give more info!
    }
}


/**
 * Tests EmptyQueueError and catching it.
 * @return Pass/Fail message.
*/
string emptyTest() {
    LinkedQueue testQueue;

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


/**
 * Test the length attribute's accuracy.
 * @return Pass/Fail message.
*/
string lengthTest() {
    LinkedQueue testQueue;

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
        return "PASSED .length() behaved as expected.";
    }

}


/**
 * Test that .peek() acts as expected.
 * @return Pass/Fail message.
*/
string peekTest() {
    LinkedQueue testQueue;
    int testValue = 9;

    testQueue.enqueue(testValue);

    bool trialOne, trialTwo;

    trialOne = testQueue.peek() == testValue;  // Is the value as expected?
    trialTwo = testQueue.length() == 1;  // Is the queue still populated?

    if (trialOne and trialTwo) {
        return "SUCCESS peek() returned expected value and did not altered length.";
    } else {
        return "FAIL peek() did not return expected value and/or altered length.";
    }

}


/**
 * Test a handful of queue states.
 * @return Pass/Fail message.
*/
string wiggleTest() {
    LinkedQueue testQueue;

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

    return "presumably passed!";  // dynamic message needed
}


int main() {
    cout << singleTest() << endl;
    cout << tripleTest() << endl;
    cout << emptyTest() << endl;
    cout << lengthTest() << endl;
    cout << peekTest() << endl;
    cout << wiggleTest() << endl;

    return 0;
}
