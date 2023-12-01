#ifndef STALICITES_H
#define STALICITES_H

#include "event.h"
using namespace std;

class Stalicites : public Event {
public:
    // Constructor for the Stalicites class. Initializes the properties related to stalactites.
    Stalicites();

    // Returns the event character representing stalactites.
    char get_event() const;

    // Returns the prompt message for encountering stalactites.
    string get_prompt() const;

    // Returns the precept message indicating the presence of stalactites.
    string get_precept() const;

    // Handles the encounter with stalactites, typically resulting in the player's death.
    void encounter(bool);
};

#endif
