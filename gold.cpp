#include "gold.h"

// Constructor for the Gold class. Initializes gold-related properties.
Gold::Gold() {
    this->event = 'g';
    this->prompt = "You found the gold!!!";
    this->precept = "You see a glimmer nearby...";
}

// Returns the event character representing the gold.
char Gold::get_event() const {
    return this->event;
}

// Returns the prompt message for finding the gold.
string Gold::get_prompt() const {
    return this->prompt;
}

// Returns the precept message indicating the presence of gold.
string Gold::get_precept() const {
    return this->precept;
}

// Handles the encounter with the gold, printing the found message.
void Gold::encounter(bool) {
    cout << "\n\n" << this->prompt << endl;
}
