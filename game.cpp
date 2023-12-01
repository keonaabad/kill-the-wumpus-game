#include "game.h"


// Constructor for the Game class, initializes the game environment with specified dimensions.
Game::Game(int width, int height) {
    this->width = width;
    this->height = height;
    this->wumpus = true;
    this->gold = false;
    this->confusion = 0;
    this->num_arrows = 3;
    // Initialize the game grid with Room objects
    for (int i = 0; i < height; i++) {
        vector <Room*> rows;
        for (int j = 0; j < width; j++) {
            rows.push_back(new Room);
        }
        this->room_arr.push_back(rows);
    }
}

// Destructor for the Game class, cleans up dynamic memory.
Game::~Game() {
    for (int i = 0; i < this->height; i++) {
        for (int j = 0; j < this->width; j++) {
            delete this->room_arr[i][j];
            this->room_arr[i][j] = NULL;
        }
    }
}

// Returns the height of the game grid.
int Game::get_height() const {
    return this->height;
}
// Returns the width of the game grid.
int Game::get_width() const {
    return this->width;
}


// Places different events (player, Wumpus, gold, etc.) on the game grid.
void Game::make_events(int x, int y, char event) {
    if (this->room_arr[x][y]->has_event() == false) {
        if (event == '*') {
            this->player_x = x;
            this->player_y = y;
            this->room_arr[x][y]->set_event(event);
            this->escape_x = x;
            this->escape_y = y;
            this->room_arr[x][y]->set_escape(true);
            this->room_arr[x][y]->set_event(event);
        }
        else if (event == 'w') {
            this->wumpus_x = x;
            this->wumpus_y = y;
            this->room_arr[x][y]->set_event(event);
        }
        else if (event == 'g') {
            this->room_arr[x][y]->set_event(event);        
        }
        else if (event == 's') {
            this->room_arr[x][y]->set_event(event);
        }
        else if (event == 'b') {
            this->room_arr[x][y]->set_event(event);
        }
    }
    else if (this->room_arr[x][y]->has_event() == true) {
        if (event == 's' && this->stalicites_count < 2) {
            this->make_events((rand() % this->width), (rand() % this->height), 's');
        }
        else if (event == 'b' && this->stalicites_count < 2) {
            this->make_events((rand() % this->width), (rand() % this->height), 'b');
        }
    }

}


// Prints the current state of the game grid.
void Game::print(bool debug) {
    for (int i = 0; i < this->height; i++) {
        for (int k = 0; k < this->width; k++) {
            cout << "+---";
        }
        cout << "+";
        cout << endl;
        for (int j = 0; j < this->width; j++) {
            cout << "| ";
            if (this->room_arr[i][j]->get_event() == '*') {
                cout << "* ";
            }
            else if (this->room_arr[i][j]->get_event() == 'w' && debug == true) {
                cout << "w ";
            }
            else if (this->room_arr[i][j]->get_event() == 'g' && debug == true) {
                cout << "g ";
            }
            else if (this->room_arr[i][j]->get_event() == 's' && debug == true) {
                cout << "s ";
            }
            else if (this->room_arr[i][j]->get_event() == 'b' && debug == true) {
                cout << "b ";
            } 
            else {
                cout << "  ";
            }
        }
        cout << "|" << endl;
    }
    for (int k = 0; k < this->width; k++) {
        cout << "+---";
    }
    cout << "+" << endl << endl;
}


// Handles the encounter of the player with various events on the grid.
void Game::encounter(char that) {
    if (that == 'w') {
        this->room_arr[this->player_x][this->player_y]->event_arr->encounter(true);
    }
    else if (that == 'g') {
        this->room_arr[this->player_x][this->player_y]->event_arr->encounter(true);
        this->gold = true;
    }
    else if (that == 'b') {
        this->room_arr[this->player_x][this->player_y]->event_arr->encounter(true);
        this->confusion = 5;
    }
    else if (that == 's') {
        this->room_arr[this->player_x][this->player_y]->event_arr->encounter(true);
    }
}



// Manages the player's movement and interactions on the grid.
void Game::player_move() {
    char move;
    cout << "W - Up\nS - Down\nA - Left\nD - Right\nF - Shoot An Arrow\nChoice:  ";
    cin >> move;
    if (confusion > 0){
        cout << "You are confused for " << confusion << " more moves." << endl;
        confusion -= 1;
        if(move == 'w'){
            move = 's';
        }else if(move == 'a'){
            move = 'd';
        }else if(move == 's'){
            move = 'w';
        }else if(move == 'd'){
            move = 'a';
        }
    }

    if ((move == 'W' || move == 'w') && (this->player_x - 1) >= 0) {
        this->room_arr[this->player_x][this->player_y]->set_event(' ');
        this->player_x -= 1;
        char hold = this->room_arr[this->player_x][this->player_y]->get_event();
        encounter(hold);
        this->room_arr[this->player_x][this->player_y]->set_event('*');
        this->print(this->debug);
        this->precepts();
        if (this->winner() == true) {
            this->~Game();
        }
    }
    else if ((move == 'S' || move == 's') && (this->player_x + 1 < this->height && (this->player_x + 1) >= 0)) {
        this->room_arr[this->player_x][this->player_y]->set_event(' ');
        this->player_x += 1;
        char hold = this->room_arr[this->player_x][this->player_y]->get_event();
        encounter(hold);
        this->room_arr[this->player_x][this->player_y]->set_event('*');
        this->print(this->debug);
        this->precepts();
        if (this->winner() == true) {
            this->~Game();
        }
    }
    else if ((move == 'A' || move == 'a') && (this->player_y - 1 < this->width && (this->player_y - 1) >= 0)) {
        this->room_arr[this->player_x][this->player_y]->set_event(' ');
        this->player_y -= 1;
        char hold = this->room_arr[this->player_x][this->player_y]->get_event();
        encounter(hold);
        this->room_arr[this->player_x][this->player_y]->set_event('*');
        this->print(this->debug);
        this->precepts();
        if (this->winner() == true) {
            this->~Game();
        }
    }
    else if ((move == 'D' || move == 'd') && (this->player_y + 1 < this->width && (this->player_y + 1) >= 0)) {
        this->room_arr[this->player_x][this->player_y]->set_event(' ');
        this->player_y += 1;
        char hold = this->room_arr[this->player_x][this->player_y]->get_event();
        encounter(hold);
        this->room_arr[this->player_x][this->player_y]->set_event('*');
        this->print(this->debug);
        this->precepts();
        if (this->winner() == true) {
            this->~Game();
        }
    }
    else if (move == 'f' || move =='F') { 
        this->shoot_arrow();
        this->print(this->debug);
    }
    else {
    cout << "Out of Bounds!!" << "\n\n";
    }
}



