// Test run file, tests the StoryNodes without the MapGraph, and without story.h
#include <iostream>
#include <string>

#include "graph.h"
#include "game.h"

using namespace std;


StoryNode *sampleStory() {
    // Create story tree.
    StoryNode *firstNode = new StoryNode("Once upon a time...", "START");
    
    StoryNode *princessRoute = new StoryNode("There was a princess, and she wore a magical gown.", "");
    StoryNode *dragonRoute = new StoryNode("There was a raging dragon, a beast!", "");

    StoryNode *princessEndingOne = new StoryNode("The princess lived happily forever, protecting her kingdom and candy people.", "", "END");
    StoryNode *princessEndingTwo = new StoryNode("The princess burst into flames. She burned to ashes, and everyone was very sad.", "", "END");

    StoryNode *dragonEndingOne = new StoryNode("It laid down for a nap in its hoard, and it rested. It had a salad when it woke again.", "", "END");
    StoryNode *dragonEndingTwo = new StoryNode("It clawed at the stone of its cave lair until its nails frayed and broke. It could not contain its hunger. It fled to the nearest castle in a fury, and spewed flame carelessly.", "", "END");

    // Map connections.
    firstNode->addPath(princessRoute, "there was a princess!");
    firstNode->addPath(dragonRoute, "there was a dragon!");

    princessRoute->addPath(princessEndingOne, "be happy!");
    princessRoute->addPath(princessEndingTwo, "get attacked by a dragon!");

    dragonRoute->addPath(dragonEndingOne, "take a nap, dragon!");
    dragonRoute->addPath(dragonEndingTwo, "go do something scary! and mean!");

    return firstNode;
}


int main() {
    StoryNode *storyRoot = sampleStory();
    Game game(new MapGraph()); // Enter empty graph to make the constructor happy. Use the generated story node. 

    try {
        game.gameLoop(storyRoot);
        cout << "You completed the game!" << endl;
    } catch (EndProgram e) {
        cout << e.what() << endl;
    }

    cout << "Thank you for playing!" << endl;
    return 0;
}
