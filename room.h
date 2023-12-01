#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include "event.h"
#include "wumpus.h"
#include "gold.h"
#include "stalicites.h"
#include "bats.h"

using namespace std;

class Room {
private:
    char event; // Character representing the type of event in the room
    bool player; // Flag indicating if the player is in the room
    bool wumpus; // Flag indicating if the Wumpus is in the room
    bool gold; // Flag indicating if the gold is in the room
    bool stalicites; // Flag indicating if stalactites are in the room
    bool bats; // Flag indicating if bats are in the room
    bool escape; // Flag indicating if the room is an escape room

public:
    // Constructor for the Room class. Initializes the room with default properties.
    Room();

    // Destructor for the Room class. Cleans up dynamically allocated event objects.
    ~Room();

    Event* event_arr; // Pointer to an Event object, dynamically allocated based on the event type

    // Checks if the room currently has any event and returns a boolean value.
    bool has_event();

    // Sets the event character for the room and initializes corresponding event objects.
    void set_event(char event);

    // Deprecated function, potentially for returning event details (not implemented).
    void return_event();

    // Returns the event character of the room.
    char get_event() const;

    // Outputs the precept of the event in the room.
    void return_precept();

    // Sets or clears the escape flag for the room.
    void set_escape(const bool valid);

    // Deprecated function, potentially for checking some property (not implemented).
    char check();
};

#endif
