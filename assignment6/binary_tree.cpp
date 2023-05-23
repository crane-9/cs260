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
    
    depth = 0;
    items = 1;
}

Node *BSTree::findByValue(const int value) {
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


void BSTree::add(const int value) {
    Node* leaf = new Node{value, nullptr, nullptr};
    ++items;

    // basic adding.
    // recursive lambda that will traverse and eventually connect a new node.
    auto traverse = [leaf, value] (auto t, Node *branch) -> void {
        Node **next;

        // decide where .... this code is UGNGLY.
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

    // then that's it i think.
    traverse(traverse, root);
}

int BSTree::remove(const int value) {
    // actually, i need to get the parent node of the removed node!
    Node *current, *parent;

    current = root;
    parent = nullptr;
    while (current != nullptr) {
        if (current->value == value) {
            break;
        }

        parent = current;
        
        if (current->value > value) {
            current = current->left;
        } else if (current->value < value) {
            current = current->right;
        }
    }

    // not found
    if (current == nullptr) {
        throw MissingValueError(value);
    }

    if (parent != nullptr) {
        // detach from parent
        if (current->value < parent->value) {
            parent->left = nullptr;
        } else {
            parent->right = nullptr;
        }
    }

    // if 2 children
    if (current->left != nullptr && current->right != nullptr) {
        // IF PARENT:
        //  decide which one is an appropriate successor in relation to the parent node
        //  make connection to parent
        //  make sibling the parent

        // IF PARENT IS NULLPTR:
        //  uhhh default successor comes from the right.
        //  make new root.
        //  make sibling child.
    } else 
    // if 1 child
    if (current->left != nullptr || current->right != nullptr) {
        // IF PARENT:
        //  find it and make it the successor to the parent node.
        //  make sibling child

        // IF PARENT IS NULLPTR:
        //  find it and make it new root
    }

    // return desired value, delete current node.
    int retValue = current->value;
    
    delete current;
    --items;

    return retValue;
}


bool BSTree::search(const int value) {
    try {
        Node *desired = findByValue(value);
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
