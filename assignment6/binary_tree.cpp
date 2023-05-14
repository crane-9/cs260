#include <sstream>
#include <string>

#include "binary_tree.h"

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


void BSTree::add(int value) {
    Node* leaf = new Node{value, nullptr, nullptr};

    // AGH
}

int BSTree::remove(int value) {
    return -1;
}


bool BSTree::search(const int value) {
    // Lambda to call recursively.
    auto recurSearch = [value] (auto rS, Node *branch) -> bool {
        // Base case
        if (value == branch->value) {
            return true;    
        } else 
        // Recursive case 1
        if (value < branch->value && branch->left != nullptr) {
            return rS(rS, branch->left);
        } else 
        // Recursive case 2
        if (value > branch->value && branch->right != nullptr) {
            return rS(rS, branch->right);
        } else {
            return false;
        }
    };

    return recurSearch(recurSearch, root);
}


// Traversal implementations

string traversals::preOrder(Node *root) {
    stringstream message;

    // Recursive lambda, captures output stringstream.
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
    return "not implemented";
}

