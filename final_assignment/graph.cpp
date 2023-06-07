#include <algorithm>
#include <sstream>
#include <string>
#include <utility>

#include "graph.h"

using std::pair, std::string, std::stringstream;


StoryNode::StoryNode(void (* _callback)(StoryNode *, Player *), string _description, string _tag) {
    callback = _callback;
    description = _description;
    tag = _tag;
}

StoryNode::~StoryNode() {
    for (labelledPair<StoryNode *> *arc : connections) {
        delete arc;
    }
    connections.clear();
}

void StoryNode::addArc(StoryNode *branch, string text) {
    // I will allow duplicates because I am working out how not to :]
    connections.push_back(new pair<string, StoryNode *>(text, branch));
}

string StoryNode::getPaths() {
    stringstream menu;

    for (int i = 0; i < connections.size(); ++i) {
        menu << "\n[" << i + 1 << "] " << connections[i]->first;
    }

    return menu.str();
}

void StoryNode::removeArc(StoryNode *branch) {
    for (int i = 0; i < connections.size(); ++i) {
        if (connections[i]->second == branch) {
            // Delete connection, and remove from list.
            delete connections[i]->second;
            connections.erase(connections.begin() + i);
            return;
        }
    }
    // If no matching node is found, I've elected to do nothing.
}


MapGraph::MapGraph() {
    size = 0;
}

MapGraph::~MapGraph() {
    for (StoryNode *node : vertices) {
        delete node;
    }
    vertices.clear();
}

void MapGraph::addDirectionedArc(StoryNode *source, StoryNode *destination) {
    source->addArc(destination);
}

void MapGraph::addMutualArc(StoryNode *nodeA, StoryNode *nodeB) {
    addDirectionedArc(nodeA, nodeB);
    addDirectionedArc(nodeB, nodeA);
}

void MapGraph::addVertex(StoryNode *newVertex) {
    vertices.push_back(newVertex);
    ++size;
}

string MapGraph::minSpanTree(StoryNode *source) {
    return "";
}

string MapGraph::shortestPath() {
    return "";
}
