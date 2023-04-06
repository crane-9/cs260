#include <iostream>
#include <stdlib.h>

using namespace std;


class Marble {
    public:
        int r;
        int g;
        int b;
        string pattern;

        Marble(int _r, int _g, int _b, string _pattern = "solid") {
            r = _r;
            g = _g;
            b = _b;
            pattern = _pattern;
        };
};

class Bag {
    private:
        int capacity;
        Marble contents[];

    public:
        Bag(int _capacity) {
            capacity = _capacity;
            contents[_capacity] = {0};
        };

        ~Bag();

        void addMarble(Marble marble) {
            // adds a marble to the bag.
        };

        Marble pullMarble() {
            // pulls a random marble from the bag.
            int idx = rand() % capacity;
            Marble marble(30, 20, 3);
            return contents[idx];
        };

        void shake() {
            // shuffles the bag
        };

};

int main() {
    Marble marble1(40, 40, 40);

    cout << marble1.pattern << endl;
    cout << marble1.r << marble1.g << marble1.b << endl;

    return 0;
}
