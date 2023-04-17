# CS260 Assignment 2: Designing a Queue Data Structure

### Guidelines
> Based on what we know about linked lists, stacks, and queues, design a queue data structure:
> 
> What functions are we likely to need for a queue to function like the one discussed in class?
> 
> What values will we need to know about the structure for our queue to function properly?


---
## Queue Design

The queue I've designed has two main methods: `enqueue()` and `dequeue()`. `enqueue()` adds a new value to the end of the queue, while `dequeue()` removes and returns the value at the front of the queue.

A queue has a `capacity`, set upon construction, and a private array of values (`items`) that holds the enqueued values. 

A private attribute, `frontIndex` defines the current "front" of the queue, and `tailIndex` defines the current "back" of the queue (or, the next space an enqueued value will take).

I also have a handful of other helper methods and attributes, included below.

### Methods
| Scope      | Name                    | Purpose                              |
|------------|-------------------------|--------------------------------------|
| Public     | `void enqueue(int)`     | Add an item to the end of the queue.
| Public     | `int length()`          | Calculate and return the filled positions in the queue.
| Public     | `int dequeue()`         | Get the next item of the queue. Removes the item from the queue.
| Public     | `int peek()`            | Peek at the next item of the queue. Does not remove the item from the queue.
| Private    | `int advanceIndex(int)` | Utility/helper method. Calculates the next index down the queue. Loops back around to index 0 when the time comes.

### Attributes
| Scope      | Name              | Purpose                                    |
|------------|-------------------|--------------------------------------------|
| Public     | `int capacity`    | The maximum capacity of the queue, or the length of the array.
| Private    | `int tailIndex`   | The index of the next position to be filled.
| Private    | `int frontIndex`  | The index of the next item to come off the queue.
| Private    | `bool isEmpty`    | Set to `true` when the list is emptied, and back to `false` once `enqueue()` is called.
| Private    | `bool isFull`     | Set to `true` when the list is filled, and back to `false` once `dequeue()` is called.
| Private    | `int items[]`     | Array of items in the queue.


---
## Examples

Below is a simulation of queue usage. First, basic visualization. Then expected use flow, including empty and full states.

### Queue visualization

| Index              |  0  |  1  |  2  |  3  |  4  |  ...                  |
|-------------------:|:---:|:---:|:---:|:---:|:---:|:----------------------|
|    `dequeue()` <-- |  8  |  7  |  6  |  _  |  _  | <-- `enqueue(int)`    |

In which:
* `capacity == 5`
* `length() == 3`
* `frontIndex == 0`
* `tailIndex == 3`
* `isEmpty == false`
* `isFull == false`


> Notes on queue function:

* The two final spaces have been left blank for visualization. In reality, they could be any value: the use of `frontIndex` and `tailIndex` allow these values to be ignored and overwritten.
    * There is no value indicative of an "empty" space, meaning any and all integers may be enqueued.

- `enqueue()` shifts the position of `tailIndex` (using `advanceIndex()`). `dequeue()` shifts the position of `frontIndex` (also using `advanceIndex()`).

* `isEmpty` and `isFalse` are set on construction, and altered conditionally on `dequeue()` and `enqueue()`, respectively.
    * These are treated as flags to clarify the queue's status in the case that `frontIndex == tailIndex`.

- `length()` is calculated using `frontIndex` and `tailIndex`, unless either `isEmpty` or `isFull` are `true`.

In the following examples, these notes may be clarified and visualized. "F" will mark the location of `frontIndex`, and "T" will mark the location of `tailIndex`. Additionally, `isEmpty` and `isFull` are displayed.


### Expected use

On construction:

| Index             |  0  |  1  |  2  |  3  |  4  |  ...                  |
|------------------:|:---:|:---:|:---:|:---:|:---:|:----------------------|
|                   |  _  |  _  |  _  |  _  |  _  |                       |
|                   |  F  |     |     |     |     | `isEmpty`: *true*     |
|                   |  T  |     |     |     |     | `isFull`: false       |

(Note that F and T are in the same position.) 
(Empty -- using `dequeue()` or `peek()` would raise an error.)

After `enqueue(8)`:

| Index             |  0  |  1  |  2  |  3  |  4  |  ...                  |
|------------------:|:---:|:---:|:---:|:---:|:---:|:----------------------|
|                   |  8  |  _  |  _  |  _  |  _  |                       |
|                   |  F  |     |     |     |     | `isEmpty`: false      |
|                   |     |  T  |     |     |     | `isFull`: false       |

After `enqueue(7)`, `enqueue(6)`, `enqueue(5)`:

| Index             |  0  |  1  |  2  |  3  |  4  |  ...                  |
|------------------:|:---:|:---:|:---:|:---:|:---:|:----------------------|
|                   |  8  |  7  |  6  |  5  |  _  |                       |
|                   |  F  |     |     |     |     | `isEmpty`: false      |
|                   |     |     |     |     |  T  | `isFull`: false       |

After `dequeue()` (returns `8`):

| Index             |  0  |  1  |  2  |  3  |  4  |  ...                  |
|------------------:|:---:|:---:|:---:|:---:|:---:|:----------------------|
|                   |  _  |  7  |  6  |  5  |  _  |                       |
|                   |     |  F  |     |     |     | `isEmpty`: false      |
|                   |     |     |     |     |  T  | `isFull`: false       |

After `enqueue(4)`:

| Index             |  0  |  1  |  2  |  3  |  4  |  ...                  |
|------------------:|:---:|:---:|:---:|:---:|:---:|:----------------------|
|                   |  _  |  7  |  6  |  5  |  4  |                       |
|                   |     |  F  |     |     |     | `isEmpty`: false      |
|                   |  T  |     |     |     |     | `isFull`: false       |

After `enqueue(3)`:

| Index             |  0  |  1  |  2  |  3  |  4  |  ...                  |
|------------------:|:---:|:---:|:---:|:---:|:---:|:----------------------|
|                   |  3  |  7  |  6  |  5  |  4  |                       |
|                   |     |  F  |     |     |     | `isEmpty`: false      |
|                   |     |  T  |     |     |     | `isFull`: *true*      |

(Note that F and T are again in the same position.)
(Full -- another `enqueue()` would raise an error.)

After `dequeue()` (returns `7`):

| Index             |  0  |  1  |  2  |  3  |  4  |  ...                  |
|------------------:|:---:|:---:|:---:|:---:|:---:|:----------------------|
|                   |  3  |  _  |  6  |  5  |  4  |                       |
|                   |     |     |  F  |     |     | `isEmpty`: false      |
|                   |     |  T  |     |     |     | `isFull`: false       |
