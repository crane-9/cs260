#include <functional>
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


BSTree::BSTree(int _root) {
    root = new Node{_root, nullptr, nullptr};
    
    depth = 0;
    items = 1;
}

bool BSTree::recurSearch(int value, Node *branch) {
    
}


void BSTree::add(int value) {
    Node* leaf = new Node{value, nullptr, nullptr};

    // AGH
}

int BSTree::remove(int value) {
    // AGH
}

bool BSTree::search(int value) {
    type recursion = function<bool(Node *, recursion);

    function<bool(Node *, function)> recurSearch = [value](Node *branch, 
    function<bool(Node *, function)> rSearch) {
        // Base case
        if (value == branch->value) {
            return true;    
        } else 
        // Recursive case 1
        if (value < branch->value && branch->left != nullptr) {
            return rSearch(value, branch->left);
        } else 
        // Recursive case 2
        if (value > branch->value && branch->right != nullptr) {
            return rSearch(value, branch->right);
        } else {
            return false;
        }
    };

    return recurSearch(value, root);
}


string traversals::preOrder(Node *root) {
    if (root->left != nullptr) {
        preOrder(root->left);
    }

    cout << root->value << ", ";

    if (root->right != nullptr) {
        preOrder(root->right);
    }
}

string traversals::inOrder(Node *root) {

}

string traversals::postOrder(Node *root) {

}

string traversals::breadthFirst(Node *root) {

}

