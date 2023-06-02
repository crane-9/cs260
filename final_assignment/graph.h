#ifndef GRAPH_HEADER
#define GRAPH_HEADER

#include <map>
#include <string>


typedef std::map<std::string, GraphNode *> nodeMap;

/// @brief Single node, up to five connections because I say so.
struct GraphNode {
    GraphNode *connections[5] = {nullptr};

    std::string data;

    /**
     * Constructs node.
     * @param _data The node's data.
    */
    GraphNode(std::string _data);
    
    /**
     * Adds a new destination to the current node.
     * @param branch The new connection.
     * @return No return value.
    */
    void addArc(GraphNode *branch);

    /**
     * Removes a branch from the current node's connections.
     * @param branch The old collection to break.
     * @return No return value.
    */
    void removeArc(GraphNode *branch);
};


/// @brief Graph class, manages graph nodes and subgraphs.
class Graph {
    private:
        nodeMap vertices;

    public:
        /**
         * Constructs an empty graph.
        */
        Graph();

        /**
         * Safely destructs graph and graph data.
        */
        ~Graph();

        /**
         * Adds an arc between two nodes on the graph, from source to destination.
         * @param source The starting node.
         * @param destination The ending node.
         * @return No return value.
        */
        void addArc(GraphNode *source, GraphNode *destination);

        /**
         * Adds a vertext to the graph.
         * @param newVertex The new vertex to add to the graph.
         * @return No return value.
        */
        void addVertex(GraphNode *newVertex);

        /**
         * Get the size of graph.
         * @return The number of vertices in the graph.
        */
        int getSize();

        /**
         * Getter for graph vertices. Intended use for test and debug.
         * @return Map of node names to nodes.
        */
        nodeMap getVertices();

        /**
         * Calculates the graph's minimum spanning tree starting at the given node.
         * @param source The node to begin with.
         * @return A string describing the graph's minimum spanning tree.
        */
        std::string minSpanTree(GraphNode *source);

        /**
         * Calculates the shortest path to every (accessible) node from the given node.
         * @return A string describing the shortest paths from the given node to all other accessible nodes.
        */
        std::string shortestPath();
};


#endif
