#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>

#include "graph.h"
#include "player.h"

using std::cout, std::endl, std::pair, std::string, std::stringstream;


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


StoryNode::StoryNode(void (* _callback)(StoryNode *, Player *), string _description, string _title) {
    callback = _callback;
    description = _description;
    title = _title;
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
    for (auto const& [label, node] : vertices) {
        delete node;
    }
    vertices.clear();
}

void MapGraph::addDirectionedArc(StoryNode *source, StoryNode *destination, string text) {
    source->addArc(destination, text);
}

void MapGraph::addVertex(StoryNode *newVertex) {
    if (vertices[newVertex->title] != 0) {
        throw VertexTitleConflict(newVertex->title);
    }

    vertices[newVertex->title] = (newVertex);
    ++size;
}

void MapGraph::deleteVertex(string title) {
    if (vertices[title] == 0) {
        throw VertexNotFound(title);
    }

    delete vertices[title];
    --size;
}

StoryNode *MapGraph::getByTag(string tag) {
    for (auto const& [label, node] : vertices) {
        if (node->tag == tag) {
            return node;
        }
    }

    throw VertexNotFound("#" + tag);
}

StoryNode *MapGraph::getByTitle(string title) {
    return vertices[title];
}

string MapGraph::minSpanTree(StoryNode *source) {
    return "";
}

string MapGraph::shortestPath() {
    return "";
}

void MapGraph::showVertices() {
    for (auto const& [label, node] : vertices) {
        cout << label << ", ";
    }
    cout << endl;
}
