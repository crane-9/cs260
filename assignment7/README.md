# CS 260: Assignment 7: Hashtable

## Design

My design is for a simple array-based hashtable, which stores strings. Currently, collisions are handled by overwriting the previous data, and the single hash method is very simple.  

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


### Tests

In `driver.cpp`, I'll test each of my main methods.

First, I'll test that the insert method works. In order to avoid using the `search()` method (which could validate the present of a value, but is not yet tested), I'll implement a `print()` method within the hashtable class for the sake of debugging. After manually adding a value, I'll print and manually assure it's there.

Next, I can use `search()` and see if it agrees. Then once `search()` works, I'll use `remove()`. I will use `remove()` twice to ensure it raises the expected error.

Finally, I have `position()`, which I may still remove. But in the case of testing, I'll `insert()` a value with an expected index, and check that the same value is returned by calling `position()` with said known index.


## Applications

A hashtable reminds me of a player inventory in a video game. It has a limited number of spaces, and is easy/efficient to access/search/remove. 
