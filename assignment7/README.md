# CS 260: Assignment 7: Hashtable

I have a simple hashtable and advanced hashtable. Each have their own header and implementation files, and share an error header and driver file.

To run `driver.cpp`:
```
g++ driver.cpp hashtable.cpp simplehash.cpp
```

## Designs

### SimpleHash

>`simplehash.cpp` and `simplehash.h`

My design for a simple array-based hashtable stores strings. Collisions are handled by overwriting the previous data, and the single hash method is very simple.

Its four main methods are:
- `void insert(string data)`: Inserts a single string into the table. This hashes, but does not check for collisions.
- `bool search(string data)`: Searches for a single string within the hash table. 
- `string position(int index)`: Searches for data within the hash table by index. (Necessary? No! But I had the thought, and it stays for now.)
- `string remove(string data)`: Removes data from the table, and returns it. Raises an error if the desired data is not found within the table.

`search()` and `remove()` both validate that the value is as desired.

Hashing, currently, will be a simple function:
```cpp
int value;
for (char i : data) {
    value += i;
}

return value % capacity;
```


### Advanced hash

> `hashtable.h` and `hashtable.cpp`

My design for my advanced hashtable builds directly off the simple hashtable. The key difference being that it handles collisions by double-hashing.

On `insert()`, double hash will be used to find a space that is empty.

On `search()` and `remove()`, double hash will be used to find a space that is equal to the given value. I will also need to account for and consider preventing the hashing from going on forever and detecting a full table, or fruitless search. 

To facilitate use of doublehashing, I will write a method called `findIndexOf()`. It will take two parameters, the first being the hashed data, and the second being the desired value to find the index of (expected either an empty space, or the data itself) (this might serve better as a boolean, but saves time to just be `EMPTY || data`). Either return an integer for the desired data's index, or raise an error if the data cannot be found.

For double-hashing, my first hash algorithm is identical to the original. My second hash algorithm calculates the sum of each letter's value multiplied by its position (starting at 1). 

> Example "Hello world": 'H' * 1 + 'e' * 2 + 'l' * 3 ...

I chose this algorithm because I wanted its results to have the least likely repeated collision between two values. Where the first hash algorithm results in collision for anagrams, this, I hope, will correct that.


### Tests

> `driver.cpp`

First, I'll test that the `insert()` method works. In order to avoid using the `search()` method (which could validate the present of a value, but is not yet tested), I'll implement a `print()` method within the hashtable class for the sake of debugging. After manually adding a value, I'll print and manually assure it's there.

Next, I can use `search()` and see if it agrees. Then once `search()` works, I'll use `remove()`. I will use `remove()` twice to ensure it raises the expected error.

Finally, I have `position()`, which I may still remove. But in the case of testing, I'll `insert()` a value with an expected index, and check that the same value is returned by calling `position()` with said known index.

For the advanced hash class, I'll have an additional test for handling collisions. Once I figure out how I want to handle collisions.


---
## Applications

A hashtable reminds me of a player inventory in a video game. It has a limited number of spaces, and is easy/efficient to access/search/remove. 
