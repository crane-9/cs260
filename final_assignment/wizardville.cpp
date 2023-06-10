#include "story.h"

#include <string>

#include "graph.h"

using namespace std;

// Callbacks

string tutDoubt(StoryNode *n, MapGraph *, Player *p) { p->addFlag("tutorialDoubt"); return ""; }


// Creates the tutorial nodes
void createTutorial(MapGraph *graph) {
    graph->addVertex(new StoryNode(
        "Welcome to Wizardville.\n\nWizardville is a Zork-like text adventure. You will be given a set of options to pick from: enter your decision by inputting the corresponding number.", 
        "TUTORIAL" // Node title.
    ));

    graph->addVertex(new StoryNode(
        "The input parser for this game is picky, and will not accept '   2 ' when you mean to enter select '2'. You will have unlimited attempts to enter valid input.\n\nIn addition to the provided options, you may enter:\n\t- 'h' for help\n\t- 'i' for game inventory\n\t- 'q' to quit",
        "tut.1"
    ));

    graph->addVertex(new StoryNode(
        tutDoubt,
        "You will figure it out",
        "tut.1.b"
    ));

    graph->addVertex(new StoryNode(
        "[ enter fun game info here. ]",
        "tut.2"
    ));

    graph->addVertex(new StoryNode(
        "Please enjoy.",
        "tutEnd",
        "END"
    ));

    graph->addArc("TUTORIAL", "tut.1", "Got it!");
    graph->addArc("TUTORIAL", "tut.1.b", "I don't get it.");

    graph->addArc("tut.1.b", "tut.1", "Ok.");

    graph->addArc("tut.1", "tut.2", "Wait! Tell me more about this program.");

    graph->addArc("tut.1", "tutEnd", "I'm ready for my adventure");
    graph->addArc("tut.2", "tutEnd", "Okay thank you, I will adventure now.");
}


// Creates the narrative game nodes.
void createGame(MapGraph *graph) {
    graph->addVertex(new StoryNode(
        "I love wizards :] bye now",
        "START",
        "END"
    ));
}


MapGraph *story::getGraph() {
    auto graph = new MapGraph();

    createTutorial(graph);
    createGame(graph);

    return graph;
}
