// Trial run for functionality and flow.
#include <iostream>
#include <string>

#include "graph.h"
#include "game.h"

using namespace std;


// Empty callback.
string noCB(StoryNode *n, MapGraph *g, Player *p) { return ""; }


StoryNode *sampleStory() {
    // Create story tree.
    StoryNode *firstNode = new StoryNode(noCB, "once upon a time..", "START");
    
    StoryNode *princessRoute = new StoryNode(noCB, "there was a princess and her skirt was magical.");
    StoryNode *dragonRoute = new StoryNode(noCB, "there was a big giant dragon");

    StoryNode *princessEndingOne = new StoryNode(noCB, "she lived happily forever!", "", "END");
    StoryNode *princessEndingTwo = new StoryNode(noCB, "she then exploded and everyone was sad", "", "END");

    StoryNode *dragonEndingOne = new StoryNode(noCB, "it napped happily in its hoard for all its days", "", "END");
    StoryNode *dragonEndingTwo = new StoryNode(noCB, "it left its cave to terrorize the world and explode a princess", "", "END");

    // Map connections.
    firstNode->addArc(princessRoute, "there was a princess.");
    firstNode->addArc(dragonRoute, "there was a dragon");

    princessRoute->addArc(princessEndingOne, "be happy");
    princessRoute->addArc(princessEndingTwo, "be attacked by a dragon");

    dragonRoute->addArc(dragonEndingOne, "take a nap, dragon");
    dragonRoute->addArc(dragonEndingTwo, "go do something scary");

    return firstNode;
}


int main() {
    StoryNode *storyRoot = sampleStory();
    Game game(new MapGraph()); // Enter empty graph, use the generated story node. why? i think i wanted to do this without a graph. why? i don't actually remember that part.

    try {
        game.gameLoop(storyRoot);
        cout << "You completed the game!" << endl;
    } catch (EndProgram e) {
        cout << e.what() << endl;
    }

    cout << "Bye bye!" << endl;
    return 0;
}
