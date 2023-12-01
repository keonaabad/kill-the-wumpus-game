#ifndef BATS_H
#define BATS_H

#include "event.h"

using namespace std;

class Bats : public Event {
public:
    // Constructor for Bats class, initializes event, prompt, and precept properties.
    Bats();

    // Returns the event character representing bats.
    char get_event() const;

    // Returns the prompt message for a bat encounter.
    string get_prompt() const;

    // Returns the precept message indicating the presence of bats.
    string get_precept() const;

    // Handles the encounter with bats, setting the confused state.
    // Parameters: bool confused - Indicates whether the player is confused.
    void encounter(bool confused);
};

#endif
