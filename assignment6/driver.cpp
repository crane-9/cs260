#include <iostream>
#include <sstream>
#include <string>

#include "binary_tree.h"

using namespace std;


/**
 * Makes a tree naively without use of the BSTree class.
*/
Node *makePrimitiveTree() {
    /* Tree looks like:
       3
     1   5
    0 2 4 6
    */
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

    bool preOrderTest, inOrderTest, postOrderTest, breadthFirstTest;
    preOrderTest = traversals::preOrder(testRoot) == "3, 1, 0, 2, 5, 4, 6, ";
    inOrderTest = traversals::inOrder(testRoot) == "0, 1, 2, 3, 4, 5, 6, ";
    postOrderTest = traversals::postOrder(testRoot) == "0, 2, 1, 4, 6, 5, 3, ";
    breadthFirstTest = traversals::breadthFirst(testRoot) == "3, 1, 5, 0, 2, 4, 6, ";

    // Overusing lambdas to save on repetition.
    auto message = [] (bool test, string testName) -> void {
        if (test) {
            cout << "PASSED "; 
        } else {
            cout << "FAILED "; 
        }

        cout << testName  << " behaves as expected." << endl;
    };

    // Print test results.
    message(preOrderTest, "Pre-order traversal");
    message(inOrderTest, "In-order traversal");
    message(postOrderTest, "Post-order traversal");
    message(breadthFirstTest, "Breadth-first traversal");
}


void treeTests() {
    BSTree testTree(3);

    /* Test adding */
    testTree.add(5);
    testTree.add(0);
    testTree.add(1);

    // Send results.
    if (testTree.traverseInOrder() == "0, 1, 3, 5, ") {
        cout << "PASSED Adding value to tree works as expected.";
    } else {
        cout << "FAILED Ordered tree expected to have a root of 3 and branch of 5, 0, and 1 [in order added]. In order traversal: " << testTree.traverseInOrder();
    }
    cout << endl;

    /* Test removal */
    testTree.remove(0);
}


int main() {
    traversalTests();
    treeTests();

    return 0;
}
