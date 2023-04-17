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


---
## List Design

I've designed a simple linked-list data structure, consisting of `Node` instances. The list structure holds pointers to the first and last nodes: `firstNode` and `lastNode`. 

There are a handful of public methods to alter and manipulate the list--namely `insert()` and `pop()`--at any given index. These methods use a private helper method, `fetchNode()` to find the node at the desired index.

`fetchNode()` fetches the desired node by surfing through the linked nodes, starting at `firstNode`. Using `_length`, I can validate the index before searching. I could also go backwards from `lastNode` if the desired index is closer to the back than the front. (Ex: getting index `9` of a 12-item list.) I feel somewhat concerned about the efficiency of this structure, however the length is flexible.


### Methods
| Scope      | Name                    | Purpose                              |
|------------|-------------------------|--------------------------------------|
| Public     | `void append(int)`      | Add a value to the end of the list.
| Public     | `void insert(int, int)` | Insert a value into the desired index.
| Public     | `int length()`          | Returns read-only `_length`.
| Public     | `int peek(int)`         | Peeks at the given index.
| Public     | `int pop(int)`          | Remove and return the value from the given index. Default argument indicates the end of the list.
| Public     | `int replace(int, int)` | Replaces the value at the given index with a new value.
| Private    | `Node* fetchNode(int)`  | Helper method. Fetches a node at the desired index. If the index is out of range, an error will raise.

### Attributes
| Scope      | Name              | Purpose                                    |
|------------|-------------------|--------------------------------------------|
| Private    | `Node* firstNode` | Pointer to the list's first node.
| Private    | `Node* lastNode`  | Pointer to the list's last node.
| Private    | `int _length`     | Records the length of the list (altered on `append()`, `insert()`, and `pop()`).


## Notes

- My list is fairly influenced by the basic `list` datatype in Python 3. The methods `append()` and `pop()` are recreations of the Python list functions of the same name.

- It may be better for `length()` to just count the length of the list when called, rather than using `_length` to manually record the length of the list. I am choosing the given design in attempt to be mindful about efficiency.

