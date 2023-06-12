#ifndef PLAYER_HEADER
#define PLAYER_HEADER

#include <map>
#include <string>


class Player {
    private:
        std::map<std::string, bool> flags;
        std::map<std::string, int> inventory;

    public:
        std::string name;

        /**
         * Sets a player flag to true.
         * @param newFlag Name of the new flag.
         * @return True if the flag was present before setting. False if this is the first time the flag has been marked.
        */
        bool addFlag(std::string newFlag);

        /**
         * Adds an item to player inventory.
         * @param newItem Item to add to player inventory.
        */
        void addItem(std::string newItem);

        /**
         * Checks a flag's status.
         * @param flag Flag's name.
         * @return True if flag has been set, false if absent.
        */
        bool checkFlag(std::string flag);

        /**
         * Checks if the player has an item.
         * @param item Item name.
         * @return True if player has item, false other.
        */
        bool hasItem(std::string item);

        /**
         * Removes an item from the player's inventory.
         * @param item The item to remove from inventory.
         * @return Returns false if the item was not present in inventory. True if it was, and is now removed.
        */
        bool removeItem(std::string item);

        /**
         * Lists all items in the player's inventory.
         * @return A string naming all items in a player's inventory.
        */
        std::string showInventory();
};


#endif
