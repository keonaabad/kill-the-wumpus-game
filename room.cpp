#include "room.h"

// Constructor for the Room class. Initializes the room with default properties.
Room::Room() {
    this->event = ' ';
    this->player = false;
    this->gold = false;
    this->stalicites = false;
    this->bats = false;
    this->escape = false;
}


// Destructor for the Room class. Cleans up dynamically allocated event objects.
Room::~Room() {
    delete this->event_arr;
    this->event_arr = NULL;
}


// Checks if the room currently has any event.
bool Room::has_event() {
    if (this->event == '*' || this->event == 'w' || this->event == 'g' || this->event == 'b' || this->event == 's') {
        return true;
    }
    else {
        return false;
    }
}

// Sets the event character for the room and initializes corresponding event objects.
void Room::set_event(char event) {
    if (event == '*') {
        this->event = '*';
        this->player = true;
    }
    else if (event == 'w') {
        this->event = 'w';
        this->wumpus = true;
        this->event_arr = new Wumpus;
    }
    else if (event == 'g') {
        this->event = 'g';
        this->gold = true;
        this->event_arr = new Gold;
    }
    else if (event == 'b') {
        this->event = 'b';
        this->bats = true;
        this->event_arr = new Bats;
    }
    else if (event == 's') {
        this->event = 's';
        this->stalicites = true;
        this->event_arr = new Stalicites;
    }
    else {
        this->event = ' ';
    }
}


// Returns the event character of the room.
char Room::get_event() const {
    if (this->event == '*') {
        return this->event;
    }
    else if (this->event == 'w') {
        return this->event;
    }
    else if (this->event == 'g') {
        return this->event;
    }
    else if (this->event == 'b') {
        return this->event;
    }
    else if (this->event == 's') {
        return this->event;
    }
}


// Outputs the precept of the event in the room.
void Room::return_precept() {
    if (event == 'w'){
        cout << endl << event_arr->get_precept() << endl << endl;
    } else if(event == 'b'){
        cout << endl << event_arr->get_precept() << endl << endl;
    }else if(event == 's'){
        cout << endl << event_arr->get_precept() << endl << endl;
    }else if(event == 'g'){
        cout << endl << event_arr->get_precept() << endl << endl;
    }else if(event == '*'){
        cout << endl << event_arr->get_precept() << endl << endl;
    }
}


// Sets or clears the escape flag for the room.
void Room::set_escape(const bool valid) {
    if (valid == true) {
        this->escape = true;
    }
    else {
        this->escape = false;
    }
}
