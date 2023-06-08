#ifndef GAME_HEADER
#define GAME_HEADER

#include <string>
#include "graph.h"

class EndProgram : public std::exception {};

namespace game {
    /**
     * Validates a player's input. "Valid" being input that selects the next page in the story.
     * @param options The number of options to pick from.
     * @param input The player's input.
     * @return True if the player has provided satisfactory input. False if not.
    */
    bool isValidInput(int options, std::string input);

    /**
     * Loops until the player has provided the appropriate input (selecting the next story page).
     * @note This handles alternative input, such as "q" for quit.
     * @param options The total number of options to pick from.
     * @return The index of the next page the player wants to navigate to.
    */
    int getPlayerInput(int options);

    /**
     * Takes and validates user input to select the next node.
     * @param node The current node.
     * @return The next page of the story.
    */
    StoryNode *pickNextNode(StoryNode *node);


    /**
     * Main game loop.
    */
    void gameLoop(MapGraph *game);
}

#endif
