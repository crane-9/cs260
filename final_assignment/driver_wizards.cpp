/**
 * This driver runs a game.
*/

#include <iostream>
#include <string>

#include "game.h"
#include "graph.h"
#include "player.h"
#include "story.h"

using std::cin, std::cout, std::endl, std::string;


int main(int argc, char *argv[]) {
    // Aesthetic preference.
    cout << endl << endl;

    Game game(story::getGraph());

    // Argument flag `-t` skips tutorial.
    if (!(argc == 2 && string(argv[1]) == "-t")) {
        game.runGame("TUTORIAL");
    }

    game.runGame("START");

    return 0;
}
