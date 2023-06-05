#ifndef GRAPH_HEADER
#define GRAPH_HEADER

#include <map>
#include <string>
#include <utility>
#include <vector>

#include "player.h"


/// @brief Single node.
struct StoryNode {
    void (* callback)(StoryNode *, Player *);
    std::vector<std::pair<std::string, StoryNode *> *> connections;

    std::string tag;
    std::string title;
    std::string narration;
    int visits = 0;

    /**
     * Constructs node.
     * @param _narration The node's narration.
     * @param _tag A tag for the node. 
    */
    StoryNode(std::string _narration, std::string _tag = "");
    
    /**
     * Adds a new destination to the current node.
     * @param branch The new connection.
     * @param text The text to display for the user.
     * @return No return value.
    */
    void addArc(StoryNode *branch, std::string text = "?");

    /**
     * Get all connections and their reference message.
     * @return A menu of options for the user to refer to.
    */
    std::string getPaths();

    /**
     * Removes a branch from the current node's connections.
     * @param branch The old connection to break.
     * @return No return value.
    */
    void removeArc(StoryNode *branch);
};


typedef std::map<std::string, StoryNode *> nodeMap;

/// @brief MapGraph class, manages story map.
class MapGraph {
    private:
        int size;
        nodeMap vertices;

    public:
        /**
         * Constructs an empty graph.
        */
        MapGraph();

        /**
         * Safely destructs graph and graph data.
        */
        ~MapGraph();

        /**
         * Adds an arc between two nodes on the graph, from source to destination.
         * @param source The starting node.
         * @param destination The ending node.
         * @return No return value.
         * @overload Overloaded to refer to nodes by name rather than the nodes themselves.
        */
        void addArc(StoryNode *source, StoryNode *destination);

        /**
         * Adds a vertex to the graph.
         * @param newVertex The new vertex to add to the graph.
         * @return No return value.
        */
        void addVertex(StoryNode *newVertex);

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
        std::string minSpanTree(StoryNode *source);

        /**
         * Calculates the shortest path to every (accessible) node from the given node.
         * @return A string describing the shortest paths from the given node to all other accessible nodes.
        */
        std::string shortestPath();
};


#endif
