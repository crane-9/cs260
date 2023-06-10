#include "graph.h"

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <string>
#include <utility>

#include "player.h"

using std::cout, std::endl, std::pair, std::string, std::stringstream;


string callbacks::eCB(StoryNode *n, MapGraph *g, Player *p) { return ""; }

// Exception implementations.

VertexTitleConflict::VertexTitleConflict(string title) {
    hint = title;
}

string VertexTitleConflict::what() {
    stringstream message;
    message << "Node '" << hint << "' already exists.";
    return message.str();
}

VertexNotFound::VertexNotFound(string title) {
    hint = title;
}

string VertexNotFound::what() {
    stringstream message;
    message << "Node '" << hint << "' could not be found within the graph.";
    return message.str();
}


// StoryNode implementations.

StoryNode::StoryNode(string (* _callback)(StoryNode *, MapGraph *, Player *), string _description, string _title, string _tag) {
    callback = _callback;
    description = _description;
    title = _title;
    tag = _tag;
}
StoryNode::StoryNode(string _description, string _title, string _tag) {
    callback = callbacks::eCB;
    description = _description;
    title = _title;
    tag = _tag;
}

StoryNode::~StoryNode() {
    for (auto arc : connections) {
        delete arc;
    }
    connections.clear();
}

void StoryNode::addArc(StoryNode *branch, string text) {
    // I will allow duplicates.
    connections.push_back(new pair<string, StoryNode *>(text, branch));
}

string StoryNode::getPaths() {
    stringstream menu;

    for (int i = 0; i < connections.size(); ++i) {
        // +1 to keep options > 0.
        menu << "\n[" << i + 1 << "] " << connections[i]->first;
    }

    return menu.str();
}

void StoryNode::removeArc(StoryNode *branch) {
    for (int i = 0; i < connections.size(); ++i) {
        if (connections[i]->second == branch) {
            // Delete connection, and remove from list.
            delete connections[i]->second;
            delete connections[i];
            connections.erase(connections.begin() + i);
            return;
        }
    }
    // If no matching node is found, I've elected to do nothing.
}


// MapGraph implementations.

MapGraph::MapGraph() {
    size = 0;
}

MapGraph::~MapGraph() {
    for (auto const& [label, node] : vertices) {
        delete node;
    }
    vertices.clear();
}

void MapGraph::addArc(StoryNode *source, StoryNode *destination, string text) {
    source->addArc(destination, text);
}

void MapGraph::addArc(string source, string destination, string text) {
    StoryNode *sourceNode = getByTitle(source);
    StoryNode *destinationNode = getByTitle(destination);

    sourceNode->addArc(destinationNode, text);
}

void MapGraph::addVertex(StoryNode *newVertex) {
    // Check that this doesn't override. Improper check because a value is going to be created here anyhow.
    if (vertices[newVertex->title] != 0) {
        throw VertexTitleConflict(newVertex->title);
    }

    // Add and increase size.
    vertices[newVertex->title] = (newVertex);
    ++size;
}

void MapGraph::addVertices(StoryNode *rootVertex) {
    // Only add if it has already been added.
    if (vertices[rootVertex->title] == 0) {
        addVertex(rootVertex);
    }

    // Add all connections.
    for (auto connection : rootVertex->connections) {
        addVertices(connection->second);
    }
}

StoryNode *MapGraph::getByTitle(string title) {
    // Check it.
    if (vertices.find(title) == vertices.end()) throw VertexNotFound(title);
    
    // Grab it.
    return vertices[title];
}

string MapGraph::minSpanTree() {
    return "";
}

pathMap *MapGraph::shortestPath(string nodeTitle) {
    std::map<string, bool> visited; // Tracks which nodes have been visited
    
    // This map holds path info. Node name mapped to the total distance and parent node.
    auto paths = new pathMap;
    for (auto items : vertices) {
        // "Infinite" distance (larger than anything expected) and no parent.
        (*paths)[items.first] = new pair<int, string>(size + 1, "");
    }

    (*paths)[nodeTitle]->first = 0;

    // Prepare and run Dijkstra's algorithm
    StoryNode *current;
    std::queue<StoryNode *> nodeQueue;
    nodeQueue.push(vertices[nodeTitle]);

    while (!nodeQueue.empty()) {
        current = nodeQueue.front(); nodeQueue.pop(); // Retrieve next node.

        // Skip if it has been visited.
        if (visited[current->title]) {
            continue;
        }

        // Add unvisited connections to queue.
        for (auto connection : current->connections) {
            StoryNode *node = connection->second;
            // Skip visited--possibly redundant, but this is safety.
            if (visited[node->title]) {
                continue;
            }
            
            // New distance based on parent node's distance.
            int distance = (*paths)[current->title]->first + 1;

            // Compare.
            if ((*paths)[node->title]->first > distance) {
                // Update distance and parent.
                (*paths)[node->title]->first = distance;
                (*paths)[node->title]->second = current->title;
            }

            nodeQueue.push(node);
        }

        // Mark as visited.
        visited[current->title] = true;
    }

    return paths;
}

string MapGraph::showVertices() {
    stringstream message;

    for (auto const& [label, node] : vertices) {
        message << label << ", ";
    }

    return message.str();
}
