#include <algorithm>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <random>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

// EXCEPTIONS
class FullBagError : public std::exception {
    public: 
        string what() {
            return "Cannot add a marble to the bag: bag is full.";
        };
};

class EmptyBagError : public std::exception {
    public: 
        string what() {
            return "Cannot remove a marble from the bag: bag is empty.";
        }
};

// BAG CLASS
class Bag {
    private:
        const int EMPTY = -1;  // a  semi-arbitrary value that will indicate "empty"
        vector<int> contents;

        int removeMarble(int idx) {
            int marble = contents[idx];
            contents[idx] = EMPTY;
            
            return marble;
        }

    public:
        int capacity;

        Bag(int _capacity) : contents(_capacity) {
            capacity = _capacity;

            // initialize contents to 'EMPTY'
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
            throw FullBagError();
        }

        int drawMarble() {
            // raising 
            if (isEmpty()) {
                throw EmptyBagError();
            } else if (currentFill() == 1) {
                for (int i = 0; i < capacity; i++) {
                    if (contents[i] != EMPTY) {
                        return removeMarble(i);
                    }
                }
            }

            int idx;
            do {
                idx = rand() % capacity;
                cout << "loop. idx value: " << idx << endl;
            } while (contents[idx] == EMPTY);

            return removeMarble(idx);
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
                    cout << "Marble (#" << setw(6) << setfill('0') << hex << marbleSpace << ")" << sep;
                } else {
                    cout << "Empty space" << sep;
                }
            }
            
            cout << endl;
        }

        void shake() {
            // give the bag a shake!
            random_device randomDevice;
            mt19937 gen(randomDevice());
 
            shuffle(contents.begin(), contents.end(), gen);
        }

        const vector<int>& getContents() const {
            return contents;
        }
};

int main() {
    srand(time(NULL));  // ensure results will differ every time.
    
    // BAG TESTING
    Bag bag(5);

    // try {
    //     bag.drawMarble();
    // } catch (BagEmptyException bee) {
    //     cout << "uh oh! bag empty" << endl;
    // } catch (BagFullException bfe) {
    //     cout << "this is not gonna hpeppn!" << endl;
    // }
    
    int pretendMarbles[3] = {0xFF0000, 0x0000FF, 0xFFFFFF};
    
    for (int i = 0; i <= 3; i++) {
        bag.addMarble(pretendMarbles[i]);
    }

    bag.peek();
    

    int marble = bag.drawMarble();
    cout << "Marble (#" << setw(6) << setfill('0') << hex << marble << ")" << endl;

    bag.peek(); bag.shake(); bag.peek();


    return 0;
}
