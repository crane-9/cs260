# CS 260: Assignment 6: Binary Search Tree

## BST Tests

Basic insertion test--insert values out-of-order, then print the tree and verify that all is well [how to print BST??]

Basic removal test--after a tree is populated, remove a value. Check again that all is well. Remove another value, check again.

Basic search test--returns a boolean for whether the given value is in the tree. This could butt heads with the insertion test.


## Traversal tests

Traversal types:
- Pre-order
- In-order
- Post-order
- Breadth-first

To test each, I want to manually build a tree (such as in `may5.cpp`):
```cpp
Node<int> *leftLeft = new Node<int>{0, nullptr, nullptr};
Node<int> *leftRight = new Node<int>{2, nullptr, nullptr};

Node<int> *rightLeft = new Node<int>{4, nullptr, nullptr};
Node<int> *rightRight = new Node<int>{6, nullptr, nullptr};

Node<int> *left = new Node<int>{1, leftLeft, leftRight};
Node<int> *right = new Node<int>{5, rightLeft, rightRight};

Node<int> *root = new Node<int>{3, left, right};
```
So that I know what to expect of each traversal.
