#include <iostream>
#include <sstream>
#include <string>

#include "autosort_list.h"

using namespace std;


ValueNotFoundError::ValueNotFoundError(int data) {
    hint = data;
}


string ValueNotFoundError::what() {
    stringstream message;
    message << "Value '" << hint << "' not found in list.";
    return message.str();
}


AutoList::AutoList() {
    head = nullptr;
    _len = 0;
}


int AutoList::index(int value) { // O(n)
    // Start at index 0, head of the list.
    int idx = 0;

    for (Node *current = head; current != nullptr; current = current->next) { // O(n)
        // If data is larger than the value, the value is not in the list.
        if (current->data > value) {
            break;
        } else if (current->data == value) {  // Value has been found.
            return idx;
        }

        // Else, value has not yet been found, but may exist.
        idx ++;
    }
    
    throw ValueNotFoundError(value);
}


void AutoList::insert(int data) { // O(n)
    Node* newNode = new Node{data, nullptr};
    _len ++;

    // Cases where the new node goes in the front.
    if (head == nullptr) {
        // If list was previously empty.
        head = newNode;
        return;
    } else if (data <= head->data) { // Or if the value is already the smallest on the list.
        newNode->next = head;
        head = newNode;
        
        return;
    } 

    // Surf to find insertion point
    Node* current = head;

    while (current->next != nullptr && data > current->next->data) { // O(n)
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}


int AutoList::remove(int value) {
    Node *current = head;

    while (current != nullptr) { // O(n)
        // If data is greater than the given value, value is not going to be in the list.
        if (current->data > value) {
            throw ValueNotFoundError(value);
        
        // What we are looking for: 
        } else if (current->next->data == value) {
            break;
        }

        current = current->next;
    }

    // Because there are two loop exit conditions:
    if (current == nullptr) {
        throw ValueNotFoundError(value);
    }

    // Return value
    int retValue = current->next->data;

    // Darn socks.
    Node *newNext = current->next->next;
    delete current->next;

    current->next = newNext;

    _len --;
    return retValue; // In the end this is the exact value that was passed as a parameter, but a real database would probably have more to return.
}


string AutoList::toString() {  // O(n)
    stringstream stringList;

    stringList << "[";

    Node* current = head;
    while (current != nullptr) {
        stringList << current->data;
        
        if (current->next != nullptr) {
            stringList << ", ";
        }
        current = current->next;
    }

    stringList << "]";

    return stringList.str();
}
