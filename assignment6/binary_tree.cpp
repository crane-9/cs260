#include <iostream>
#include <sstream>
#include <string>

#include "binary_tree.h"
#include "queue.h"

using namespace std;


MissingValueError::MissingValueError(int value) {
    _value = value;
}

string MissingValueError::what() {
    stringstream message;
    message << _value << "could not be found in tree.";

    return message.str();
}


// BSTree implementations

BSTree::BSTree(int _root) {
    root = new Node{_root, nullptr, nullptr};
    
    items = 1;
}

Node *BSTree::findByValue(const int value) { // O(logn)
    auto recurSearch = [value] (auto rS, Node *branch) -> Node * {
        // Base case
        if (value == branch->value) {
            return branch;   
        } else 
        // Recursive case 1
        if (value < branch->value && branch->left != nullptr) {
            return rS(rS, branch->left);
        } else 
        // Recursive case 2
        if (value > branch->value && branch->right != nullptr) {
            return rS(rS, branch->right);
        } else {
            throw MissingValueError(value);
        }
    };

    return recurSearch(recurSearch, root);
}


void BSTree::add(const int value) { // O(logn) ?
    // O(1)
    Node* leaf = new Node{value, nullptr, nullptr};
    ++items; 

    // Recursive traversal.
    auto traverse = [leaf, value] (auto t, Node *branch) -> void { // O(logn)
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

int BSTree::remove(const int value) { // O(logn)
    // O(1)
    Node *current, *parent, *successor;
    bool isRightChild; // Variable indicates current's relationship to parent.

    // Find desired node.
    current = root;
    parent = nullptr;
    while (current != nullptr) { // O(logn)
        if (current->value == value) {
            break;
        }

        parent = current;
        
        if (current->value > value) {
            current = current->left;
            isRightChild = false;
        } else if (current->value < value) {
            current = current->right;
            isRightChild = true;
        }
    }

    // O(1) from here
    // Not found.
    if (current == nullptr) {
        throw MissingValueError(value);
    }
    
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

    // Return desired value, delete current node.
    int retValue = current->value;
    
    delete current;
    --items;

    return retValue;
}


bool BSTree::search(const int value) { // O(logn)
    try {
        Node *desired = findByValue(value); // O(logn)
    } catch (MissingValueError error) {
        return false;
    }

    return true;
}


string BSTree::traversePreOrder() {
    return traversals::preOrder(root);
}

string BSTree::traverseInOrder() {
    return traversals::inOrder(root);
}

string BSTree::traversePostOrder() {
    return traversals::postOrder(root);
}

string BSTree::traverseBreadthFirst() {
    return traversals::breadthFirst(root);
}


// Traversal implementations
// I believe they should all be O(n)?

string traversals::preOrder(Node *root) {
    stringstream message;

    // Recursive lambda, captures outputs to stringstream.
    auto order = [&message] (auto o, Node *branch) -> void {
        message << branch->value << ", ";

        if (branch->left != nullptr) {
            o(o, branch->left);
        }

        if (branch->right != nullptr) {
            o(o, branch->right);
        }
    };
    
    order(order, root);
    return message.str();
}

string traversals::inOrder(Node *root) {
    stringstream message;

    // Recursive lambda
    auto order = [&message] (auto o, Node *branch) -> void {
        if (branch->left != nullptr) {
            o(o, branch->left);
        }

        message << branch->value << ", ";

        if (branch->right != nullptr) {
            o(o, branch->right);
        }
    };

    order(order, root);
    return message.str();
}

string traversals::postOrder(Node *root) {
    stringstream message;

    auto order = [&message] (auto o, Node *branch) -> void {
        if (branch->left != nullptr) {
            o(o, branch->left);
        }

        if (branch->left != nullptr) {
            o(o, branch->right);
        }

        message << branch->value << ", ";
    };

    order(order, root);
    return message.str();
}

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
