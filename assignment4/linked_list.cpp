#include "linked_list.h"

#include <sstream>
#include <string>

using namespace std;


IndexError::IndexError(int data) {
    hint = data;
}

string IndexError::what() {
    stringstream message;
    message << "Invalid index. Index '" << hint << "' does not exist.";
    return message.str();
}


LinkedList::LinkedList() {
    firstNode = lastNode = nullptr;
    _length = 0;
}

Node* LinkedList::fetchNode(int idx) {
    Node* currentNode = firstNode;

    for (int i = 0; i != idx; i++) {
        currentNode = currentNode->next;
        
        if (currentNode == nullptr) {
            throw IndexError(idx);
        }
    }

    return currentNode;
}

void LinkedList::append(int newValue) {
    Node* newNode = new Node{newValue, nullptr, lastNode};
    
    // Only if there is a node to attach to.
    if (!isEmpty()) {
        lastNode->next = newNode;
    }

    lastNode = newNode;
    if (isEmpty()) {
        firstNode = newNode;
    }

    _length ++;
}

int LinkedList::count(int value) {
    Node* current = firstNode;
    int tally = 0;

    // Loop through and count every instance of the given value.
    while (current != nullptr) {
        if (current->value == value) {
            tally ++;
        }
        current = current->next;
    }
    
    return tally;
}

int LinkedList::get(int idx) {
    Node* wantedNode = fetchNode(idx);
    return wantedNode->value;
}

int LinkedList::index(int value) {
    Node* current = firstNode;
    int idx = 0;

    // Run through the whole list.
    while (current != nullptr) {
        if (current->value == value) {
            return idx; 
        }
        current = current->next;
        idx ++;
    }

    // If the value was never found.
    return -1;
}

void LinkedList::insert(int idx, int newValue) {
    Node* nextNode = firstNode;

    for (int i = 0; i < idx; i++) {
        if (nextNode->next == nullptr) {
            throw IndexError(idx);
        }

        nextNode = nextNode->next;
    }

    // Build new node.
    Node* newNode = new Node{newValue, nextNode, nextNode->prev};

    // Link respective nodes to the new node.
    if (newNode->next != nullptr) {
        newNode->next->prev = newNode;
    }

    if (newNode->prev != nullptr) {
        newNode->prev->next = newNode;
    }

    // Fix absolute pointers.
    if (idx == 0) {
        firstNode = newNode;
    } else if (idx == _length) {
        lastNode = newNode;
    }

    _length ++;
}

bool LinkedList::isEmpty() { return _length == 0; }

int LinkedList::pop(int idx) {
    Node* poppedNode = fetchNode(idx);

    // Darn your socks
    Node* previousNode = poppedNode->prev;
    Node* nextNode = poppedNode->next;

    previousNode->next = nextNode;
    nextNode->prev = previousNode;

    // Ding dong ditch
    int value = poppedNode->value;

    delete poppedNode;
    _length --;

    return value;
}

int LinkedList::replace(int idx, int newValue) {
    Node* currentNode = fetchNode(idx);

    // Swap values
    int oldValue = currentNode->value;
    currentNode->value = newValue;

    return oldValue;
}

string LinkedList::toString() {
    stringstream stringList;

    Node* current = firstNode;

    stringList << "[";
    while (current != nullptr) {
        stringList << current->value;
        current = current->next;

        if (current != nullptr) {
            stringList << ", ";
        }
    }

    stringList << "]";

    return stringList.str();
}
