# CS260 Assignment 2: Designing a List Data Structure

### Guidelines
> Based on what we know about linked lists, design a list data structure that allows us to add (insert) or remove (delete) values at a given location in the list (instead of the top of a stack or the front or back of a queue):
> 
> What functions are we likely to need for a list to function like this?
> 
> What values will we need to know about the structure for our list to function properly?

### Initial notes
1. `.insert()` to insert something at a specific location; `.remove()` to remove from a specific location. `.take()`, or a better name, to remove and return something from a given space on the list? could `.remove()` return the item? probably sure. maybe `.get()` doesn't remove the item.
    + `int remove(int)`
    + `void insert(int, int)`
    + `int get(int)`
    + `int replace(int, int)`????
2. `.length()` is always nice, and there may be `.capacity` as well.
3. as opposed to the queue, this list may need a filler "empty" value?

