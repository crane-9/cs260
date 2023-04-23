#include <string>

#include "queue_errors.h"
#include "array_queue.h"

using namespace std;


ArrayQueue::ArrayQueue() {
    // Queue is empty by default.
    _isEmpty = true;
    _isFull = false;

    // Front and tail both at 0.
    frontIndex = tailIndex = 0;
}

int ArrayQueue::advanceIndex(int idx) {
    idx ++;

    if (idx == CAPACITY) { return 0; }
    else { return idx; }
}

int ArrayQueue::dequeue() {
    // Pre-condition 
    if (_isEmpty) { throw EmptyQueueError(); }
    
    // Not full anymore.
    if (_isFull) { _isFull = false; } 
    
    // Actually dequeue.
    int value = items[frontIndex];
    frontIndex = advanceIndex(frontIndex);

    // If the front catches up to the back, queue is now empty.
    if (frontIndex == tailIndex) { _isEmpty = true; }

    return value;
}


void ArrayQueue::enqueue(int value) {
    //Pre-condition.
    if (_isFull) { throw FullQueueError(); }
    
    // Not empty anymore.
    if (_isEmpty) { _isEmpty = false; } 
    
    // Actually enqueue.
    items[tailIndex] = value;
    tailIndex = advanceIndex(tailIndex);

    // If tail == front, the queue is now full. 
    if (tailIndex == frontIndex) { _isFull = true; }
}


int ArrayQueue::peek() {
    // Pre-condition.
    if (_isEmpty) { throw EmptyQueueError(); }
    
    return items[frontIndex];
}


int ArrayQueue::length() {
    // Two easy answers:
    if (_isEmpty) { return 0; }
    else if (_isFull) { return CAPACITY; } 
    
    // Otherwise, calculate:
    if (tailIndex < frontIndex) {
        return tailIndex + CAPACITY - frontIndex;
    } 
    else { return tailIndex - frontIndex; }
}
