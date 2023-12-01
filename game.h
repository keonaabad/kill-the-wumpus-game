#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "room.h"

using namespace std;

class Game {
private:
    int width; // Width of the game grid
    int height; // Height of the game grid
    bool set_player; // Flag to check if player is set
    int player_x, player_y; // Player's current position coordinates
    int wumpus_x, wumpus_y; // Wumpus's position coordinates
    bool wumpus; // Flag to check if Wumpus is alive
    bool gold; // Flag to check if gold is found
    int arrow_x, arrow_y; // Arrow's position coordinates
    int num_arrows; // Number of arrows player has
    int confusion; // Counter for how many turns player is confused
    int escape_x, escape_y; // Escape point coordinates
    int stalicites_count; // Count of stalactites in the game
    int bats_count; // Count of bats in the game
    vector<vector<Room*> > room_arr; // 2D vector representing the game grid

public:
    // Constructor for the Game class, initializes the game environment.
    Game(int width, int height);

    // Destructor for the Game class, cleans up dynamic memory.
    ~Game();

    // Getter for the height of the game grid.
    int get_height() const;

    // Getter for the width of the game grid.
    int get_width() const;

    // Places different events (player, Wumpus, gold, etc.) on the game grid.
    void make_events(int x, int y, char event);

    // Prints the current state of the game grid, showing different events.
    void print(bool debug);

    // Handles the player's encounter with various events on the grid.
    void encounter(char that);

    // Manages the player's movement on the game grid.
    void player_move();

    // Generates precepts based on adjacent events to the player's location.
    void precepts();

    // Manages the shooting of an arrow by the player.
    void shoot_arrow();

    // Checks if the game's win or lose conditions have been met.
    bool winner();

    // Debug mode flag for additional game information.
    bool debug;
};

#endif
