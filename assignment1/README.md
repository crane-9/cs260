# CS260 Assignment 1: Bag of Marbles

Below are my preliminary plans for `marbles.cpp`.

## Marble Representation

A marble will be represented by a single `int`: a hex value that could be translated to a color.

Example:
```cpp
int redMarble = 0xFF0000;
int blueMarble = 0x0000FF;
int magentaMarble = 0xFF00FF; 
```

---
## Bag Class

A bag will be its own class. Its capacity will be set upon construction, and it will be empty by default. The primary functionality of the bag is to hold marbles (by adding one at a time) and retrieve marbles (by drawing one at random).

Basic usage example: 
```cpp
Bag myBag(10);  // declaring a bag with a capacity of 10

myBag.addMarble(0x00FF00);  // add a lime marble
myBag.addMarble(0x00FFFF);  // add a cyan marble
myBag.addmarble(0xFF0000);  // add a red marble

int mysteryMarble = myBag.drawMarble();
```

I have some additional methods I'd like to implement in order to enhance a bag's functionality.

**Public methods:**
+ `void addMarble(int)`
+ `int drawMarble()`
+ `bool isFull()`
+ `int currentFill()`:  Returns the current number of non-empty spaces.
+ `void peek()`: Prints the current contents to the terminal (namely for ease of testing).

**Public attributes:**
+ `int capacity`: Total capacity, regardless of empty spaces.

**Private methods:**
- `void shuffle()`: Shuffles the contents of the bag.

**Private attributes:**
- `vector contents`: Holds the marbles.


---
## Exceptions

There are two custom exceptions I intend to implement:

1. `BagFullException`, which will be thrown on `Bag::addMarble()` if the bag is already full.
2. `BagEmptyException`, which will be thrown on `Bag::drawMarble()` if the bag is already empty.


---
## Tests

A handful of brainstormed tests, and their goal:

1. Placing a single marble in an empty bag, and retrieving it.
    - Validates the survival of the marble's value.
2. Placing three marbles in an empty bag, and retrieving three marbles.
    - Tests that a bag can hold multiple values at once.
3. Attempt to add a marble in a full bag, and catch the error.
    - Proves that the thrown error works as intended.
4. Attempt to draw from an empty bag, and catch the error.
    - Proves the error is thrown as intended.
    - Also, a chance to prove a distinction between the two errors.
5. Compare contents before and after shuffling a full bag. 
    - Ensures that the shuffle algorithm works.

I intend to write and run these tests in a separate file, `driver.cpp`.
