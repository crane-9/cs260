// Tests for graph.h/cpp

#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <utility>

#include "graph.h"

using namespace std;


// Complex graph generator.
GraphMap *makeSampleGraph() {
    auto graph = new GraphMap();

    graph->addVertex(new StoryNode("", "A"));
    graph->addVertex(new StoryNode("", "B"));
    graph->addVertex(new StoryNode("", "C"));
    graph->addVertex(new StoryNode("", "D"));
    graph->addVertex(new StoryNode("", "E"));
    graph->addVertex(new StoryNode("", "F"));
    graph->addVertex(new StoryNode("", "G"));
    graph->addVertex(new StoryNode("", "H"));
    graph->addVertex(new StoryNode("", "I"));
    graph->addVertex(new StoryNode("", "J"));
    
    graph->addVertex(new StoryNode("", "X"));
    graph->addVertex(new StoryNode("", "Y"));
    graph->addVertex(new StoryNode("", "Z"));

    graph->addArc("A", "B"); graph->addArc("B", "A");
    graph->addArc("B", "C");
    graph->addArc("C", "D");
    graph->addArc("C", "G");
    graph->addArc("D", "A");
    graph->addArc("D", "E");
    graph->addArc("E", "F");
    graph->addArc("G", "H");
    graph->addArc("H", "F");
    graph->addArc("H", "I");
    graph->addArc("I", "J");
    graph->addArc("J", "H");

    graph->addArc("X", "Y"); graph->addArc("Y", "X");

    return graph;
}


// Unit tests

/// @brief Tests a graph's addVertex() method, returns pass/fail message.
string addVertexTest(GraphMap *graph) {
    graph->addVertex(new StoryNode("data", "A"));
    graph->addVertex(new StoryNode("data", "B"));
    graph->addVertex(new StoryNode("data", "C"));

    string result = graph->showVertices();
    if (result == "\"A\", \"B\", \"C\", ") {
        return "PASSED All nodes added to graph successfully.";
    }

    stringstream message;
    message << "FAILED Expected: '\"A\", \"B\", \"C\", '. graph.showVertices(): '" << result << "'";
    return message.str();
}


/// @brief Tests a graph's addArc() method, returns a pass/fail message.
string addArcTest(GraphMap *graph) {
    return "";
}


/// @brief Tests a graph addVertices() method, returns pass/fail message.
string addVerticesTest(GraphMap *graph) {
    return "";
}


string shortestPathTest(GraphMap *sampleGraph) {
    pathMap *shortestPaths = sampleGraph->shortestPath("C");

    stringstream results;

    results << "SHORTEST PATHS FROM NODE 'C':\n";

    for (auto const& [nodeTitle, data] : (*shortestPaths)) {
        results << "\t";
        results << nodeTitle << " - ";
        if (data->first == sampleGraph->getSize() + 1) {
            results << "NO PATH";
        } else {
            results << data->first << " STEP ";
        }

        if (data->second != "") {
            results << "[PARENT '" << data->second << "']";
        }

        results << "\n";
    }

    delete shortestPaths;

    return results.str();
}


string minSpanTreeTest(GraphMap *sampleGraph) {
    return sampleGraph->minSpanTree();
}



int main() {
    GraphMap *graph = new GraphMap();

    cout << addVertexTest(graph) << endl;
    cout << addArcTest(graph) << endl;
    cout << addVerticesTest(graph) << endl;

    delete graph;

    // Build complex graph. Tree tests.
    GraphMap *compGraph = makeSampleGraph();

    cout << shortestPathTest(compGraph) << endl;    
    cout << minSpanTreeTest(compGraph) << endl;    

    delete compGraph;

    return 0;
}
