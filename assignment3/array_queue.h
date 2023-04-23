#ifndef ARR_QUEUE_HEADER
#define ARR_QUEUE_HEADER

#include <string>


/// @brief Array-based queue. 
class ArrayQueue {
    private:
        int items[10];

        // Index for next item to pop.
        int frontIndex;

        // Index for next space to be filled.
        int tailIndex;

        // Flags
        bool _isEmpty, _isFull;

        /**
         * Private helper. Calculates and returns the next position in the array, 
         * with consideration for looping around once length is met.
         * @param idx Base index.
         * @return Next index.
        */
        int advanceIndex(int idx);

    public:
        const int CAPACITY = 10;

        /**
         * Constructs an empty array. 
        */
        ArrayQueue();

        /**
         * Add an value to the queue. Any integer.
         * @param value Integer to add to the queue.
        */
        void enqueue(int value);

        /**
         * Calculates and returns the queue's current length.
         * @return How many items are in the queue.
        */
        int length();
        
        /**
         * Remove the next item from the queue.
         * @return The next value in the queue.
        */
        int dequeue();
        
        /**
         * Preview the next item in the queue without removing from the queue.
         * @return The next value in the queue.
        */
        int peek();

        /// @return True if the queue is empty.
        bool isEmpty() const { return _isEmpty; }

        /// @return True if no items in the queue.
        bool isFull() const { return _isFull; }
};


#endif
