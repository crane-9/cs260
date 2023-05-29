#ifndef GRAPH_HEADER
#define GRAPH_HEADER


/// @brief Single node, up to three connections because I say so.
struct GraphNode {
    int value;
    GraphNode *connections[5]; //???? maybe
};


/// @brief Graph class, manages graph nodes and subgraphs.
class Graph {
    private:

    public:

};

#endif
