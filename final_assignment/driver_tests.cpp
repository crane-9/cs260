// Tests for graph.h/cpp

#include <iostream>
#include <string>

#include "graph.h"

using namespace std;

// Empty callback
void eCB(StoryNode*, Player *) {}

void addVertexTest(MapGraph *graph) {
    auto node = new StoryNode(eCB, "A", "here is some data.");
    auto node2 = new StoryNode(eCB, "B", "here is some data.");
    auto node3 = new StoryNode(eCB, "C", "here is some data.");

    graph->addVertex(node);
    graph->addVertex(node2);
    graph->addVertex(node3);

    graph->showVertices();

    cout << graph->getByTag("D") << endl;
}

int main() {
    addVertexTest(new MapGraph());

    return 0;
}
