#include "game.h"

#include <iostream>
#include <string>

#include "graph.h"
#include "player.h"

using std::cin, std::cout, std::string, std::endl;


string EndProgram::what() {
    return "Player ended the game early.";
}


Game::Game(MapGraph *_game) {
    game = _game;
}

Game::~Game() {
    delete game;
}

bool Game::isValidInput(int options, string input) {
    if (input == "") {
        return false;
    }

    int intput;
    try {
        intput = stoi(input);
    } catch(std::invalid_argument e) {
        return false;
    }

    // keep in mind i am going 1 - 3 rather than 0 - 2
    return 0 < intput && intput <= options;
}

int Game::getInput(int options) {
    string playerInput;

    while (!isValidInput(options, playerInput)) {
        cout << "> ";
        cin >> playerInput;

        if (playerInput == "q" || playerInput == "Q") {
            throw EndProgram();
        } 
    }

    return stoi(playerInput);
}

StoryNode *Game::pickNextNode(StoryNode *node) {
    // Convert player input to 0-index.
    int idx = getInput(node->connections.size()) - 1;
    return node->connections[idx]->second;
}

void Game::gameLoop(StoryNode *start) {
    StoryNode *current;
    
    current = start;
    while (current != nullptr) {
        current->callback(current, &player);

        ++current->visits;

        // print narration and menu
        cout << current->description << endl;
        std::cerr << current->getPaths() << endl;

        if (current->tag == "END") {
            break;
        }

        // get input, next iteration
        current = pickNextNode(current);
    }
}
