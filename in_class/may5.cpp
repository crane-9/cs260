/**
  * binary tree attempt because i want to
 * 
 * template node: left child [less than] and right child [greater than]
 * template binary tree: root pointer, depth counter? n [number of items?].
 *  - void add(T): sort a value into the tree.
 *  - bool search(T): find if a value exists in the tree
 *  - T remove(T): removes a value from the tree and restructures.
 * 
 * continued may 10
*/
#include <iostream>

using namespace std;


template<class T>
struct Node {
    T value;
    
    Node<T> *left;
    Node<T> *right;
};


/**
* autosorted binary tree. attempt...
*/
template<class T>
class BinaryTree {
    private:
        int _depth;
        int _items;

        Node<T> *root;

    public:
        BinaryTree(T _root) {
            root = new Node<T>{_root, nullptr, nullptr};

            _depth = 0;
            _items = 1;
        }

        void add(T value) {
        }
};




// recursive function to traverse the tree.
/// @note set to type int for simplicity.
void inOrderTraversal(Node<int> *root) {
    if (root->left != nullptr) {
        inOrderTraversal(root->left);
    }

    cout << root->value << ", ";

    if (root->right != nullptr) {
        inOrderTraversal(root->right);
    }
}


void breadthFirstTraversal(Node<int> *root) {
    // queue children of the root, 
    // visit children, add those children to the queue.
    // holy heck
    
}


// main main driver main do the things here this file is SQUISHED
int main() {
    Node<int> *leftLeft = new Node<int>{0, nullptr, nullptr};
    Node<int> *leftRight = new Node<int>{2, nullptr, nullptr};

    Node<int> *rightLeft = new Node<int>{4, nullptr, nullptr};
    Node<int> *rightRight = new Node<int>{6, nullptr, nullptr};

    Node<int> *left = new Node<int>{1, leftLeft, leftRight};
    Node<int> *right = new Node<int>{5, rightLeft, rightRight};

    Node<int> *root = new Node<int>{3, left, right};

    inOrderTraversal(root);
    cout << endl;


    return 0;
}
