# CS 260: Assignment 3: Linked-list Queue Design

Documentation design and plan for `queue.h`/`queue.cpp`.

---
## Linked Queue

My queue will consist of linked nodes. Nodes will be a simple `struct` with a `value` and a `next` pointer.

A queue will keep track of the front and back nodes, as well as the total length of the queue. The length attribute will assist in the pre-conditions for `dequeue()`, `enqueue()`, and `peek()`.

### Attributes
| Scope      | Name                    | Purpose                              |
|------------|-------------------------|--------------------------------------|
| Private    | `Node* backPtr`         | Pointer to the end of the line.
| Private    | `Node* frontPtr`        | Pointer to the front of the line.    
| Private    | `int _length`           | Counts every value in line.

### Methods
| Scope      | Name                    | Purpose                              |
|------------|-------------------------|--------------------------------------|
| Public     | `int dequeue()`         | Get the next at the front of the line.
| Public     | `void enqueue(int)`     | Add a new value to the back of the line.
| Public     | `bool isEmpty()`        | Check if the queue is empty.
| Public     | `int peek()`            | Peek at the front of the line.
| Public     | `int length()`          | Read-only length of the queue.


## EmptyQueueError

I'll have a single error to throw on `dequeue()` and `peek()`, in the case of these methods being called on an empty queue.

---
## Tests

I want to test every public method and attempt to show their approrpriate function.

1. **Single in/out test.**
    Test that a single value can be added to the queue, and retrieved as expected. The queue should then have a length of 0.

2. **Triple in/out test.**
    Test that three values can be added to the queue, and all retrieved as expected. The queue should return them in the expected order, and then have a length of 0.

3. **Empty queue test.**
    Tests that dequeuing an empty queue throws and error. Catch that error.

4. **Length test.**
    Enqueue a given number of values, and check that the length updates as expected. Dequeue, and check that the length updates as expected.

5. **Peek test.**
    Enqueue a known value. Peek, and ensure the given value is as expected. Then test that the value is still in the queue.

6. **Wiggle test.**
    Enqueue four items. Dequeue one. Enqueue two. Dequeue three. Enqueue one. Dequeue the rest. Crash test to test with a handful of queue states (ex: enqueuing on a just-dequeued, non-empty queue).
