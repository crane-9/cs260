// Trial run for functionality and flow.
#include "graph.h"

#include <iostream>
#include <string>

using namespace std;


class EndProgram : public exception {
    public:
        string what() {
            return "User ended program.";
        }
};


void noCB(StoryNode *n, Player *p) {}


StoryNode *sampleStory() {
    StoryNode *firstNode = new StoryNode(noCB, "once upon a time..", "START");
    
    StoryNode *princessRoute = new StoryNode(noCB, "there was a princess and her skirt was magical.");
    StoryNode *dragonRoute = new StoryNode(noCB, "there was a big giant dragon");

    StoryNode *princessEndingOne = new StoryNode(noCB, "she lived happily forever!", "END");
    StoryNode *princessEndingTwo = new StoryNode(noCB, "she then exploded and everyone was sad", "END");

    StoryNode *dragonEndingOne = new StoryNode(noCB, "it napped happily in its hoard for all its days", "END");
    StoryNode *dragonEndingTwo = new StoryNode(noCB, "it left its cave to terrorize the world and explode a princess", "END");

    firstNode->addArc(princessRoute, "there was a princess.");
    firstNode->addArc(dragonRoute, "there was a dragon");

    princessRoute->addArc(princessEndingOne, "be happy");
    princessRoute->addArc(princessEndingTwo, "be attacked by a dragon");

    dragonRoute->addArc(dragonEndingOne, "take a nap, dragon");
    dragonRoute->addArc(dragonEndingTwo, "go do something scary");

    return firstNode;
}

bool isValidInput(int vectorSize, string input) {
    if (input == "q") {
        throw EndProgram();
    } else if (input == "") {
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
    Player player;
    while (current != nullptr) {
        // current->callback(current, &player);

        ++current->visits;

        // print narration and menu
        cout << current->description << endl;
        cout << current->getPaths() << endl;

        if (current->tag == "END") {
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
    try {
        runGame(storyRoot);
    } catch (EndProgram e) {
        cout << e.what() << endl;
    }

    return 0;
}
