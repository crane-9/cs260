/**
 * autosort list, following along in class, plus my own edits.
*/
#include <iostream>
#include <sstream>
#include <string>

using namespace std;


struct Node
{
    int data;
    Node* next;
};


class AutoList {
    private:
        Node* head;
        int _len;

    public:
        AutoList() {
            head = nullptr;
            _len = 0;
        }

        void insert(int data) {
            cout << toString() << endl;

            Node* newNode = new Node{data, nullptr};
            _len ++;

            // special cases? i think.
            if (head == nullptr) {
                head = newNode;
                return;
            } else if (data <= head->data) {
                newNode->next = head;
                head = newNode;
                
                return;
            } 

            // surf to find insertion point
            Node* current = head;

            while (current->next != nullptr && data > current->next->data) {
                current = current->next;
            }

            // darn socks
            newNode->next = current->next;
            current->next = newNode;
        }

        int length() const { return _len; }

        string toString() {
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

};


void shortInsertTest() {
    AutoList testList;

    cout << testList.toString() << endl;

    testList.insert(15);
    testList.insert(6);
    testList.insert(8);
    testList.insert(2);

    cout << testList.toString() << endl;
}


void longInsertTest() {
    AutoList testList;

    cout << testList.toString() << endl;

    for (int i = 10; i < 20; i ++) {
        testList.insert(i + 5);
        testList.insert(i - 5);
    }

    cout << testList.toString() << endl;
    cout << "length: " << testList.length();
}


int main() {
    shortInsertTest();
    longInsertTest();
    
    return 0;
}
