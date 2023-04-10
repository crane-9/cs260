/**
 * Driver file for `marbles.cpp`.
 * Runs a series of fun tests :]
*/
#include <iostream>
#include <vector>

#include "marbles.h"
using namespace marbles;

using namespace std;


/**
 * Places a single marble in an empty bag and retrieves it.
 * 
 * @return True if passed.
*/
bool singleMarbleTest() {
    const int testValue = 0xFFFF00;
    Bag testBag(5);

    int myMarble = testValue;
    testBag.addMarble(myMarble);

    int drawnMarble = testBag.drawMarble();
    return drawnMarble == testValue; 
}


/**
 * Places three marbles in an empty bag, and retrieves three marbles.
*/
bool threeMarbleTest() {
    Bag testBag(3);

    int sampleMarbles[3] = {0x5BCEFA, 0xF5A9B8, 0xFFFFFF};

    for (int i; i < testBag.capacity; i++) {
        testBag.addMarble(sampleMarbles[i]);
    }

    try {
        for (int i; i < testBag.capacity; i++) {
            testBag.drawMarble();
        }
    } catch (EmptyBagError) {
        return false;
    }

    return true;
}


/**
 * Attempts to add a marble to a full bag; catches the error.
 * 
 * @return True if passed. 
*/
bool catchFullErrorTest() {
    Bag testBag(1);

    testBag.addMarble(0xC6D4FF);

    try {
        testBag.addMarble(0x2DC2BD);
    } catch (FullBagError) {
        return true;
    }

    return false;
}


/**
 * Attempts to draw from an empty bag; catches the error.
 * 
 * @return True if passed.
*/
bool catchEmptyErrorTest() {
    Bag testBag(5);

    try {
        testBag.drawMarble();
    } catch (EmptyBagError) {
        return true;
    }

    return false;
}


/**
 * Compares contents before and after shuffling to prove functionality.
 * 
 * @return True if passed.
*/
bool shakeTest() {
    Bag testBag(10);
    int testMarbles[10] = {0X321325, 0X491133, 0X5F0F40, 0X7D092F, 0X9A031E, 0XB33E2C, 0XBF5C33, 0XCB793A, 0XE4AB44, 0XFCDC4D};

    for (int i; i < testBag.capacity; i++) {
        testBag.addMarble(testMarbles[i]);
    }

    const vector<int> stageOne = testBag.getContents();

    testBag.shake();

    const vector<int> stageTwo = testBag.getContents();

    for (int i; i < testBag.capacity; i++) {
        if (stageOne[i] != stageTwo[i]) {
            return true;
        }
    }

    return false;
}


int main() {
    Bag bag(3);

    int testMarbles[10] = {0X321325, 0X491133, 0X5F0F40, 0X7D092F, 0X9A031E, 0XB33E2C, 0XBF5C33, 0XCB793A, 0XE4AB44, 0XFCDC4D};

    for (int i; i < bag.capacity; i++) {
        bag.addMarble(testMarbles[i]);
    }

    try {
        cout << bag.drawMarble();
    } catch (exception e) {
        cout << e.what() << endl;
    } 
    
    
    // temporary test outputs
    // cout << singleMarbleTest();
    // cout << threeMarbleTest();
    // cout << catchFullErrorTest();
    // cout << catchEmptyErrorTest();
    // cout << shakeTest();
    
    // cout << endl;

    return 0;
}
