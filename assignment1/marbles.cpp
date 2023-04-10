/**
 * Implements the classes and functions declared in 'marbles.h'.
 * 
 * Documentation in 'marbles.h'.
*/
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <random>
#include <stdlib.h>
#include <string>
#include <vector>

#include "marbles.h"
using namespace marbles;

using namespace std;


string FullBagError::what() {
    return "Cannot add a marble to the bag: bag is full.";
}


string EmptyBagError::what() {
    return "Cannot remove a marble from the bag: bag is empty.";
}


string BagCapacityError::what() {
    return "A bag's capacity must be a positive integer.";
}


Bag::Bag(int _capacity): contents(_capacity) {
        if (_capacity < 1) {
            throw BagCapacityError();
        }

        capacity = _capacity;

        for (int i = 0; i < contents.size(); i++) {
            contents[i] = EMPTY;
        }
}


int Bag::removeMarble(int idx) {
    int marble = contents[idx];
    contents[idx] = EMPTY;
    
    return marble;
}


void Bag::addMarble(int marble) {
    for (int i = 0; i < capacity; i++) {
        if (contents[i] == EMPTY) {
            contents[i] = marble;
            return;
        }
    }

    // If reached, no marble has been added.
    throw FullBagError();
}


int Bag::drawMarble() {
    // Preliminary checks make life a little easier.
    if (isEmpty()) {
        throw EmptyBagError();
    } else if (currentFill() == 1) {
        for (int i = 0; i < capacity; i++) {
            if (contents[i] != EMPTY) {
                return removeMarble(i);
            }
        }
    }

    // If there are two or more marbles in the bag, selection is random.
    int idx;
    do {
        idx = rand() % capacity;
    } while (contents[idx] == EMPTY);

    return removeMarble(idx);
}


int Bag::currentFill() {
    int filledSpaces = 0;
    
    for (int i = 0; i < capacity; i++) {
        if (contents[i] != EMPTY) {
            filledSpaces ++;
        }
    }

    return filledSpaces;
}


bool Bag::isFull() {
    return currentFill() == capacity;
}


bool Bag::isEmpty() {
    return currentFill() == 0;
}


void Bag::peek() {
    const string sep = ", ";  // character separating each marble space
    cout << "Bag contents: ";

    for (int i = 0; i < contents.size(); i++) {
        int marbleSpace = contents[i];

        if (marbleSpace != EMPTY) {
            printMarble(marbleSpace);
        } else {
            cout << "Empty space";
        }
        cout << sep;
    }
    
    cout << endl;
}


void Bag::shake() {
    random_device randomDevice;
    mt19937 gen(randomDevice());

    shuffle(contents.begin(), contents.end(), gen);
}
