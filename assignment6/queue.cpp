// Adapted from assignment 3.

#include <iostream>
#include <string>

#include "binary_tree.h"

#include "queue.h"

using namespace std;


string EmptyQueueError::what() { return "Queue is empty, cannot dequeue or peek. "; }


LinkedQueue::LinkedQueue() {
    frontPtr = nullptr;
    backPtr = nullptr;
    _length = 0;
}


Node *LinkedQueue::dequeue() {
    if (isEmpty()) {
        throw EmptyQueueError(); 
    }

    // Retrieve data, set new front node.
    QueueNode<Node *> *oldNode = frontPtr;
    Node *data = oldNode->data;

    frontPtr = oldNode->next;
    delete oldNode;

    _length --;

    if (isEmpty()) {
        frontPtr = nullptr;
        backPtr = nullptr;
    }

    return data;
}


void LinkedQueue::enqueue(Node *newData) {
    QueueNode<Node *> *newNode = new QueueNode<Node *>{newData, nullptr};

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


Node *LinkedQueue::peek() {
    if (isEmpty()) {
        throw EmptyQueueError();        
    }

    return frontPtr->data; 
}
