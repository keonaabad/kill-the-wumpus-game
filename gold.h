#ifndef GOLD_H
#define GOLD_H

#include "event.h"
using namespace std;

class Gold : public Event {
public:
    // Constructor for the Gold class. Initializes the gold-related properties.
    Gold();

    // Returns the event character representing the gold.
    char get_event() const;

    // Returns the prompt message for finding the gold.
    string get_prompt() const;

    // Returns the precept message indicating the presence of gold.
    string get_precept() const;

    // Handles the encounter with the gold, printing the found message.
    void encounter(bool);
};
#endif
