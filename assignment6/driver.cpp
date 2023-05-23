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
    testTree.add(2);

    if (testTree.traverseInOrder() == "0, 2, 3, 5, ") {
        cout << "PASSED Adding value to tree works as expected.";
    } else {
        cout << "FAILED Ordered tree expected to have a root of 3 and branch of 5, 0, and 1 [in order added]. In order traversal: " << testTree.traverseInOrder();
    }
    cout << endl << endl;

    /* Test search method. */
    bool testOne, testTwo;
    
    testOne = testTree.search(5) == true; // Expected results
    testTwo = testTree.search(1) == false;

    if (testOne && testTwo) {
        cout << "PASSED Search method works for present and missing values.";
    } else if (testOne) {
        cout << "FAILED Search method returns 'true' for both present and missing values.";
    } else if (testTwo) {
        cout << "FAILED Search method returns 'false' for boeth present and missing values.";
    } else {
        cout << "FAILED Search method returns inverted results.";
    }
    cout << endl << endl;

    /* Test removal -- one child. */
    testTree.add(1); // To give 0 a child.
    testTree.remove(0);

    if (testTree.traverseInOrder() == "1, 2, 3, 5, ") {
        cout << "PASSED Removing node with single child worked as expected.";
    } else {
        cout << "FAILED Removal of single-child node failed. Current tree in order: " << testTree.traverseInOrder();
    }
    cout << endl;

    /* Test remove -- two children. */
    testTree.add(4); // To give 5 two children.
    testTree.add(6);
    testTree.remove(5);

    if (testTree.traverseInOrder() == "1, 2, 3, 4, 6, ") {
        cout << "PASSED Removing node with two children nodes works, as unexpected!";
    } else {
        cout << "FAILED Removal of node with two children failed. Current tree in order: " << testTree.traverseInOrder() << ". Should be: 1, 2, 3, 4, 6, ";
    }
    cout << endl;
}


int main() {
    traversalTests();
    cout << endl; // Blank line.

    treeTests();

    return 0;
}
