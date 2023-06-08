// Tests for graph.h/cpp

#include <iostream>
#include <string>

#include "graph.h"

using namespace std;

// Empty callback
void eCB(StoryNode*, Player *) {}

void addVertexTest(MapGraph *graph) {
    auto node = new StoryNode(eCB, "data", "A");
    auto node2 = new StoryNode(eCB, "data", "B");
    auto node3 = new StoryNode(eCB, "data", "C");

    graph->addVertex(node);
    graph->addVertex(node2);
    graph->addVertex(node3);

    graph->showVertices();

    // cout << graph->getByTag("D") << endl;
}

int main() {
    addVertexTest(new MapGraph());

    return 0;
}
