#include <iostream>

#include <string>
#include "linked_queue.h"

using namespace std;


string EmptyQueueError::what() {
    return "Queue is empty: cannot peek or dequeue";
}


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
    Node* previous = frontPtr;
    int value = previous->value;

    frontPtr = previous->next;
    delete previous;

    _length --;

    if (isEmpty()) {
        frontPtr = nullptr;
        backPtr = nullptr;
    }

    return value;
}


void LinkedQueue::enqueue(int newValue) {
    Node* newNode = new Node{newValue, nullptr};

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
