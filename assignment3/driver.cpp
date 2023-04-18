#include <iostream>
#include <string>

#include "queue.h"

using namespace std;


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


int main() {
    cout << basicQueueTest() << endl;

    return 0;
}
