#ifndef GRAPH_HEADER
#define GRAPH_HEADER

#include <map>
#include <string>
#include <utility>
#include <vector>

#include "player.h"


/// @brief Error thrown when a graph already has a node of the given name.
class VertexTitleConflict : public std::exception {
    private: 
        std::string hint;

    public:
        VertexTitleConflict(std::string title);
        std::string what();
};


/// @brief Error thrown when a graph does not have a desired node.
class VertexNotFound : public std::exception {
    private:
        std::string hint;

    public: 
        VertexNotFound(std::string title);
        std::string what();
};


/// @brief Single node.
struct StoryNode {
    void (* callback)(StoryNode *, Player *);
    std::vector<std::pair<std::string, StoryNode *> *> connections;

    std::string title; // Short, unique.
    std::string description; // Long, doesn't need to be unique, likely will be.
    std::string tag; // Short, doesn't need to be unique.
    int visits = 0;

    /**
     * Constructs node.
     * @param _callback Node's callback
     * @param _description The node's narration.
     * @param _title Unique title for the node, may be omitted when used without a graph. 
    */
    StoryNode(void (* _callback)(StoryNode *, Player *), std::string _description, std::string _title = "");

    /**
     * Destructs node and its connections.
    */
    ~StoryNode();

    /**
     * Adds a new destination to the current node.
     * @param branch The new connection.
     * @param text The text to display for the player.
     * @return No return value.
    */
    void addArc(StoryNode *branch, std::string text = "");

    /**
     * Get all connections and their reference message.
     * @return A menu of options for the player to refer to.
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
        std::map<std::string, StoryNode *> vertices;

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
         * @param text Narration for the connection.
         * @return No return value.
        */
        void addDirectionedArc(StoryNode *source, StoryNode *destination, std::string text = "");

        /**
         * Adds a vertex to the graph.
         * @param newVertex The new vertex to add to the graph.
         * @throws VertexTitleConflict if the given node's title conflicts with an existing vertex in the graph. 
         * @return No return value.
        */
        void addVertex(StoryNode *newVertex);

        /**
         * Removes a vertex from the graph and deletes it forever.
         * @param title The title of the node.
         * @return No return--the vertex is deleted.
        */
        void deleteVertex(std::string title);

        /**
         * Gets a node by its unique title.
         * @param title Title of the desired node.
         * @throws VertexNotFound if node does not exist.
         * @return Pointer to the node with the desired title.
        */
        StoryNode *getByTitle(std::string title);

        /**
         * Get the size of graph.
         * @return The number of vertices in the graph.
        */
        inline int getSize() const { return size; }

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

        /**
         * For debug purposes. Prints all node titles and descriptions.
        */
        void showVertices();
};


#endif
