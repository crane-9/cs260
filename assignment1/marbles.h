/**
 * Header file for 'marbles.cpp'.
*/
#ifndef MARBLES_HEADER
#define MARBLES_HEADER

#pragma once

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

/**
 * Namespace for all things marbles.
 * 
 * Functions
 * - printMarble(int)
 * 
 * Classes
 * - Bag 
 * 
 * Exceptions
 * - FullBagError
 * - EmptyBagError
 * - BagCapacityError
*/
namespace marbles {
    // Raise on `Bag::addMarble()` when a Bag is full.
    class FullBagError : public std::exception {
        public:
            std::string what();
    };

    // Raise on `Bag::drawMarble()` when a Bag is empty.
    class EmptyBagError : public std::exception {
        public:
            std::string what();
    };

    // Raise on `Bag::Bag()` when given an inappropriate argument.
    class BagCapacityError : public std::exception {
        public: 
            std::string what();
    };


   /**
    * Formats and prints a marble -- no `endl`.
    * 
    * @param marble The `int` representing the marble. Expected in the range 0 - 16777215 [0x0 - 0xFFFFFF], however this is not enforced.
    * @return No return value. 
   */
   inline void printMarble(int marble) { std::cout << "Marble (#" << std::setw(6) << std::setfill('0') << std::hex << marble << ")"; };

    /**
     * The bag class emulates a bag of marbles with a limited size.
    */    
    class Bag {
        private: 
            const int EMPTY = -1;

            // Represents the bag's contents.
            std::vector<int> contents;

            /**
             * Private method for internal use only.
             * Replaces the marble with an empty space, then returns the marble.
             * 
             * @param idx The desired marble's index.
             * @return The desired marble.
            */
            int removeMarble(int idx);

        public: 
            int capacity;

            /**
             * Constructs a bag with the given *positive* capacity. 
             * Bag is empty on construction.
             * 
             * @param _capacity The bag's maximum capacity. An error will later raise if this capacity is violated.
             * @throws Throws `BagCapacityError` if the given maximum capacity is less than one (zero, or negative).
            */
            Bag(int _capacity);

            
           /**
             * Adds a marble to the bag by replacing an empty space.
             * 
             * @param marble The `int` representing the marble.
             * @throws Throws `FullBagError` if the bag cannot hold another marble.
             * @return No return value.
            */
            void addMarble(int marble);

            /**
             * Selects a random marble to remove from the bag, and then return.
             * 
             * @throws Throws `EmptyBagError` if there is not marble to return.
             * @return A randomly selected marble.
            */
            int drawMarble();

            /**
             * Checks the current filled spaces within a bag.
             * 
             * @return An `int` representing the count of non-empty spaces in the bag.
            */
            int currentFill();

            /**
             * @return True if the bag is full, false if not.
            */
            bool isFull();

            /**
             * @return True if the bag is empty, false if there are still marbles.
            */
            bool isEmpty();

            /**
             * Formats and prints the contents of the bag to the console on a single line.
             * 
             * @return No return value. For read-only contents, use `Bag::getContents()`.
            */
            void peek();

            /**
             * Shuffles the contents of the bag. Arbitrary, as `Bag::drawMarble()` already uses random chance.
            */
            void shake();

            /**
             * Read-only contents
             * 
             * @return Read-only vector for the bag's contents.
            */
            const std::vector<int>& getContents() const { return contents; }
    };
}

#endif
