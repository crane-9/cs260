#ifndef GRAPH_HEADER
#define GRAPH_HEADER

#include <string>
#include <utility>
#include <vector>

#include "player.h"


//using a template bc circular stuff and ugh yeah
template <typename T>
using labelledPair = std::pair<std::string, T>;


/// @brief Single node.
struct StoryNode {
    void (* callback)(StoryNode *, Player *);
    std::vector<labelledPair<StoryNode *> *> connections;

    std::string description;
    std::string tag;
    int visits = 0;

    /**
     * Constructs node.
     * @param _callback Node's callback
     * @param _description The node's narration.
     * @param _tag Optional unique tag for the node. 
    */
    StoryNode(void (* _callback)(StoryNode *, Player *), std::string _description, std::string _tag = "");

    /**
     * Destructs node and its connections.
    */
    ~StoryNode();

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
     * @throws No error thrown if the desired branch isn't found.
     * @param branch The old connection to break.
     * @return No return value.
    */
    void removeArc(StoryNode *branch);
};



/// @brief MapGraph class, manages story map.
class MapGraph {
    private:
        int size;
        std::vector<StoryNode *> vertices;

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
        void addDirectionedArc(StoryNode *source, StoryNode *destination);

        /**
         * Adds two arcs between two nodes. One from A to B, and one from B to A.
         * @param nodeA One node.
         * @param nodeB Another node.
         * @return No return value.
        */
       void addMutualArc(StoryNode *nodeA, StoryNode *nodeB);

        /**
         * Adds a vertex to the graph.
         * @param newVertex The new vertex to add to the graph.
         * @return No return value.
        */
        void addVertex(StoryNode *newVertex);

        /**
         * Gets a node by its tag.
         * @note Unique tags are not enforced, but expected to be unique. Only the first node with the given tag may be returned.
         * @param tag The tag of the desired node.
         * @return Pointer to that node.
        */
       StoryNode *getByTag(std::string tag);

        /**
         * Get the size of graph.
         * @return The number of vertices in the graph.
        */
        int getSize();

        /**
         * Getter for graph vertices. Intended use for test and debug.
         * @return 
        */
        StoryNode getVertices();

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
