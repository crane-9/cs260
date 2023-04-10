#pragma once

#include <string>
#include <vector>

namespace marbles {
    class FullBagError : public std::exception {
        public:
            std::string what();
    };

    class EmptyBagError : public std::exception {
        public:
            std::string what();
    };


    class Bag {
        private: 
            const int EMPTY;
            std::vector<int> contents;

            int removeMarble(int idx);

        public: 
            int capacity;

            Bag(int _capacity);
            void addMarble(int marble);
            int drawMarble();
            int currentFill();
            bool isFull();
            bool isEmpty();
            void peek();
            void shake();
    };
}
