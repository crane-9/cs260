// LOOK OUT!!!!!! THIS WASN'T DONE IN CLASS!!!!!
#include <iostream>
#include <string>

using namespace std;


/************** STRUCTS **************/
/// @brief simplistic player struct
struct Player {
    string inventory[10];
}myPlayer;


/// @brief simplistic story node struct, with one pointer forward.
struct StoryNode {
    StoryNode *next;
    string narration;
    void (* callback)(StoryNode *, Player *);
}page1, page2, page3, page4;


/************** CALLBACKS **************/
void callback1(StoryNode *node, Player *player) {
    player->inventory[0] = "big key";
}

void callback2(StoryNode *node, Player *player) {
    if (player->inventory[0] != "big key") {
        cout << "'i am so sorry player you have no big key!'" << endl;
    } else {
        cout << "'AH YES YOU HAVE MY KEY! THANKS'" << endl;
    }
}

void callback3(StoryNode *node, Player *player) {
    node->next = &page4;
}

void callback4(StoryNode *node, Player *player) {
    cout << player->inventory[0] << endl;
}


/**
 * everythign in one function, i so lazy :]
*/
int main() {
    // set up
    page1.narration = "Once upon a time..... I gave you a key.";
    page2.narration = "You brought it back to its rightful owner. And for that I am so proud.";
    page3.narration = "You then went home, and took a long nap.";
    page4.narration = "And when you woke... You found it, in your pocket. MYSTERIOUS!!!";

    page1.callback = callback1;
    page2.callback = callback2;
    page3.callback = callback3;
    page4.callback = callback4;

    page1.next = &page2;
    page2.next = &page3;
    page4.next = nullptr;

    // set loop and run
    StoryNode *current;
    current = &page1;

    while (current != nullptr) {
        current->callback(current, &myPlayer);

        cout << current->narration << endl;

        // CURRENT issue..... sometimes it skips an interation when it comes to getting player input!
        string input = ""; // i have tried placing this here, and then also right above the loop. interesting.
        cout << "> ";
        cin >> input;
        cout << endl << endl;

        current = current->next;
    }

    cout << "you did it. you won the video game forever." << endl;

    return 0;
}