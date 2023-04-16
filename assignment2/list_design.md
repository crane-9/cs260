# CS260 Assignment 2: Designing a List Data Structure

### Guidelines
> Based on what we know about linked lists, design a list data structure that allows us to add (insert) or remove (delete) values at a given location in the list (instead of the top of a stack or the front or back of a queue):
> 
> What functions are we likely to need for a list to function like this?
> 
> What values will we need to know about the structure for our list to function properly?


---
## Node Design

In order to have my list function as desired, I need a simple `Node` structure.

### Fields
| Scope      | Name         | Purpose                                         |
|------------|--------------|-------------------------------------------------|
| Public     | `Node* next` | Pointer to the next node.
| Public     | `Node* prev` | Pointer to the previous node.
| Public     | `int value`  | Value of this node.

*Upon implementation, for the sake of streamlined construction, this may be a class as rather than a structure.


---
## List Design

I've designed a simple linked-list data structure, consisting of nodes. The list structure holds pointers to the first and last nodes: `firstNode` and `lastNode`. 

There are a handful of public methods to alter and manipulate the list--namely `insert()` and `pop()`--at any given index. These methods use a private helper method, `fetchNode()` to find the node at the desired index.

I chose to give it a limit to how many items it can store as I feel somewhat concerned about efficiency. `fetchNode()` fetches the desired node by surfing through the linked nodes, starting at `firstNode`. Using `_length`, I can validate the index before searching. I could also go backwards from `lastNode` if the desired index is closer to the back than the front. (Ex: getting index `9` of a 12-item list.) I still 


### Methods
| Scope      | Name                    | Purpose                              |
|------------|-------------------------|--------------------------------------|
| Public     | `void append(int)`      | Add a value to the end of the list.
| Public     | `void insert(int, int)` | Insert a value into the desired index.
| Public     | `int length()`          | Returns read-only `_length`.
| Public     | `int peek(int)`         | Peeks at the given index.
| Public     | `int pop(int)`          | Remove and return the value from the given index. "Pops" off the desired index, rather than the end.
| Public     | `int replace(int, int)` | Replaces the value at the given index with a new value.
| Private    | `Node* fetchNode(int)`  | Helper method. Fetches a node at the desired index. If the index is out of range, an error will raise.

### Attributes
| Scope      | Name              | Purpose                                    |
|------------|-------------------|--------------------------------------------|
| Public     | `int capacity`    | The maximum capacity of the list, set upon construction.
| Private    | `Node* firstNode` | Pointer to the list's first node.
| Private    | `Node* lastNode`  | Pointer to the list's last node.
| Private    | `int _length`     | Records the length of the list.

