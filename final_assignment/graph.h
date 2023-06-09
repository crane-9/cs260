#ifndef GRAPH_HEADER
#define GRAPH_HEADER

#include <map>
#include <string>
#include <utility>
#include <vector>

#include "player.h"


using std::string;


typedef std::map<string, std::pair<int, string> *> pathMap;

/// @brief Error thrown when a graph already has a node of the given name.
class VertexTitleConflict : public std::exception {
    private: 
        string hint;

    public:
        VertexTitleConflict(string title);
        string what();
};


/// @brief Error thrown when a graph does not have a desired node.
class VertexNotFound : public std::exception {
    private:
        string hint;

    public: 
        VertexNotFound(string title);
        string what();
};


/// @brief Single node.
struct StoryNode {
    string (* callback)(StoryNode *, Player *);
    std::vector<std::pair<string, StoryNode *> *> connections;

    string title; // Short, unique.
    string description; // Long, doesn't need to be unique, likely will be.
    string tag; // Short, doesn't need to be unique.

    int visits = 0;

    /**
     * Constructs node.
     * @param _callback Node's callback
     * @param _description The node's narration.
     * @param _title Unique title for the node, may be omitted when used without a graph. 
     * @param _tag Optional tag for the node. Non-unique. Example: "END" to mark an ending.
    */
    StoryNode(string (* _callback)(StoryNode *, Player *), string _description, string _title = "", string _tag = "");

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
    void addArc(StoryNode *branch, string text = "Return.");

    /**
     * Get all connections and their reference message.
     * @return A menu of options for the player to refer to.
    */
    string getPaths();

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
        std::map<string, StoryNode *> vertices;

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
         * Adds a directioned arc between two nodes on the graph, from source to destination.
         * @param source The starting node.
         * @param destination The ending node.
         * @param text Narration for the connection.
         * @overload One overload to make a connection by node title, rather than the node object itself.
         * @return No return value.
        */
        void addArc(StoryNode *source, StoryNode *destination, string text = "");
        void addArc(string source, string destination);

        /**
         * Adds a vertex to the graph.
         * @param newVertex The new vertex to add to the graph.
         * @throws VertexTitleConflict if the given node's title conflicts with an existing vertex in the graph. 
         * @return No return value.
        */
        void addVertex(StoryNode *newVertex);

        /**
         * Adds many vertices to the graph, starting at the root and adding all recursively.
         * @param rootVertex The root node, or starting node.
         * @return No return value.
        */
        void addVertices(StoryNode *rootVertex);

        /**
         * Removes a vertex from the graph and deletes it forever.
         * @param title The title of the node.
         * @return No return--the vertex is deleted.
        */
        void deleteVertex(string title);

        /**
         * Gets a node by its unique title.
         * @param title Title of the desired node.
         * @throws VertexNotFound if node does not exist.
         * @return Pointer to the node with the desired title.
        */
        StoryNode *getByTitle(string title);

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
        string minSpanTree();

        /**
         * Calculates the shortest path to every (accessible) node from the given node.
         * @param nodeTitle The title of the source node.
         * @return A string describing the shortest paths from the given node to all other accessible nodes.
        */
        pathMap *shortestPath(string nodeTitle);

        /**
         * For debug purposes. Returns a string of all node titles and descriptions.
        */
        string showVertices();
};


#endif
