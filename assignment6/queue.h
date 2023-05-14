#ifndef LINK_QUEUE_HEADER
#define LINK_QUEUE_HEADER

#include <string>

#include "binary_tree.h"


/// @brief Single-linked node, specific for a queue.
template <class T>
struct QueueNode {
    T data;
    QueueNode<T>* next;
};


class EmptyQueueError : public std::exception {
    public:
        std::string what();
};


/// @brief A queue designed specifically for binary tree nodes.
class LinkedQueue {
    private:
        QueueNode<Node *> *frontPtr;
        QueueNode<Node *> *backPtr;
        int _length;

    public:
        /**
         * Constructs an empty queue.
        */
        LinkedQueue();

        /**
         * Get the next BST node in line.
         * 
         * @throws Throws EmptyQueueError if the queue is empty.
         * @return Integer value.
        */
        Node *dequeue();

        /**
         * Add a node to the end of the queue.
         * 
         * @param data The new node to register to the queue.
         * @return No return value.
        */
        void enqueue(Node *data);


        /**
         * @return True if 0 items in queue, false otherwise.
        */
        inline bool isEmpty() { return _length == 0; };

        /**
         * Preview the next data in line. Does not remove the data from the queue.
         * @throws Throws EmptyQueueError if there is nothign to peek at.
         * @return The next integer in line.
        */
        Node *peek();
        
        /**
         * Read-only queue length.
         * @return Count of items in the queue.
        */
        int length() const { return _length; }
};


#endif
