#include "player.h"

#include <algorithm>
#include <sstream>
#include <string>
#include <map>

using namespace std;


bool Player::addFlag(string newFlag) {
    bool oldStatus = flags[newFlag];
    flags[newFlag] = true;

    return oldStatus;
}

void Player::addItem(string newItem) {
    inventory[newItem] = inventory[newItem] + 1;
}

bool Player::checkFlag(string flag) {
    return flags[flag];
}

bool Player::hasItem(string item) {
    return inventory[item] != 0;
}

bool Player::removeItem(string item) {
    bool hadItem = inventory[item];

    if (hadItem) {
        --inventory[item];
    }

    return hadItem;
}


string Player::showInventory() {
    if (inventory.empty()) {
        return "You have nothing.";
    }

    stringstream items;

    for (const auto& [item, count] : inventory) {
        if (!count) continue;

        items << "\t- " << item;
        if (count > 1) {
            items << "(x" << count << ")";
        }
        items << "\n";
    }

    return items.str();
}
