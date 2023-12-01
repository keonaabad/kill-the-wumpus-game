#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <iostream>

using namespace std;

class Event {
protected:
    char event;    // Character representing the type of event
    string precept; // Description of the event's precept
    string prompt;  // Prompt or message associated with the event

public:
    // Constructor for the Event class. Initializes the event, precept, and prompt.
    Event();

    // Pure virtual function to get the event character.
    // Returns a char representing the event.
    virtual char get_event() const = 0;

    // Pure virtual function to get the prompt message.
    // Returns a string containing the prompt message.
    virtual string get_prompt() const = 0;

    // Pure virtual function to get the precept message.
    // Returns a string containing the precept message.
    virtual string get_precept() const = 0;

    // Pure virtual function to handle an encounter with this event.
    // Parameters: bool - A flag indicating a specific state during the encounter.
    virtual void encounter(bool) = 0;
};

#endif