// Generates precepts based on adjacent rooms.
void Game::precepts() {
    if ((this->player_x + 1) < this->height) {
        if (this->room_arr[this->player_x + 1][this->player_y]->get_event() == 'g' || 'w' || 's' || 'b') {
            room_arr[this->player_x + 1][this->player_y]->return_precept();
        }
    }
    if ((this->player_x - 1) >= 0) {
        if (this->room_arr[this->player_x - 1][this->player_y]->get_event() == 'g' || 'w' || 's' || 'b') {
            room_arr[this->player_x - 1][this->player_y]->return_precept();
        }
    }
    if ((this->player_y + 1) < this->height) {
        if (this->room_arr[this->player_x][this->player_y + 1]->get_event() == 'g' || 'w' || 's' || 'b') {
            room_arr[this->player_x][this->player_y + 1]->return_precept();
        }
    }
    if ((this->player_y - 1) >= 0) {
        if (this->room_arr[this->player_x][this->player_y - 1]->get_event() == 'g' || 'w' || 's' || 'b') {
            room_arr[this->player_x][this->player_y - 1]->return_precept();
        }
    }
}



// Handles the logic for shooting an arrow in the game.
void Game::shoot_arrow() {
    this->num_arrows -= 1;
    if (this->num_arrows == 0) {
        cout << "Out of Arrows!!!" << endl;
        return;
    }
    char choice;
    bool wumpus_hit;
    do {
        cout << "W - Shoot Up    S - Shoot Down    A - Shoot Left    D - Shoot Right" << endl;
        cin >> choice;
    } while (!(choice == 'w' || choice == 'a' || choice == 's' || choice == 'd'));
    this->arrow_x = this->player_x;
    this->arrow_y = this->player_y;
    for (int i = 0; i < 3; i++) {
        if (choice == 'w' && (this->arrow_x - 1) >= 0) {
            this->arrow_x += -1;
        } else if (choice == 'a' && (this->arrow_y - 1) >= 0) {
            this->arrow_y += -1;
        } else if (choice == 's' && (this->arrow_x + 1) < this->height) {
            this->arrow_x += 1;
        } else if (choice == 'd' && (this->arrow_y + 1) < this->width) {
            this->arrow_y += 1;
        }

        if (room_arr[arrow_x][arrow_y]->get_event() == 'w') {
            this->wumpus = false;
            cout << "You killed Wumpus!!!" << endl;
            wumpus_hit = true;
            room_arr[this->arrow_x][this->arrow_y]->set_event(' ');
        }
    }
    if (wumpus_hit = false) {
        cout << "Wumpus has awoken and moved!" << endl;
        room_arr[this->wumpus_x][this->wumpus_y]->set_event(' ');
        bool empty = false;
        do {
            int y = rand() % this->width;
            int x = rand() % this->height;
            if (this->room_arr[x][y]->has_event() == false) {
                empty = true;
                this->room_arr[x][y]->set_event('w');
                this->wumpus_x = x;
                this->wumpus_y = y;
            }
        } while (empty = false);
    }
    cout << "You now have " << this->num_arrows << " left." << endl;
}


// Checks if the game's win or lose conditions have been met.
bool Game::winner() {
    // Check if the player found the gold and reached the escape room
    if (this->gold == true && this->player_x == this->escape_x && this->player_y == this->escape_y) {
        cout << "You found the gold and escaped! You win!" << endl;
        return true;
    }
    // Check if the Wumpus is dead
    if (!this->wumpus) {
        cout << "You have defeated the Wumpus!" << endl;
        return true;
    }
    // Check if the player is killed by the Wumpus
    if (this->wumpus && (this->player_x == this->wumpus_x && this->player_y == this->wumpus_y)) {
        cout << "The Wumpus has killed you! Game Over." << endl;
        return true;
    }
    // Check if the player is killed by a stalactite
    // Assuming 's' represents a stalactite in your room event
    if (this->room_arr[this->player_x][this->player_y]->get_event() == 's') {
        cout << "You were killed by a stalactite! Game Over." << endl;
        return true;
    }

    return false;
}