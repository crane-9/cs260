/**
 * Driver file for `marbles.cpp`.
 * NOTE! Compile with `g++ driver.cpp marbles.cpp -o driver` from terminal.
*/
#include <iostream>
#include <vector>

#include "marbles.h"
using namespace marbles;

using namespace std;


/**
 * Places a single marble in an empty bag and retrieves it.
 * @return Pass/fail message.
*/
string singleMarbleTest() {
    const int testMarble = 0xFFFF00;
    int drawnMarble;

    Bag testBag(5);

    testBag.addMarble(testMarble);

    try {
        drawnMarble = testBag.drawMarble();
    } catch (EmptyBagError) {
        return "FAILED Marble not found.";
    }

    if (drawnMarble == testMarble) {
        return "PASSED Marble retrieved successfully.";
    } else {
        return "FAILED Retrieved marble does not match.";
    }
}


/**
 * Places three marbles in an empty bag, and retrieves three marbles.
 * @return Pass/fail message.
*/
string threeMarbleTest() {
    Bag testBag(3);

    int sampleMarbles[3] = {0x5BCEFA, 0xF5A9B8, 0xFFFFFF};

    try {
        for (int i; i < testBag.capacity; i++) {
            testBag.addMarble(sampleMarbles[i]);
        }
    } catch (FullBagError) {
        return "FAILED Bag could not fit three marbles.";
    }

    try {
        for (int i; i < testBag.capacity; i++) {
            testBag.drawMarble();
        }
    } catch (EmptyBagError) {
        return "FAILED Less than three marbles drawn from the bag.";
    }

    return "PASSED Three marbles drawn from the bag.";
}


/**
 * Attempts to add a marble to a full bag; catches the error.
 * @return Pass/fail message. 
*/
string catchFullErrorTest() {
    Bag testBag(1);

    testBag.addMarble(0xC6D4FF);

    try {
        testBag.addMarble(0x2DC2BD);
    } catch (FullBagError) {
        return "PASSED FullBagError caught.";
    }

    return "FAILED FullBagError not thrown.";
}


/**
 * Attempts to draw from an empty bag; catches the error.
 * @return Pass/fail message.
*/
string catchEmptyErrorTest() {
    Bag testBag(5);

    try {
        testBag.drawMarble();
    } catch (EmptyBagError) {
        return "PASSED EmptyBagError caught.";
    }

    return "FAILED EmptyBagError not thrown.";
}


/**
 * Compares contents before and after shuffling to prove functionality.
 * @return Pass/fail message.
*/
string shakeTest() {
    Bag testBag(10);
    int testMarbles[10] = {0X321325, 0X491133, 0X5F0F40, 0X7D092F, 0X9A031E, 0XB33E2C, 0XBF5C33, 0XCB793A, 0XE4AB44, 0XFCDC4D};

    for (int i; i < testBag.capacity; i++) {
        testBag.addMarble(testMarbles[i]);
    }

    string before = testBag.peek();

    testBag.shake();

    string after = testBag.peek();
    
    if (before == after) {
        return "FAILED Contents identical before and after shuffle.";
    } else {
        return "PASSED Contents changed before and after shuffle.";
    }
}


int main() {
    srand(time(NULL));

    cout << "Single marble test: " << singleMarbleTest() << endl;
    cout << "Three marble test: " << threeMarbleTest() << endl;
    cout << "Full bag test: " << catchFullErrorTest() << endl;
    cout << "Empty bag test: " << catchEmptyErrorTest() << endl;
    cout << "Shake test: " << shakeTest() << endl;
    
    cout << endl;

    return 0;
}
