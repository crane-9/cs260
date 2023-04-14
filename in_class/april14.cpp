#include <iostream>

using namespace std;


struct node {
    int data;
    node *prev;
    node *next;
};

node node0{0, nullptr};
node node1{1, &node0};
node node2{2, &node1};
node node3{3, &node2, nullptr};


int getElement(int arr[], int arrLength, int position) {
    if (position >= arrLength) {
        cout << "there may be an issue!" << endl;
    }
    return arr[position];
}


void nodeLoop() {
    node *current = &node0;

    while (current != nullptr) {
        cout << current->data << endl;
        
        current = current->next;
    }
}


int main() {
    // int myArray[5] = {1, 2, 3, 4, 5};
    // int arrayLength = sizeof myArray / sizeof myArray[0];
    // cout << getElement(myArray, arrayLength, 4) << endl;

    // these cannot be set outside the scope of a function!
    node0.next = &node1;
    node1.next = &node2;
    node2.next = &node3;

    // cout << node0.data << endl;
    // cout << node0.next << endl;
    // cout << node1.data << endl;
    // cout << node1.prev << endl;

    nodeLoop();


    return 0;
}
