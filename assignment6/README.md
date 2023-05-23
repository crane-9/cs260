# CS 260: Assignment 6: Binary Search Tree

> Note: My code does not pass all the tests I wanted it to pass. The core issue is the `remove()` method--it should be recursive, and it is not. 

## BST Tests

Basic insertion test--insert values out-of-order, then check that all is well.

Basic search test--returns a boolean for whether the given value is in the tree. If insertion does not work as intended, this will not work.

Basic removal test--after a tree is populated, remove a value with a single child. Check again that all is well. Remove another value with two children, and check again.

"Checking all is well" meaning printing traversal results and comparing to an expected/desired output.


## Traversal tests

Traversal types:
- Pre-order
- In-order
- Post-order
- Breadth-first

To test each, I want to manually build a tree (such as in `may5.cpp`) so that I know what to expect of each traversal. Example:
```cpp
Node<int> *leftLeft = new Node<int>{0, nullptr, nullptr};
Node<int> *leftRight = new Node<int>{2, nullptr, nullptr};

Node<int> *rightLeft = new Node<int>{4, nullptr, nullptr};
Node<int> *rightRight = new Node<int>{6, nullptr, nullptr};

Node<int> *left = new Node<int>{1, leftLeft, leftRight};
Node<int> *right = new Node<int>{5, rightLeft, rightRight};

Node<int> *root = new Node<int>{3, left, right};
```

---
## Binary search tree class

My binary search tree uses nodes which hold only a single integer value. The class has the following attributes and methods:

**Attributes**
| Scope    | Declaration   | Purpose                                  |
|:---------|:--------------|-----------------------------------------:|
| Private  | `Node *root`  | The root of the tree.
| Private  | `int items`   | Counts the number of items in a tree.

**Methods**
| Scope    | Declaration                     | Purpose                                  |
|:---------|:-------------------------|-----------------------------------------:|
| Private  | `Node *findByValue(int)`    | Finds the node holding the desired value. Note that it returns the first node to match the given value, not accounting for duplicates.
| Public   | `void add(int)`                 | Adds a value to the tree using recursion.
| Public   | `int remove(int)`               | Removes the node containing the given value from the tree. Returns that value.
| Public   | `bool search(int)`              | Searches the tree for the given value. Returns true/false: true if the value exists within the tree, false otherwise.
| Public   | `int size()`                    | Getter method for private variable `items`.
| Public   | `string traversePreOrder()`     | Traverses the tree pre-order, returning a string of each value, separated by a comma and space.
| Public   | `string traverseInOrder()`      | Traverses the tree in-order, and behaves just as `traversePreOrder()`.
| Public   | `string traversePostOrder()`    | Traverses the tree post-order, behaves just as the previous traversal methods.
| Public   | `string traverseBreadthFirst()` | Traverses the tree breadth-first, and behaves as the previous traversal methods.

The final four methods, the traversal methods, each call their correlating traversal function from the `traversals` namespace, and pass the tree's `root` node as an argument.

## Queue

It should be noted that a linked-queue data structure is included--`queue.h` and `queue.cpp`. This structure was adapted from `assignment3/linked_queue.h/cpp`, and thorough design documentation can be found [here](../assignment3/readme.md#linked-queue)).

The main difference is that the nodes of the queue (renamed to `QueueNode`) hold a pointer to a `Node` of the search tree. 

These files have been included solely to be used for `traversals::breadthFirst()`.

---
## Note on complexity analysis

My `search()` `remove()` and `add()` methods each should have a complexity of O(log(n)), which is expected for a sorted binary search tree. With an unsorted tree, the complexity of each method is O(n) at best.

---
## Meeting requirements

My structure uses a node to store values:

```cpp
// binary_tree.h, lines 8 - 11
struct Node {
    int value;
    Node *left, *right;
};
```

My structure has an `add()` method which adds and orders a new node. I use a lambda recursively within this method.

```cpp
// binary_tree.cpp, lines 53 - 79 (complexity analysis notes removed)
void BSTree::add(const int value) {
    Node* leaf = new Node{value, nullptr, nullptr};
    ++items; 

    // Recursive traversal.
    auto traverse = [leaf, value] (auto t, Node *branch) -> void {
        Node **next;

        // Decides where to place the new node.
        if (branch->value > value) {
            if (branch->left != nullptr) {
                t(t, branch->left);
            } else {
                branch->left = leaf;
            }
        } else {
            if (branch->right != nullptr) {
                t(t, branch->right);
            } else {
                branch->right = leaf;
            }
        }
    };

    traverse(traverse, root);
}
```

My structure has a `remove()` method, which removes a node from the tree. It does not work if the node has two children, and leaks if the node has grandchildren.

```cpp
// binary_tree.cpp, lines 111 - 134, a cropped selection of the method.

{   // ... Finds desired node and its parent ...

    // Pick a successor--defaults to right child.
    if (current->right != nullptr) {
        successor = current->right;
        
        // Move sibling node.
        if (current->left != nullptr) {
            /* I can't figure this out, I need recursion and 
            to restructure the rest of this method. */
        }

    } else if (current->left != nullptr) {
        successor = current->left;
    } else {
        successor = nullptr;
    }

    // Attach successor to parent
    if (parent == nullptr) {
        root = successor;
    } else if (isRightChild) {
        parent->right = successor;
    } else {
        parent->left = successor;
    }

    // ... Delete node and return its value ...
}
```
> Note: The solution is to make recursion do the work.

I have four traversal functions: pre-order, in-order, post-order, and breadth-first. These are all declared within a `traversals` namespace, so that they may be called on a stray node, and not just within a tree. These are all implemented in `binary_tree.cpp`, beginning on line 177. Three of four use a lambda recursively.

> Note: I chose to use lambdas recursively in order to emulate how I would solve this problem in Python, where one can define a function within a function.

The exception is the breadth-first traversal, which uses a queue as mentioned:

```cpp
// binary_tree.cpp, lines 236 - 258

string traversals::breadthFirst(Node *root) {
    // Initialize.
    stringstream message;
    LinkedQueue queue;
    
    // Add root to queue. 
    queue.enqueue(root);

    // While queue isn't empty, dequeue, add value to return message, and enqueue children.
    while (!queue.isEmpty()) {
        Node *current = queue.dequeue();
        message << current->value << ", ";

        if (current->left != nullptr) {
            queue.enqueue(current->left);
        }
        if (current->right != nullptr) {
            queue.enqueue(current->right);
        }
    }

    return message.str();
}
```

