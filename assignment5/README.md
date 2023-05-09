# CS 260: Assignment 5: Auto-sorted List

I've made an auto-sorted singly-linked list with three operations:
- `int index(int)`: Searches for a value in the list and returns its index position.
- `void insert(int)`: Sorts a new value into the list.
- `int remove(int)`: Finds the given value in the list, and removes it. Returns the removed value.


---
## Big-O Complexity Analysis

| Method                  | Complexity   |
|:------------------------|:------------:|
| `AutoList::index()`     | O(n)
| `AutoList::insert()`    | O(n)
| `AutoList::remove()`    | O(n)

I believe that all three of my methods have a complexity of O(n). I think they could each be improved upon, and that using an array-based sorted list may even be more efficient, given the variety of possible sorting algorithms.

---
## Meeting Requirements

Here is my search method, `index`, it returns the index of the desired value using a very simple search algorithm:

```cpp
// autosort_list.cpp, lines 28 - 45

int AutoList::index(int value) { // O(n)
    // Start at head of the list.
    int idx = 0;

    for (Node *current = head; current != nullptr; current = current->next) {
        // If data is larger than the value, the value is not in the list.
        if (current->data > value) {
            break;
        } else if (current->data == value) {
            return idx;
        }

        // Else, value has not yet been found, but may exist.
        idx ++;
    }
    
    throw ValueNotFoundError(value);
}
```

Here is a snippet of my insertion method, `insert`. This is the second half of the method, the base case, where excluded lines cover special cases in which the new value would be inserted at the beginning of the list.

```cpp
// autosort_list.cpp, lines 65 - 72

Node* current = head;

while (current->next != nullptr && data > current->next->data) { // O(n)
    current = current->next;
}

newNode->next = current->next;
current->next = newNode;
```

Here is a snippet of my removal method, `remove`. This is the loop that locates the node holding the desired value:

```cpp
// autosort_list.cpp, lines 79, 90
while (current != nullptr) { // O(n)
    // If data is greater than the given value, value is not going to be in the list.
    if (current->data > value) {
        throw ValueNotFoundError(value);
    
    // What we are looking for: 
    } else if (current->next->data == value) {
        break;
    }

    current = current->next;
}
```


To demonstrate success, below is a screenshot of terminal output, one line printed after each insertion, for 20 insertions, trailed by printing the list's final length.

![Console output, building an ordered list.](https://cdn.discordapp.com/attachments/799704269787496518/1105250508266021004/image.png)
