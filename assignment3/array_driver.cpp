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
        return "PASSED Returned expected value.";
    }
    stringstream message;
    message << "FAILED returned unexpected value: " << value;

    return message.str();
}


int main() {
    cout << singleTest() << endl;

    return 0;
}
