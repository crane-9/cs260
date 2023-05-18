#include <iostream>
#include <sstream>
#include <string>

#include "binary_tree.h"

using namespace std;


/**
 * Makes a tree naively without use of the BSTree class.
*/
Node *makePrimitiveTree() {
    Node *leftLeft = new Node{0, nullptr, nullptr};
    Node *leftRight = new Node{2, nullptr, nullptr};

    Node *rightLeft = new Node{4, nullptr, nullptr};
    Node *rightRight = new Node{6, nullptr, nullptr};

    Node *left = new Node{1, leftLeft, leftRight};
    Node *right = new Node{5, rightLeft, rightRight};

    Node *root = new Node{3, left, right};

    return root;
}

void traversalTests() {
    Node* testRoot = makePrimitiveTree();

    cout << traversals::preOrder(testRoot) << endl;
    cout << traversals::inOrder(testRoot) << endl;
    cout << traversals::postOrder(testRoot) << endl;
    cout << traversals::breadthFirst(testRoot) << endl;
}


string addTest() {
    BSTree testTree(3);
    testTree.add(5);

    cout << testTree.traverseInOrder() << endl;

    testTree.add(1);
    testTree.add(4);

    cout << testTree.traverseInOrder() << endl;

    // remove function is not working as of current ! OK!
    // testTree.search(3);

    cout << testTree.search(0) << endl;
    cout << testTree.search(3) << endl;
    cout << testTree.search(7) << endl;

    cout << testTree.remove(1) << endl;

    return "";
}


int main() {
    traversalTests();
    addTest();

    return 0;
}
