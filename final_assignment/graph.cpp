#include <sstream>
#include <string>
#include <utility>

#include "graph.h"

using std::pair, std::string, std::stringstream;


StoryNode::StoryNode(string _narration, string _tag) {
    narration = _narration;
    tag = _tag;

    visits = 0;
}

void StoryNode::addArc(StoryNode *branch, string text) {
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
            delete connections[i];
            return;
        }
    }
    // i guess it still shouldn't be going on at this point--throw error i guess.
}


MapGraph::MapGraph() {

}

MapGraph::~MapGraph() {

}

void MapGraph::addArc(StoryNode *source, StoryNode *destination) {

}

void MapGraph::addVertex(StoryNode *newVertex) {

}

string MapGraph::minSpanTree(StoryNode *source) {
    return "";
}

string MapGraph::shortestPath() {
    return "";
}
