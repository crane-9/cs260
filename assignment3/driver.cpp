#include <iostream>
#include <sstream>
#include <string>

#include "queue.h"

using namespace std;

/**
 * Tests a single value in and out of a queue.
 * 
 * @return Success/fail message
*/
string singleTest() {
    int testValue = 5;
    LinkedQueue testQueue;

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
 * @return Fail/success message.
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


/// @brief Tests EmptyQueueError
string emptyTest() {
    LinkedQueue testQueue;

    int mysteryValue;
    try {
        mysteryValue = testQueue.dequeue();
    } catch (EmptyQueueError e) {
        return "SUCCESS Dequeuing empty queue raised the appropriate error.";
    }

    stringstream message;

    message << "FAILURE Dequeuing empty queue was fine. Returned: " << mysteryValue; 

    return message.str();

}


int main() {
    cout << singleTest() << endl;
    cout << tripleTest() << endl;
    cout << emptyTest() << endl;

    return 0;
}
