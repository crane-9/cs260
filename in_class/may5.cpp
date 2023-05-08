/**
  * binary tree attempt because i want to
 * 
 * template node: left child [less than] and right child [greater than]
 * template binary tree: root pointer, depth counter? n [number of items?].
 *  - void add(T): sort a value into the tree.
 *  - bool search(T): find if a value exists in the tree
 *  - T remove(T): removes a value from the tree and restructures.
 *  - 
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
* autosorted binary tree.
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


// main main driver main do the things here this file is SQUISHED
int main() {


    return 0;
}
