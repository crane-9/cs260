# CS260 Assignment 2: Designing a Queue Data Structure

### Guidelines
> Based on what we know about linked lists, stacks, and queues, design a queue data structure:
> 
> What functions are we likely to need for a queue to function like the one discussed in class?
> 
> What values will we need to know about the structure for our queue to function properly?


---
## Queue Design

The queue I've designed has two main methods: `enqueue()` and `next()`. `enqueue()` adds a new value to the end of the queue, while `next()` gets the value at the front of the queue. A queue has a `capacity`, set upon construction, and a private array of values (`items`) that holds the enqueued values. A private attribute, `frontIndex` defines the current "front" of the queue, and `tailIndex` defines the current "back" of the queue.

I also have a handful of helper methods and attributes, included below.

### Methods
| Scope      | Name                    | Purpose                              |
|------------|-------------------------|--------------------------------------|
| Public     | `void enqueue(int)`     | Add an item to the end of the queue.
| Public     | `int length()`          | Calculate and return the filled positions in the queue.
| Public     | `int next()`            | Get the next item of the queue. Removes the item from the queue.
| Public     | `int peek()`            | Peek at the next item of the queue. Does not remove the item of the queue.
| Private    | `int advanceIndex(int)` | Utility/helper method. Moves the index one position down the queue. Loops back around to index 0 when necessary.
| Private    | `bool isEmpty()`        | Returns true if the queue is empty, false otherwise.
| Private    | `bool isFull()`         | Returns true if the queue is full, false if there is one or more empty space.

### Attributes
| Scope      | Name              | Purpose                                    |
|------------|-------------------|--------------------------------------------|
| Public     | `int capacity`    | The maximum capacity of the queue, or the length of the array.
| Private    | `int tailIndex`   | The index of the next (empty) position to be filled.
| Private    | `int frontIndex`  | The index of the next item to come off the queue.
| Private    | `int items[]`     | Array of items in the queue.
| Private    | `const int EMPTY` | A value that indicates an empty space in a queue. 

---
To clarify the anatomy of a queue, and visualize `capacity` vs `length()`:

![A doodle of queue anatomy.](https://cdn.discordapp.com/attachments/799704269787496518/1096592198725795901/20230414_172540.jpg)

The two spaces have been left   

