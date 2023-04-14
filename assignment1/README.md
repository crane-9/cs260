# CS260 Assignment 1: Bag of Marbles

Documentation for `marbles.cpp`, updated throughout the process.

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
+ `string peek()`: Returns the current contents as a string (namely for ease of testing).
+ `void shake()`: Shuffles the order of the contents.
    * Not a very important method, as `drawMarble()` is already random.
+ `vector<int> getContents()`: Returns a read-only `contents`.

**Public attributes:**
+ `int capacity`: Total capacity, regardless of empty spaces.

**Private methods:**
- `int removeMarble(int)`: Removes a marble from a bag at the desired index, replacing it with an empty space. Returns the desired marble.

**Private attributes:**
- `vector<int> contents`: Holds the marbles.
    * Empty spaces in the bag will be represented by the value -1 in the vector, as it cannot be translated into a valid hex color. Example contents (`int`s inconsistently formatted for conceptual clarity):
    ```cpp
    {0x000000, 0xFF00FF, 0xFFFFFF, -1, -1, -1}
    ```


---
## Exceptions

There are two custom exceptions I intend to implement:

1. `FullBagError`, which will be thrown on `Bag::addMarble()` if the bag is already full.
2. `EmptyBagError`, which will be thrown on `Bag::drawMarble()` if the bag is already empty.


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


---
## Completed

My first two tests show the basic functionality for the assignment--adding and removing marbles from a bag (lines 18 and 44 of `driver.cpp`)

![Snapshot of lines 32-36 of `driver.cpp`](https://cdn.discordapp.com/attachments/799704269787496518/1095240133118267423/image.png)

The next two tests prove the error functionality.

On line 73's `catchFullErrorTest()`:

![Snapshot of lines 78-82 of `driver.cpp`](https://cdn.discordapp.com/attachments/799704269787496518/1095240834733064192/image.png)

And line 92's `catchEmptyErrorTest()`:

![Snapshot of lines 95-99 of `driver.cpp`](https://cdn.discordapp.com/attachments/799704269787496518/1095241221577908244/image.png)

I was able to implement bags with a functional capacity, and functional content management.
