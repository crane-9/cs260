/* scratch file for misc tests and experiments. */

#include <iostream>
#include <stdlib.h>

#include <algorithm>
#include <iterator>
#include <random>
#include <vector>

#include <time.h>

using namespace std;

// 04 07 2023

/// @brief learning how hex values operate in c++
void hexTest() {
    int value = -1;
    cout << "value is: " << hex << value << endl;
}

/// @brief shuffling a vector
void shuffleVector() {
    // copied from https://en.cppreference.com/w/cpp/algorithm/random_shuffle and altered.
    vector<int> testVector {45, 54, 87, 1, 100, 69};
 
    random_device rd;
    mt19937 g(rd());
 
    shuffle(testVector.begin(), testVector.end(), g);
 
    copy(testVector.begin(), testVector.end(), ostream_iterator<int>(cout, " "));
    cout << '\n';
}

/// @brief shuffle algorithm
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

/// @brief grab a random item off a vector
void randomFromVector() {
    vector<int> things{1, 2, 3, 4, 5};

    int idx;
    do {
        idx = rand() % things.size();
    } while (things[idx] > 3);

    cout << things[idx] << endl;
}

int main() {
    srand(time(NULL));

    // hexTest();

    // shuffleVector();
    // customShuffleVector();

    randomFromVector();

    return 0;
}
