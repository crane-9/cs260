// Tests for graph.h/cpp

#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>

#include "graph.h"

using namespace std;


// Complex graph generator.
MapGraph *makeSampleGraph() {
    auto graph = new MapGraph();

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

    graph->addArc("A", "B", "ab"); graph->addArc("B", "A", "ba");
    graph->addArc("B", "C", "bc");
    graph->addArc("C", "D", "cd");
    graph->addArc("C", "G", "cg");
    graph->addArc("D", "A", "da");
    graph->addArc("D", "E", "de");
    graph->addArc("E", "F", "ef");
    graph->addArc("G", "H", "gh");
    graph->addArc("H", "F", "hf");
    graph->addArc("H", "I", "hi");
    graph->addArc("I", "J", "ij");
    graph->addArc("J", "H", "jh");

    graph->addArc("X", "Y", "xy"); graph->addArc("Y", "X", "yx");

    return graph;
}


// Unit tests

/// @brief Tests a graph's addVertex() method, returns pass/fail message.
string addVertexTest(MapGraph *graph) {
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
string addArcTest(MapGraph *graph) {
    return "";
}


/// @brief Tests a graph addVertices() method, returns pass/fail message.
string addVerticesTest(MapGraph *graph) {
    return "";
}


string shortestPathTest(MapGraph *sampleGraph) {
    pathMap *shortestPaths = sampleGraph->shortestPath("B");

    stringstream results;

    results << "SHORTEST PATHS FROM NODE 'B':\n";

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


string arborescenceTest(MapGraph *sampleGraph) {
    auto information = sampleGraph->arborescence("B");
    stringstream message;

    // Return a list of all edge names.
    for (auto edgeTuple : (*information)) {
        message << "'" << std::get<2>((*edgeTuple)) << "', ";
    }

    delete information;
    return message.str();
}



int main() {
    MapGraph *graph = new MapGraph();

    cout << addVertexTest(graph) << endl;
    cout << addArcTest(graph) << endl;
    cout << addVerticesTest(graph) << endl;

    delete graph;

    // Build complex graph. Tree tests.
    MapGraph *compGraph = makeSampleGraph();

    cout << shortestPathTest(compGraph) << endl;    
    cout << arborescenceTest(compGraph) << endl;    

    delete compGraph;

    return 0;
}
