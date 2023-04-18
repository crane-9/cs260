#include <iostream>

#include <string>
#include "queue.h"

using namespace std;


string EmptyQueueError::what() {
    return "Queue is empty: cannot peek or dequeue";
}


LinkedQueue::LinkedQueue() {
    frontNode = nullptr;
    backNode = nullptr;
    _length = 0;
}


int LinkedQueue::dequeue() {
    if (isEmpty()) {
        throw EmptyQueueError(); 
    }

    // Retrieve value, set new front node.
    int value = frontNode->value;

    cout << value << endl;
    frontNode = frontNode->next;

    _length --;

    return value;
}


void LinkedQueue::enqueue(int newValue) {
    Node newNode;
    newNode.value = newValue;
    newNode.next = nullptr;

    if (isEmpty()) {
        // In a queue of one, the front and back are the same.
        frontNode = &newNode;
        backNode = &newNode; 
    } else {
        // The end of the queue references the new node.
        backNode->next = &newNode;

        // New end of the queue.
        backNode = &newNode;
    }

    _length ++;
}


int LinkedQueue::peek() {
    if (isEmpty()) {
        throw EmptyQueueError();        
    }
    return frontNode->value; 
}
