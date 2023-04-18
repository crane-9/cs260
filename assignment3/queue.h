#ifndef MARBLES_HEADER
#define MARBLES_HEADER

#include <string>


/// @brief Raise on `LinkedQueue::dequeue()` and `LinkedQueue::peek()` when operating on an empty queue.
class EmptyQueueError : public std::exception {
    public:
        std::string what();
};


/// @brief Single-linked node.
struct Node {
    int value;
    Node* next;
};


/// @brief A queue designed in the spirit of linked lists. 
class LinkedQueue {
    private:
        Node* frontPtr;
        Node* backPtr;
        int _length;

    public:
        /**
         * Constructs a queue, empty by default.
        */
        LinkedQueue();

        /**
         * Get the next value in line.
         * 
         * @throws Throws EmptyQueueError if the queue is empty.
         * @return Integer value.
        */
        int dequeue();

        /**
         * Add a value to the end of the queue.
         * 
         * @param value The new value to register to the queue.
         * @return No return value.
        */
        void enqueue(int value);


        /**
         * @return True if the queue is empty, false otherwise.
        */
        inline bool isEmpty() { return _length == 0; };

        /**
         * Preview the next value in line. Does not remove the value from the queue.
         * @throws Throws EmptyQueueError if there is nothign to peek at.
         * @return The next integer in line.
        */
        int peek();
        
        /**
         * Read-only queue length.
         * @return Count of items in the queue.
        */
        int length() const { return _length; }
};


#endif
