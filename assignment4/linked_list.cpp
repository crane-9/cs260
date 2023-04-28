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
    // Flags
    bool isFirst, isLast;
    isFirst = isLast = false;
    
    // Node pointers we need to find.
    Node* previousNode;
    Node* nextNode;

    // Define node previous to the new node.
    if (idx == 0) { // Special case: front of the list.
        isFirst = true;
        previousNode = nullptr; 
    } else { // Default case, not the new front of the list.
        // If this throws an error, it throws an error!
        previousNode = fetchNode(idx - 1);
    }

    // Define next node.
    if (idx == _length) { // Special case: last of the list/behind the old end of the list. 
        isLast = true;
        nextNode = nullptr;
    } else if (previousNode != nullptr) { // If there's a previous node, it points us to the next.
        nextNode = previousNode->next;
    } else { // Special case part 2: in adding to the front of the list, the next node will be the old front of the list.
        nextNode = fetchNode(idx);
    }
    
    // Build new node.
    Node* newNode = new Node{newValue, nextNode, previousNode};

    // Update first/last pointers.
    if (isFirst) { firstNode = newNode; }
    else if (isLast) { lastNode = newNode; }

    _length ++;
}

bool LinkedList::isEmpty() { return _length == 0; }

string LinkedList::peek() {
    stringstream list;

    Node* current = firstNode;

    while (current != nullptr) {
        list << current->value << ", ";
        current = current->next;
    }

    return list.str();
}

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
