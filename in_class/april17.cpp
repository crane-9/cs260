#include <iostream>

using namespace std;


int getElement(int arr[], int length, int position);
//vs....
int getElementFromPointer(int *arr, int length, int position);

// ^ getElementFromPointer is maybe the better decision? arr[] vs *arr

void memoryQuirk() {
    int arr[5] = {1, 2, 3, 4, 5};
    int position = 3;

    // basic math.....
    cout << (position[arr] == arr[position]) << endl;
}


struct node {
    int data;
    node *next;
};


class Stack {
    // everythign is private by defualt...
    int top;
    node *storage[];

    public:
        void push(int);
        int pop();
        int peek();
};


int main() {
    memoryQuirk();
    return 0;
}
