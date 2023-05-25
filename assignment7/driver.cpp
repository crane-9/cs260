#include <iostream>
#include <sstream>
#include <string>

#include "hashtable.h"

using namespace std;


string insertionTest(Hashtable ht) {
    ht.insert("HI THERE");

    ht.display();
    
    return "passed?";
}

string positionTest(Hashtable ht) {

    return "";
}

string removalTest(Hashtable ht) {

    return "";
}

string searchTest(Hashtable ht) {

    return "";
}


int main() {
    Hashtable table;

    cout << insertionTest(table) << endl;
    // cout << positionTest(table) << endl;
    // cout << removalTest(table) << endl;
    // cout << searchTest(table) << endl;

    return 0;
}
