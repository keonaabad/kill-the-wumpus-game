#include "stalicites.h"

// Constructor for the Stalicites class. Initializes properties related to stalactites.
Stalicites::Stalicites() {
    this->event = 's';
    this->prompt = "You fell into an abyss and died! :(";
    this->precept = "You feel a breeze...";
}

// Returns the event character representing stalactites.
char Stalicites::get_event() const {
    return this->event;
}

// Returns the prompt message for encountering stalactites.
string Stalicites::get_prompt() const {
    return this->prompt;
}

// Returns the precept message indicating the presence of stalactites.
string Stalicites::get_precept() const {
    return this->precept;
}

// Handles the encounter with stalactites, typically resulting in the player's death.
void Stalicites::encounter(bool) {
    cout << "\n\n" << this->prompt << endl;
}
