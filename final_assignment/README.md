# CS 260 Final Project: Graph

## Design

### Inspiration

The first application I saw for a graph data structure is the skeleton for a text-based adventure game. For example, Zork. 

![Map of Zork I](https://cdn.discordapp.com/attachments/799704269787496518/1113593127148716163/zork_map.png) 
Found on [archive.org](https://archive.org/details/zork-i-ii-iii-maps/)

In Zork, the player navigates the world by entering a direction (north/east/south/west) into the console. Each location behaves as a node, as it has its own unique data and connections to other locations. Connections between locations can even be one-way passages, similar to the directionality of graph nodes.

Another example and point of inspiration is [Twine 2](https://twinery.org/), a tool for building non-linear, text-based adventure games. The tool's editor interface is a graph that holds story nodes, all of which are connected by directional arcs.

![Twine 2 interface](https://cdn.discordapp.com/attachments/799704269787496518/1112636765300338728/twine2_example.jpg)


### Solving a problem

As (hopefully) illustrated by my previous points, a graph is an ideal structure for modelling a non-linear story tree for a text adventure game. Each story node may hold the data for its represented "page" or location. 

In practice, this becomes more complicated, as games like Zork require a player inventory system in order for the create puzzles for the player to solve. This issue, however, is more about how each story node, or the rest of the program, works. A graph solves the problem of how to create branching story paths.

A simple version of a story node (with no concern for player inventory or conditional elements) might look like this:
```cpp
struct StoryNode {
    StoryNode *paths[5]; // Setting a limit of 5 for simplicity

    // Narrative text
    std::string narration;
    std::string title; // A name for the node/page/location. 
};
```

While a more complex node may look like this:
```cpp
struct StoryNode {
    StoryNode *paths[5];

    std::string narration;
    
    // A special tag may tell a game-handling object how to handle this node. For example: "Start" or "End"
    std::string tag;
    // A possible callback that interacts with the Player object, or uses the Player object to modify itself.
    std::function<void(StoryNode *, Player *)> callbackOnVisit;
    // Some games may want to count if the player has visited before, or how many times.
    int visits = 0; 
};
```

Alternatively, it could be a class for more complex and flexible behavior. 

In all proposed node versions, I've modelled a connection between two nodes as one having a pointer. This would thereby be a directioned graph, which I find appropriate for the situation.

As for unlockable routes, I believe it would be appropriate to place that logic in a node's callback like so:
```cpp
void callback(StoryNode *node, Player *player) {
    if (player->hasItem("silver key")) {
        // Where `GLOBAL_VAR_FOR_ANOTHER_NODE` is a defined node.
        node->addPath(GLOBAL_VAR_FOR_ANOTHER_NODE);
    }
}
```


### Design outline

Above, I've explored and outlined a couple iterations of what a `StoryNode` could look like in order to provide common adventure game mechanics. As for the program's complete structural design 


### Tests

Putting application aside and refocusing on the structure of a graph, there are a few tests I would like to run to prove graph functionality.

For `addVertex()`:

For `addEdge()`:

For `shortestPath()`:

For `minSpanTree()`:


---
## [ complexity analysis ]


---
## [ meeting requirements ]
