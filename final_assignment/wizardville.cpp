#include "story.h"

#include <string>

#include "graph.h"

using namespace std;

// Callbacks

string tutDoubt(StoryNode *n, MapGraph *m, Player *p) { p->addFlag("tutorialDoubt"); return ""; }

string tutAssurance(StoryNode *n, MapGraph *m, Player *p) {
    if (p->checkFlag("tutorialDoubt")) {
        return "Remember: just enter the number. I believe in you.";
    } else {
        return "";
    }
}


// Creates the tutorial.
void createTutorial(MapGraph *graph) {
    graph->addVertex(new StoryNode(
        "Welcome to Wizardville.\n\nTo play the game, you will be given a simple menu of options. To make your selection, you will enter the corresponding number.\n\nHere is your first test:", 
        "TUTORIAL" // Node title.
    ));

    graph->addVertex(new StoryNode(
        "Great. The input parser for this game is picky, and will not accept '   2 ' when you mean to select option '2'. You will have unlimited attempts to enter valid input.\n\nIn addition to the provided options, you may enter:\n\t- 'h' for help\n\t- 'i' for game inventory\n\t- 'q' to quit",
        "tut.1"
    ));

    graph->addVertex(new StoryNode(
        tutDoubt,
        "You will figure it out.",
        "tut.1.b"
    ));

    graph->addVertex(new StoryNode(
        "Wizardville is made from scratch over a couple of weeks for my data structure class. Each 'page' of the adventure is a point on a map (or a node on a graph), that holds data representing one location, or point in conversation. Each node may have a callback function, and any callback function may update a player variable (add something to your inventory, set a flag to remember your decision) or check how many times you've visited that location, in order to create a more responsive experience.\n\nWizardville is written in C++ and compiled with GCC. For this project, I wrote a simple framework which could easily be customized for other text adventures, by anyone with some familiarity with C++. I attempted to make it as approachable as possible.",
        "tut.2"
    ));

    graph->addVertex(new StoryNode(
        tutAssurance,
        "Thank you for playing.",
        "tutEnd",
        "END"
    ));

    graph->addArc("TUTORIAL", "tut.1", "Got it!");
    graph->addArc("TUTORIAL", "tut.1.b", "I don't get it.");

    graph->addArc("tut.1.b", "tut.1", "Ok.");

    graph->addArc("tut.1", "tutEnd", "I'm ready for my adventure");
    graph->addArc("tut.1", "tut.2", "Wait! Tell me more about this program.");

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
