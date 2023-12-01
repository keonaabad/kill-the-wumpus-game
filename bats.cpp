#include "bats.h"

// Constructor for Bats class, initializes event, prompt, and precept properties.
Bats::Bats() {
    this->event = 'b';
    this->prompt = "Angry Superbats attacked you! Directions reversed for 5 moves. :(";
    this->precept = "You hear wings flapping...";
}

// Returns the event character representing bats.
char Bats::get_event() const {
    return this->event;
}

// Returns the prompt message for a bat encounter.
string Bats::get_prompt() const {
    return this->prompt;
}

// Returns the precept message indicating the presence of bats.
string Bats::get_precept() const {
    return this->precept;
}

// Handles the encounter with bats, setting the confused state.
// Parameters: bool confused - Indicates whether the player is confused.
void Bats::encounter(bool confused) {
    confused = true;
    cout << "\n\nYou were attacked by SUPERBATS and your directions are reversed for 5 turns!!! Damn." << endl;
}
