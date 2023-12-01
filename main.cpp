/*********************************************************************
** Program Filename: main.cpp
** Author: Keona Abad
** Date: 11/25/2023
** Description: Main program file for the Wumpus World game. It initializes
**              the game environment, sets up the game, and runs the main game loop.
** Input: User inputs for game configuration and player actions.
** Output: Game state updates and outputs based on player actions.
*********************************************************************/

#include "game.h"

// Function to check if a number is an integer
int is_int(int &number);

int main() {
    int w, h; // width and height of the game grid
    srand(time(NULL));

    // Prompt user for game width and height
    do {
        cout << "Enter width of game: ";
        cin >> w;
    } while (w < 4);

    do {
        cout << "Enter height of game: ";
        cin >> h;
    } while (h < 4);

    // Initialize game with given width and height
    Game main = Game(w, h);
    cout << "Are you playing in debug mode? (1 - Yes, 0 - No): ";
    cin >> main.debug;

    // Set up game events
    for (int i = 0; i < 7; i++) {
        int y = rand() % w;
        int x = rand() % h;
        if (i == 0) {
            main.make_events(x, y, '*'); // Player starting position
        }
        else if (i == 1) {
            main.make_events(x, y, 'w'); // Wumpus
        }
        else if (i == 2) {
            main.make_events(x, y, 'g'); // Gold
        }
        else if (i == 3 || i == 4) {
            main.make_events(x, y, 'b'); // Bats
        }
        else if (i == 5 || i == 6) {
            main.make_events(x, y, 's'); // Stalactites
        }
    }

    // Print the initial state of the grid
    main.print(main.debug);

    // Main game loop
    do {
        main.player_move();
    } while (true); // The loop will break from inside player_move() if game ends

    return 0; // End of the program
}
