// EVIL EXPERIMENTAL DRIVER!!!!!!!!!!!!!
#include "array_queue.h"
#include "linked_queue.h"
#include "queue_errors.h"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;


/**
 * Tests a single value in and out of a queue.
 * 
 * @return Pass/fail message
*/
template<class Queue>
string singleTest() {
    Queue testQueue;
    int testValue = 5;

    testQueue.enqueue(testValue);

    int value;

    try {
        value = testQueue.dequeue();
    } catch (EmptyQueueError) {
        return "FAILED Dequeue failed, threw EmptyQueueError.";
    }

    if (value == testValue) {
        return "SUCCESS Dequeue returned desired test value.";
    } else {
        stringstream message;
        message << "FAILED Dequeue returned " << value << " instead of desired value: " << testValue;
        return message.str();
    }
}

/**
 * Places three known values in the queue, and retrieves them.
 * 
 * @return Pass/fail message.
*/
template <class Queue>
string tripleTest() {
    Queue testQueue;

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


/**
 * Tests EmptyQueueError and catching it.
 * @return Pass/Fail message.
*/
template <class Queue>
string emptyTest() {
    Queue testQueue;

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
template <class Queue>
string lengthTest() {
    Queue testQueue;

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


/**
 * Test that .peek() acts as expected.
 * @return Pass/Fail message.
*/
template <class Queue>
string peekTest() {
    Queue testQueue;
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


/**
 * Test a handful of queue states.
 * @return Pass/Fail message.
*/
template <class Queue>
string wiggleTest() {
    Queue testQueue;

    bool test;

    // Enqueue 4
    for (int i = 1; i < 5; i ++) {
        testQueue.enqueue(i);
    }

    // Dequeue 1
    testQueue.dequeue();

    // Enqueue 2
    for (int i = 1; i < 3; i++) {
        testQueue.enqueue(i);
    }

    // Dequeue 3
    for (int i = 1; i < 4; i++) {
        testQueue.dequeue();
    }

    // Enqueue 1
    testQueue.enqueue(1);

    // Dequeue until empty
    while (!testQueue.isEmpty()) {
        testQueue.dequeue();
    }

    return "SUCCESS Queue survived a series of enqueuing and dequeueing.";  // dynamic message needed
}

// Array-queue test ONLY
string fullTest() {
    ArrayQueue testQueue;

    for (int i = 1; testQueue.length() < 10; i++) {
        testQueue.enqueue(i^2);
    }

    try {
        testQueue.enqueue(9);
    } catch (FullQueueError) {
        return "SUCCESS FullQueueError thrown at the appropriate time.";
    }

    return "FAIL FullQueueError not thrown.";
}


// run all tests for a given class
template <class Queue>
void runTests(string queueName) {
    cout << queueName << ":" << endl;
    cout << "\t" << singleTest<Queue>() << endl;
    cout << "\t" << tripleTest<Queue>() << endl;
    cout << "\t" << emptyTest<Queue>() << endl;   
    cout << "\t" << lengthTest<Queue>() << endl;
    cout << "\t" << peekTest<Queue>() << endl;
    cout << "\t" << wiggleTest<Queue>() << endl;

    if (is_same<Queue, ArrayQueue>::value) {
        cout << "\t" << fullTest() << endl;
    }
    
    cout << endl;
}


int main(int argc, char* argv[]) {
    runTests<LinkedQueue>("LINKED QUEUE");
    runTests<ArrayQueue>("ARRAY QUEUE");

    return 0;
}
