#include "EventManager.h"

void EventManager::setEvents(const Event* events, int eventsNum) {
    for (int i = 0; i < eventsNum; i++) {
        this->events[i] = events[i];
    }
}

void EventManager::setEventsNum(int eventsNum) {
    this->eventsNum = eventsNum;
}

EventManager::EventManager(const Event* events, int eventsNum) {
    setEvents(events, eventsNum);
    setEventsNum(eventsNum);
}

void EventManager::addEvent(const Event& event) {
    if (eventsNum < EVENTS_MAX_COUNT) {
        events[eventsNum] = event;
        eventsNum++;
    }
}

void EventManager::deleteEvent(const char* eventName) {

    for (int i = 0; i < eventsNum; i++) {
        if (std::strcmp(events[i].getName(), eventName) == 0) {
            for (int j = i; j < eventsNum - 1; j++) {
                events[j] = events[j + 1];
            }
            eventsNum--;
            std::cout << "The event" << " " << events[i].getName() << " " << "was successfully deleted!" << std::endl;
            return;
        }
    }
}


bool isOverlap(int start1, int end1, int start2, int end2) {
    return start1 < end2 && end1 > start2;
}

int EventManager::getEventsAtDate(const Date& date) {

    int eventsCount = 0;

    for (int i = 0; i < eventsNum; i++) {
        if (events[i].getDate().day == date.day &&
            events[i].getDate().year == date.year &&
            events[i].getDate().month == date.month) {
            bool isIntersected = false;
            for (int j = 0; j < i; j++) {
                if (isOverlap(events[i].getStartHour(), events[i].getEndHor(), events[j].getStartHour(), events[j].getEndHor())) {
                    isIntersected = true;
                    break;
                }
            }
            if (!isIntersected) {
                eventsCount++;
            }
        }
    }
    return eventsCount;
}

Event EventManager::findLongestEvent() {

    int longestEventLen = 0;
    Event longestEvent;
    for (int i = 0; i < eventsNum; i++) {
        int currLen = events[i].getEndHor() - events[i].getStartHour();
        if (currLen > longestEventLen) {
            longestEventLen = currLen;
            longestEvent = events[i];
        }
    }
    return longestEvent;
}



void EventManager::printEvents() const {
    for (int i = 0; i < eventsNum; i++) {
        events[i].printEvent();
    }
}