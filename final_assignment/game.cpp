#include "game.h"

#include <iostream>
#include <string>

#include "graph.h"
#include "player.h"

using std::cin, std::cout, std::string, std::endl;


string EndProgram::what() {
    return "Player ended the game early.";
}


Game::Game(MapGraph *_graph) {
    graph = _graph;
}

Game::~Game() {
    delete graph;
}

bool Game::isValidInput(int options, string input) {
    if (input == "") {
        return false;
    }

    int intInput;
    try {
        intInput = stoi(input);
    } catch(std::invalid_argument e) {
        return false;
    }

    // Check if input is in the appropriate range.
    return 0 < intInput && intInput <= options;
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
    string callbackText;

    current = start;
    while (current != nullptr) {
        // Callback, update visits.
        callbackText = current->callback(current, graph, &player);
        ++current->visits;

        // Print narration and menu.
        cout << current->description << endl;
        if (callbackText != "") cout << callbackText << endl;
        cout << current->getPaths() << endl;

        // Break loop here. 
        if (current->tag == "END") break;

        // Next iteration.
        current = pickNextNode(current);
        cout << endl << endl;
    }
}


void Game::runGame(string startTitle) {
    gameLoop(graph->getByTitle(startTitle));
}
