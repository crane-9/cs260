/* This file is the script for wizardville. Most of the file is writing. I suggest enabling softwrap. */
#include "story.h"

#include <string>

#include "game.h"
#include "graph.h"

using namespace std;


// Callbacks -- tutorial

string tutDoubt(StoryNode *n, MapGraph *m, Player *p) { p->addFlag("tutorialDoubt"); return ""; }

string tutAssurance(StoryNode *n, MapGraph *m, Player *p) {
    if (p->checkFlag("tutorialDoubt")) {
        return "I believe in you.";
    }
    return "";
}


// Callbacks -- story

string bedroom(StoryNode *n, MapGraph *m, Player *p) {
    if (!n->visits) {
        return "You get out of bed, and to your feet.";
    } else if (n->visits == 1) {
        n->description = "Your bedroom is a quiet mess. Barnaby is curled up on the corner of your bed, napping the day away."; // Update node description.
    } 

    return ""; 
}

string bedroomHat(StoryNode *n, MapGraph *m, Player *p) {
    if (!n->visits) {
        p->addItem("Your hat");
    }

    m->deleteArc("hill.house.bedroom", n->title);

    return "You take it off the dresser, and put it on your head.";
}


// Graph/game assembly

// Creates the tutorial.
void createTutorial(MapGraph *graph) {
    graph->addVertex(new StoryNode(
        "Welcome to Wizardville.\n\nTo play the game, you will be given a simple menu of options. To make your selection, you will enter the corresponding number.\n\nHere is your first test:", 
        "TUTORIAL"
    ));

    graph->addVertex(new StoryNode(

        "Great. The input parser for this game is picky, and will not accept '   2 ' when you mean to select option '2'. You will have unlimited attempts to enter valid input.\n\nIn addition to the provided options, you may enter:",
        "tut.1"
    ));

    graph->addVertex(new StoryNode(
        tutDoubt,
        "You'll figure it out.",
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
    // Opening
    graph->addVertex(new StoryNode(
        "It is morning, and you are asleep, face down in your stack of quilts. ",
        "START"
    ));

    // THE HILL
    // Alchemist's home
    graph->addVertex(new StoryNode(
        bedroom,
        "",
        "hill.house.bedroom"
    ));
    
    graph->addVertex(new StoryNode(
        bedroomHat,
        "Your hat is a worn old thing, embellished with years of patchwork. An embroidered hummingbird curves around the peak of the hat. Colorful glass beads dangle off the rim, each handcrafted by your friend, the Illusionist.",
        "hill.house.bedroom.hat"
    ));
    
    graph->addVertex(new StoryNode(
        "",
        "hill.house.kitchen"
    ));
    
    graph->addVertex(new StoryNode(
        "",
        "hill.house.living"
    ));

    // Outdoors
    graph->addVertex(new StoryNode(
        "",
        "hill.house.exterior"
    ));

    graph->addVertex(new StoryNode(
        "",
        "hill.trail"
    ));

    // Hill location connections
    graph->addArc("START", "hill.house.bedroom", "Wake up.");
    
    graph->addArc("hill.house.bedroom", "hill.house.bedroom.hat", "Don hat.");
    graph->addArc("hill.house.bedroom", "hill.house.kitchen", "Enter kitchen.");
    
    graph->addArc("hill.house.kitchen", "hill.house.bedroom", "Enter bedroom.");
    graph->addArc("hill.house.kitchen", "hill.house.living", "Enter living room.");
    graph->addArc("hill.house.kitchen", "hill.house.exterior", "Go outside.");
    
    graph->addArc("hill.house.living", "hill.house.living", "Enter kitchen.");
    graph->addArc("hill.house.living", "hill.house.exterior", "Go outside.");

    graph->addArc("hill.house.exterior", "hill.house.living", "Go inside.");
    graph->addArc("hill.house.exterior", "hill.trail", "Head into town.");


    // TOWN

}


MapGraph *story::getGraph() {
    auto graph = new MapGraph();

    createTutorial(graph);
    createGame(graph);

    return graph;
}
