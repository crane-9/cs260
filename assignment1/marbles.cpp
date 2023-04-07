#include <iostream>
#include <stdlib.h>
#include <vector>
#include <iomanip>

using namespace std;


// EXCEPTIONS
class BagFullException : public std::exception {
    public: 
        string what() {
            return "Cannot add a marble to the bag: bag is full.";
        };
};

class BagEmptyException : public std::exception {
    public: 
        string what() {
            return "Cannot remove a marble from the bag: bag is empty.";
        }
};

// BAG CLASS
class Bag {
    private:
        const int EMPTY = -1;

        vector<int> contents;

        void shuffle() {
            // shuffles the bag
        }

    public:
        int capacity;

        Bag(int _capacity) : contents(_capacity) {
            capacity = _capacity;

            for (int i = 0; i < contents.size(); i++) {
                contents[i] = EMPTY;
            }
        }

        void addMarble(int marble) {
            // adds a marble to the bag.
            for (int i = 0; i < capacity; i++) {
                if (contents[i] == EMPTY) {
                    contents[i] = marble;
                    return;
                }
            }

            // no marble has been added
            throw BagFullException();
        }

        int drawMarble() {
            // raising 
            if (isEmpty()) {
                throw BagEmptyException();
            }

            int idx;
            do {
                idx = rand() % capacity;
            } while (contents[idx] == EMPTY);
            
            int marble = contents[idx];
            contents[idx] = EMPTY;

            return marble;
        }

        int currentFill() {
            int filledSpaces = 0;
            
            for (int i = 0; i < capacity; i++) {
                if (contents[i] != EMPTY) {
                    filledSpaces ++;
                }
            }

            return filledSpaces;
        }

        bool isFull() {
            return currentFill() == capacity;
        }

        bool isEmpty() {
            return currentFill() == 0;
        }
        
        void peek() {
            const string sep = ", ";

            cout << "Bag contents: ";

            for (int i = 0; i < contents.size(); i++) {
                int marbleSpace = contents[i];

                if (marbleSpace != EMPTY) {
                    cout << "Marble (#" << setw(6) << setfill('0') << hex << marbleSpace<< ")" << sep;
                } else {
                    cout << "Empty space" << sep;
                }
            }
            
            cout << endl;
        }
};

int main() {
    // bag test
    Bag bag(5);
    bag.peek();

    try {
        bag.drawMarble();
    } catch (BagEmptyException bee) {
        cout << "uh oh! bag empty" << endl;
    } catch (BagFullException bfe) {
        cout << "this is not gonna hpeppn!" << endl;
    }
    
    int pretendMarbles[3] = {0xFF0000, 0x0000FF, 0xFF00FF};
    
    for (int i = 0; i <= 3; i++) {
        bag.addMarble(pretendMarbles[i]);
    }

    bag.peek();

    return 0;
}
