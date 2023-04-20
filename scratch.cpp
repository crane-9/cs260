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


// 04 20 2023
void parseArgs(int argc, char* argv[]) {
    bool testOne, testTwo;
    if (argc == 2) {
        string arg = string(argv[1]);

        if (arg != "one" && arg != "two") {
            cout << "Nonsense argument: accept 'one' and 'two'. Not \"" << arg << "\"" << endl;
            return;
        }

        testOne = arg == "one";
        testTwo = arg == "two";
    } else {
        testOne = testTwo = true;
    }

    cout << "One: " << testOne << endl; 
    cout << "Two: " << testTwo << endl;
}


void parseInput() {
    /// taken from https://www.digitalocean.com/community/tutorials/compare-strings-in-c-plus-plus
    string str_inp1;
	string str_inp2;

	cout << "Enter the String 1:\n";
	cin >> str_inp1;
	cout << "Enter the String 2:\n";
	cin >> str_inp2;

	if (str_inp1 == str_inp2)
		cout << "Strings are equal" << endl;
	else
		cout << "Strings are not equal" << endl;
}


int main(int argc, char* argv[]) {
    // srand(time(NULL));

    // hexTest();

    // shuffleVector();
    // customShuffleVector();

    // randomFromVector();

    parseArgs(argc, argv);
    // parseInput();

    return 0;
}
