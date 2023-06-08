#include <algorithm>
#include <string>
#include <map>

#include "player.h"

using namespace std;


bool Player::addFlag(string newFlag) {
    bool oldStatus = flags[newFlag];
    flags[newFlag] = true;

    return oldStatus;
}

void Player::addItem(string newItem) {
    inventory.push_back(newItem);
}

bool Player::checkFlag(string flag) {
    return flags[flag];
}

bool Player::hasItem(string item) {
    // Using an algorithm--experimenting.
    return find(inventory.begin(), inventory.end(), item) != inventory.end();
}
