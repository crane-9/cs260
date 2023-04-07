/* scratch file for misc tests and experiments. */

#include <iostream>
#include <stdlib.h>

#include <algorithm>
#include <iterator>
#include <random>
#include <vector>

using namespace std;

// 04 07 2023
void hexTest() {
    // learning how hex values operate in c++
    int value = 0xFF00FF;
    cout << "value is: " << hex << value << endl;
}

void shuffleVector() {
    // copied from https://en.cppreference.com/w/cpp/algorithm/random_shuffle and altered.
    vector<int> testVector {45, 54, 87, 1, 100, 69};
 
    random_device rd;
    mt19937 g(rd());
 
    shuffle(testVector.begin(), testVector.end(), g);
 
    copy(testVector.begin(), testVector.end(), ostream_iterator<int>(cout, " "));
    cout << '\n';
}

void customShuffleVector() {
    //copied from https://stackoverflow.com/questions/22850316/how-to-shuffle-elements-in-a-vector-randomly, minor adjustments
    
    vector<int> testVector {45, 54, 87, 1, 100, 69};
    
    // first shuffle
    for (int k = 0; k < testVector.size(); k++) {
        int r = k + rand() % (testVector.size() - k); // careful here!
        cout << r << " " << k << endl;
        swap(testVector[k], testVector[r]);
    }

    // THEN print
    for (int k = 0; k < testVector.size(); k++) {
        cout << testVector[k] << " ";
    }
    cout << endl;
}

int main() {
    // hexTest();

    shuffleVector();
    customShuffleVector();

    return 0;
}
