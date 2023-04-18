# CS 260: Assignment 3: Linked-list Queue Design

Documentation design and plan for `queue.h`/`queue.cpp`.

---
## Linked Queue

My queue will consist of linked nodes. Nodes will be a simple structure as so:

```cpp
struct Node {
    int value;
    Node *next;
}
```

A queue will keep track of the front and back nodes, as well as the total length of the queue. The length attribute will assist in the pre-conditions for `dequeue()`, `enqueue()`, and `peek()`.

### Attributes
| Scope      | Name                    | Purpose                              |
|------------|-------------------------|--------------------------------------|
| Private    | `Node *backNode`        | Pointer to the end of the line.
| Private    | `Node *frontNode`       | Pointer to the front of the line.    
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
