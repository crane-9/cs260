#include "graph.h"

#include <iostream>
#include <string>

using namespace std;


StoryNode *sampleStory() {
    StoryNode *firstNode = new StoryNode("once upon a time..", "start");
    
    StoryNode *princessRoute = new StoryNode("there was a princess and her skirt was magical.");
    StoryNode *dragonRoute = new StoryNode("there was a big giant dragon");

    StoryNode *princessEndingOne = new StoryNode("she lived happily forever!", "end");
    StoryNode *princessEndingTwo = new StoryNode("she then exploded and everyone was sad", "end");

    StoryNode *dragonEndingOne = new StoryNode("it napped happily in its hoard for all its days", "end");
    StoryNode *dragonEndingTwo = new StoryNode("it left its cave to terrorize the world and explode a princess", "end");

    firstNode->addArc(princessRoute, "there was a princess.");
    firstNode->addArc(dragonRoute, "there was a dragon");

    princessRoute->addArc(princessEndingOne, "be happy");
    princessRoute->addArc(princessEndingTwo, "be attacked by a dragon");

    dragonRoute->addArc(dragonEndingOne, "take a nap, dragon");
    dragonRoute->addArc(dragonEndingTwo, "go do something scary");

    return firstNode;    
}

bool isValidInput(int vectorSize, string input) {
    if (input == "") {
        return false;
    }

    int intput;
    try {
        intput = stoi(input);
    } catch(invalid_argument e) {
        return false;
    }

    // keep in mind i am going 1 - 3 rather than 0 - 2
    return 0 < intput && intput <= vectorSize;
}

int getPlayerInput(int optionCount) {
    string playerInput;

    while (!isValidInput(optionCount, playerInput)) {
        cout << "> ";
        cin >> playerInput;
    }

    return stoi(playerInput);
}

void runGame(StoryNode *start) {
    StoryNode *current;
    
    current = start;
    while (current != nullptr) {
        // do the callback. cut for now.
        // current->callback(current, &myPlayer);

        ++current->visits;

        // print narration and menu
        cout << current->narration << endl;
        cout << current->getPaths() << endl;

        if (current->tag == "end") {
            break;
        }

        // get input, next iteration
        current = current->connections[
            getPlayerInput(current->connections.size()) - 1
        ]->second;
}

    cout << "you did it. you won the video game forever." << endl;
}

int main() {
    StoryNode *storyRoot = sampleStory();

    runGame(storyRoot);

    return 0;
}
