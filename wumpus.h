#ifndef WUMPUS_H
#define WUMPUS_H

#include "event.h"
using namespace std;

class Wumpus : public Event {
public:
    // Constructor for the Wumpus class. Initializes the properties related to the Wumpus.
    Wumpus();

    // Returns the event character representing the Wumpus.
    char get_event() const;

    // Returns the prompt message for encountering the Wumpus.
    string get_prompt() const;

    // Returns the precept message indicating the presence of the Wumpus.
    string get_precept() const;

    // Handles the encounter with the Wumpus, typically resulting in the player's death.
    void encounter(bool);
};

#endif
