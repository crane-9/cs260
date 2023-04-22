#include "linked_list.h"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;


string appendTest() {
    LinkedList testList;

    for (int i = 0; i < 10; i ++) {
        testList.append(i);
    }

    return testList.peek();
}


string getTest() {
    LinkedList testList;
    
    testList.append(4);
    testList.append(5);
    testList.append(6);
    testList.insert(2, 10);

    cout << testList.peek(); 
    stringstream message;
    message << "value is...." << testList.get(2);
    return message.str();
}


int main() {
    cout << appendTest() << endl;
    cout << getTest() << endl;

    return 0;
}
