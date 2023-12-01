#include "wumpus.h"

// Constructor for the Wumpus class. Initializes properties related to the Wumpus.
Wumpus::Wumpus() {
    this->event = 'w';
    this->prompt = "You found the Wumpus!! He ate you and returned to sleep. :(";
    this->precept = "You smell a terrible stench... ew";
}

// Returns the event character representing the Wumpus.
char Wumpus::get_event() const {
    return this->event;
}

// Returns the prompt message for encountering the Wumpus.
string Wumpus::get_prompt() const {
    return this->prompt;
}

// Returns the precept message indicating the presence of the Wumpus.
string Wumpus::get_precept() const {
    return this->precept;
}

// Handles the encounter with the Wumpus, typically resulting in the player's death.
void Wumpus::encounter(bool) {
    cout << "\n\n" << this->prompt << endl;
}
