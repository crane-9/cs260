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


/**
 * Secret implementation utility namespace? eyah
*/
namespace {
    /**
     * Recursive search to aid in BSTree::search(). could this just be a private utility though?? what i want is to be able to define a recursive function within a method. UAGH
    */
    bool recurSearch(const int value, Node *branch) {
        // Base case
        if (value == branch->value) {
            return true;    
        } else 
        // Recursive case 1
        if (value < branch->value && branch->left != nullptr) {
            return recurSearch(value, branch->left);
        } else 
        // Recursive case 2
        if (value > branch->value && branch->right != nullptr) {
            return recurSearch(value, branch->right);
        } else {
            return false;
        }
    }

}


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
    // AGH
}


bool BSTree::search(const int value) {
    // ermmmm
    return recurSearch(value, root);
}


string traversals::preOrder(Node *root, stringstream *message = nullptr) {
    // uhhh
    if (message == nullptr) {
        message = new stringstream;
    }

    if (root->left != nullptr) {
        preOrder(root->left, message);
    }

    // De-reference and insert?
    (*message) << root->value << ", ";

    if (root->right != nullptr) {
        preOrder(root->right, message);
    }

    // UH?!
    return message->str();
}

string traversals::inOrder(Node *root) {

}

string traversals::postOrder(Node *root) {

}

string traversals::breadthFirst(Node *root) {

}

