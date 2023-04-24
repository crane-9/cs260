#include <iostream>
#include <string>

#include "queue_errors.h"
#include "linked_queue.h"

using namespace std;


LinkedQueue::LinkedQueue() {
    frontPtr = nullptr;
    backPtr = nullptr;
    _length = 0;
}


int LinkedQueue::dequeue() {
    if (isEmpty()) {
        throw EmptyQueueError(); 
    }

    // Retrieve value, set new front node.
    Node<int>* oldNode = frontPtr;
    int value = oldNode->value;

    frontPtr = oldNode->next;
    delete oldNode;

    _length --;

    if (isEmpty()) {
        frontPtr = nullptr;
        backPtr = nullptr;
    }

    return value;
}


void LinkedQueue::enqueue(int newValue) {
    Node<int>* newNode = new Node<int>{newValue, nullptr};

    if (isEmpty()) {
        // In a queue of one, the front and back are the same.
        frontPtr = backPtr = newNode; 
    } else {
        // The end of the queue references the new node.
        backPtr->next = newNode;

        // New end of the queue.
        backPtr = newNode;
    }

    _length ++;
}


int LinkedQueue::peek() {
    if (isEmpty()) {
        throw EmptyQueueError();        
    }
    return frontPtr->value; 
}
