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


string doubleTest() {
    int valueOne = 7; int valueTwo = 3;
    LinkedQueue testQueue;

    testQueue.enqueue(valueOne);
    testQueue.enqueue(valueTwo);
    cout << testQueue.dequeue() << endl;

    cout << testQueue.length() << endl;

    cout << testQueue.dequeue() << endl;

    return " who knows!";

}


/**
 * Places three known values in the queue, and retrieves them.
 * 
 * @return Fail/success message.
*/
string basicQueueTest() {
    LinkedQueue testQueue;

    testQueue.enqueue(1);
    testQueue.enqueue(2);
    testQueue.enqueue(3);

    int result;
    try {
        result = testQueue.dequeue();
    } catch (exception e) {
        return e.what();
    }
    return "bruh";
    // bool trialOne, trialTwo, trialThree;

    // trialOne = testQueue.dequeue() == 1;
    // trialTwo = testQueue.dequeue() == 2;
    // trialThree = testQueue.dequeue() == 3;

    // if (trialOne, trialTwo, trialThree) {
    //     return "ALL trials succeeded!";
    // } else {
    //     return "Uh ohOh";
    // }
}


string threeTest() {
    // LinkedQueue testQueue;

    // for (int i = 4; i < 40; i += 3) {
    //     testQueue.enqueue(i);
    // }

    // cout << testQueue.length() << endl;


    // while (!testQueue.isEmpty()) {
    //     try {
    //         cout << testQueue.dequeue() << endl;
    //     } catch (EmptyQueueError) {
    //         cout << "uh oh. queue length? " << testQueue.length() << endl;
    //         break;
    //     }
    // }
    return "not implemented, ding dong";
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
    cout << emptyTest() << endl;
    cout << doubleTest() << endl;
    // cout << basicQueueTest() << endl;

    return 0;
}
