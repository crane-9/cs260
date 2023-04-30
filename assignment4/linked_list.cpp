#include "linked_list.h"

#include <sstream>
#include <string>

using namespace std;


IndexError::IndexError(int data) { // O(1)
    hint = data;
}

string IndexError::what() { // O(1)
    stringstream message;
    message << "Invalid index. Index '" << hint << "' does not exist.";
    return message.str();
}


LinkedList::LinkedList() { // O(1)
    firstNode = lastNode = nullptr;
    _length = 0;
}

Node *LinkedList::fetchNode(int idx) { // O(n)
    Node *currentNode = firstNode; // O(1)

    // Cycle through until the wanted index is reached.
    for (int i = 0; i != idx; i++) { // O(n)
        currentNode = currentNode->next; // O(1)
        
        // Throw error if the index is out of range.
        if (currentNode == nullptr) { // O(1)
            throw IndexError(idx); // O(1)
        }
    }

    return currentNode;
}

void LinkedList::append(int newValue) { // O(1)
    Node *newNode = new Node{newValue, nullptr, lastNode}; // O(1)
    
    // Only if there is a node to attach to.
    if (!isEmpty()) {
        lastNode->next = newNode;
    } // O(1)

    lastNode = newNode; // O(1)
    if (isEmpty()) {
        firstNode = newNode;
    } // O(1)

    _length ++; // O(1)
}

int LinkedList::count(int value) { // O(n)
    Node *current = firstNode; // O(1)
    int tally = 0; // O(1)

    // Loop through and count every instance of the given value.
    while (current != nullptr) { // O(n)
        if (current->value == value) { // O(1)
            tally ++; // O(1)
        }
        current = current->next; // O(1)
    }
    
    return tally; // O(1)
}

int LinkedList::get(int idx) { // O(n)
    Node *wantedNode = fetchNode(idx); // O(n)
    return wantedNode->value; // O(1)
}

int LinkedList::index(int value) { // O(n)
    Node *current = firstNode; // O(1)
    int idx = 0; // O(1)

    // Run through the whole list.
    while (current != nullptr) { // O(n)
        if (current->value == value) {
            return idx; 
        } // O(1)
        current = current->next; // O(1)
        idx ++; // O(1)
    }

    // If the value was never found.
    return -1; // O(1)
}

void LinkedList::insert(int idx, int newValue) { // O(n)
    // Get the node currently at `idx`
    Node *nextNode = fetchNode(idx); // O(n)

    // Build new node.
    Node *newNode = new Node{newValue, nextNode, nextNode->prev}; // O(1)

    // Link respective nodes to the new node.
    if (newNode->next != nullptr) { 
        newNode->next->prev = newNode;
    } // O(1)

    if (newNode->prev != nullptr) {
        newNode->prev->next = newNode;
    } // O(1)

    // Fix absolute pointers.
    if (idx == 0) {
        firstNode = newNode;
    } else if (idx == _length) {
        lastNode = newNode;
    } // O(1)

    _length ++; // O(1)
}

bool LinkedList::isEmpty() { return _length == 0; } // O(1)

int LinkedList::pop(int idx) { // O(n)
    Node *poppedNode = fetchNode(idx); // O(n)

    // Retrieve adjacent nodes. // O(1)
    Node *previousNode = poppedNode->prev;
    Node *nextNode = poppedNode->next;

    // Close the gap. // O(1)
    previousNode->next = nextNode;
    nextNode->prev = previousNode;

    // Retrieve the value. // O(1)
    int value = poppedNode->value;

    // Alter list. // O(1)
    delete poppedNode;
    _length --;

    return value;
}

int LinkedList::replace(int idx, int newValue) { // O(n)
    Node *currentNode = fetchNode(idx); // O(n)

    // Swap values // O(1)
    int oldValue = currentNode->value;
    currentNode->value = newValue;

    return oldValue; // O(1)
}

string LinkedList::toString() { // O(n)? Depending on implementation of stringstream.str()!
    stringstream stringList; // O(1)

    Node *current = firstNode; // O(1)

    stringList << "["; // O(1)
    while (current != nullptr) {
        stringList << current->value;
        current = current->next;

        if (current != nullptr) {
            stringList << ", ";
        }
    } // O(n)

    stringList << "]"; // O(1)

    return stringList.str(); // O(?)
}
