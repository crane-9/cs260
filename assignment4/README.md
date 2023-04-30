# CS 260: Assignment 4: List operations.

I've built a linked list with the following operations:
- append(value), returns void.
- count(value), returns a count of the given value.
- get(index), returns the value at the given index.
- index(value), returns the index of the given value.
- insert(index, value), returns void.
- pop(index), removes and returns the value at the given index.
- replace(index, value), replaces and returns the old value at the given index.

---
## Meeting requirements.

My linked list keeps track of the front node and back node using pointers:
```cpp
// linked_list.h, lines 34 - 37
class LinkedList {
    private:
        Node *firstNode;
        Node *lastNode;
...
```

> **Note**: The below snippets refer to a private method of the `LinkedList` class called `fetchNode()`. This method uses a loop to get the desired node at the given index. I created this private method to cut down on repetition.

My implementation of an `add()` method is called `insert()`. Here is its implementation in `linked_list.cpp`.
```cpp
// linked_list.cpp, lines 92 - 116
void LinkedList::insert(int idx, int newValue) {
    // Get the node currently at `idx`
    Node *nextNode = fetchNode(idx);

    // Build new node.
    Node *newNode = new Node{newValue, nextNode, nextNode->prev};

    // Link respective nodes to the new node.
    if (newNode->next != nullptr) {
        newNode->next->prev = newNode;
    }

    if (newNode->prev != nullptr) {
        newNode->prev->next = newNode;
    }

    // Fix absolute pointers.
    if (idx == 0) {
        firstNode = newNode;
    } else if (idx == _length) {
        lastNode = newNode;
    }

    _length ++;
}
```

Here is my implementation of a `remove()` function. Mine is `pop()` and it takes the desired index as an argument, and returns the removed value.
```cpp
// linked_list.cpp, lines 120 - 139
int LinkedList::pop(int idx) {
    Node *poppedNode = fetchNode(idx);

    // Retrieve adjacent nodes.
    Node *previousNode = poppedNode->prev;
    Node *nextNode = poppedNode->next;

    // Close the gap.
    previousNode->next = nextNode;
    nextNode->prev = previousNode;

    // Retrieve the value.
    int value = poppedNode->value;

    // Alter list.
    delete poppedNode;
    _length --;

    return value;
}
```

Finally, this is my implementation of `get()`, simply returning the value of the wanted node. 
```cpp
// linked_list.cpp, lines 70 - 73
int LinkedList::get(int idx) {
    Node *wantedNode = fetchNode(idx);
    return wantedNode->value;
}
```

---
## Implementation Complexity Analysis Summary

Below are my complexity analysis results for each function as implemented in `linked_list.cpp`. 

| Method                         | Complexity   |
|:-------------------------------|:------------:|
| `IndexError::IndexError()`     | O(1)
| `IndexError::what()`           | O(1)
| `LinkedList::LinkedList()`     | O(1)
| `LinkedList::fetchNode()`      | **O(n)**
| `LinkedList::append()`         | O(1)
| `LinkedList::count()`          | **O(n)**
| `LinkedList::get()`            | **O(n)**
| `LinkedList::index()`          | **O(n)**
| `LinkedList::insert()`         | **O(n)**
| `LinkedList::isEmpty()`        | O(1)
| `LinkedList::pop()`            | **O(n)**
| `LinkedList::replace()`        | **O(n)**
| `LinkedList::toString()`       | * **O(n)**/*O(n²)*

When compared to the [Big-O cheatsheet](https://www.bigocheatsheet.com/), as a doubly-linked list, my implementation complexity looks about right.

*I used a `stringstream` in `LinkedList::toString()`. As mentioned in class, the complexity of a `stringstream`'s `str()` method could be O(n), but that is not known. At best, the complexity is O(n), and at worst, it is O(n²).
