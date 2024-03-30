#pragma once
#include "Event.h"

const int EVENTS_MAX_COUNT = 20;

class EventManager {

private:
    Event events[EVENTS_MAX_COUNT];
    int eventsNum = 0;


public:
    EventManager() = default;
    EventManager(const Event* events, int eventsNum);


    void setEvents(const Event* events, int eventsNum);
    void setEventsNum(int eventsNum);

    void addEvent(const Event& event);
    Event findLongestEvent();
    int getEventsAtDate(const Date& date);
    void deleteEvent(const char* eventName);

    void printEvents() const;

};
