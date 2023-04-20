#include <string>


class EmptyQueueError : public std::exception {
    public:
        std::string what() { return "Queue is empty, cannot dequeue or peek. "; };
};

/// ArrayQueue exclusive. Raise on enqueue when queue is full.
class FullQueueError : public std::exception {
    public:
        std::string what() { return "Queue is full, cannot enqueue."; }
};

