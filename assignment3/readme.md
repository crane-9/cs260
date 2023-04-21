# CS 260: Assignment 3: Linked-list Queue and Array Queue Design


### Shortcuts
* [Linked Queue Design](#linked-queue)
* [Array Queue Design](#array-queue)
* [Tests](#tests)
* [Complexity Analysis](#complexity-analysis)
* [Guidelines Fulfilled](#guidelines-fulfilled)


### Summary

This README contains documentation for two separate queue designs: a linked queue and a bonus array queue. Each queue design has its own chapter of documentation, and a clearly named `.h` and `.cpp` file. They share an error file, `queue_errors.h`, and a driver file, `driver.cpp`.


---
## Linked Queue

A queue will keep track of the nodes at the front and back of the queue, as well as the total length of the queue. The length attribute will assist in the pre-conditions for `dequeue()`, `enqueue()`, and `peek()`.

### Attributes
| Scope      | Definition              | Purpose                              |
|------------|-------------------------|--------------------------------------|
| Private    | `Node* backPtr`         | Pointer to the end of the line.
| Private    | `Node* frontPtr`        | Pointer to the front of the line.    
| Private    | `int _length`           | Counts every value in line.

### Methods
| Scope      | Definition              | Purpose                              |
|------------|-------------------------|--------------------------------------|
| Public     | `int dequeue()`         | Get the next at the front of the line.
| Public     | `void enqueue(int)`     | Add a new value to the back of the line.
| Public     | `bool isEmpty()`        | Check if the queue is empty.
| Public     | `int peek()`            | Peek at the front of the line.
| Public     | `int length()`          | Read-only length of the queue.

## Nodes

Nodes are a simple structure, consisting of a `value` and `next` pointer.

## Exceptions

I'll have a single error to throw on `dequeue()` and `peek()`: `EmptyQueueError`.


---
## Array Queue

The following is an adaptation of [queue_design.md](../assignment2/queue_design.md).

The main adjustment I have made is setting a pre-defined capacity, 10. I've also added read-only access for `_isEmpty` and `_isFull`

### Methods
| Scope      | Definition              | Purpose                              |
|------------|-------------------------|--------------------------------------|
| Public     | `void enqueue(int)`     | Add an item to the end of the queue.
| Public     | `int dequeue()`         | Get the next item of the queue. Removes the item from the queue.
| Public     | `int peek()`            | Peek at the next item of the queue. Does not remove the item from the queue.
| Public     | `bool isEmpty()`        | Read-only `_isEmpty`.
| Public     | `bool isFull()`         | Read-only `_isFull`.
| Public     | `int length()`          | Calculate and return the filled positions in the queue.
| Private    | `int advanceIndex(int)` | Utility/helper method. Calculates the next index down the queue. Loops back around to index 0 when the time comes.

### Attributes
| Scope      | Definition           | Purpose                                 |
|------------|----------------------|-----------------------------------------|
| Public     | `const int CAPACITY` | The maximum capacity of the queue, or the length of the array.
| Private    | `bool _isEmpty`      | Set to `true` when the list is emptied, and back to `false` once `enqueue()` is called.
| Private    | `bool _isFull`       | Set to `true` when the list is filled, and back to `false` once `dequeue()` is called.
| Private    | `int frontIndex`     | The index of the next item to come off the queue.
| Private    | `int tailIndex`      | The index of the next position to be filled.
| Private    | `int items[]`        | Array of items in the queue.


## Exceptions

I'll have two exceptions: 
1. `EmptyQueueError` thrown on `peek()` and `dequeue()`.
2. `FullQueueError` thrown on `enqueue()`. 


---
## Tests

Both queue designs will go through the same tests, as they should have the same functionality. These tests will be the same template functions.

1. **Single in/out test.**
    Test that a single value can be added to the queue, and retrieved as expected. The queue should then have a length of 0.

2. **Triple in/out test.**
    Test that three values can be added to the queue, and all retrieved as expected. The queue should return them in the expected order, and then have a length of 0.

3. **Empty queue test.**
    Tests that dequeuing an empty queue throws and error. Catch that error.
     Paralell **Full queue test** for array queue.

4. **Length test.**
    Enqueue a given number of values, and check that the length updates as expected. Dequeue, and check the length.

5. **Peek test.**
    Enqueue a known value. Peek, and ensure the given value is as expected. Then test that the value is still in the queue.

6. **Wiggle test.**
    Enqueue four items. Dequeue one. Enqueue two. Dequeue three. Enqueue one. Dequeue the rest. Crash test to test with a handful of queue states (ex: enqueuing on a just-dequeued, non-empty queue).

### `driver.cpp`

 `driver.cpp` must be compiled with `linked_queue.cpp` and `array_queue.cpp`. Running the compiled code will test both queues using the same tests (templated functions), save the full queue test.


---
## Complexity Analysis

Below are attempted complexity analyses for both `linked_queue.cpp` and `array_queue.cpp`. 

To summarize, neither file uses a loop or recursion at any point, and I believe the time and space complexity for all methods/functions in both are **O(1)**.

### For `linked_queue.cpp`

Generally, the time and space complexity of all methods in `linked_queue.cpp` is theoretically O(1), as there is little input, and it never affects the time/space of a function.

The one method that takes input (comments removed): 

```cpp
void LinkedQueue::enqueue(int newValue) {
    Node* newNode = new Node{newValue, nullptr};

    if (isEmpty()) {
        frontPtr = backPtr = newNode; 
    } else {
        backPtr->next = newNode;

        backPtr = newNode;
    }

    _length ++;
}
```

At no point does `newValue` have an effect on the time or space of the method.


### For `array_queue.cpp`

Similarly, the time and space complexity both are consistently O(1) for the methods of `array_queue.cpp`.

For example, the one method that takes input (comments replaced):

```cpp
void ArrayQueue::enqueue(int value) {
    if (_isFull) { throw FullQueueError(); }
    
    if (_isEmpty) { _isEmpty = false; } 
    
    items[tailIndex] = value;
    tailIndex = advanceIndex(tailIndex);  // advanceIndex is a mathematic function

    if (tailIndex == frontIndex) { _isFull = true; }
}
```

`enqueue()` and `advanceIndex()` both only use basic operations, and zero loops. At no point is this method's time or space affected by the size of input.


---
## Guidelines Fulfilled

ahahabhgdsijkg
