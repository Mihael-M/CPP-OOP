#include "Event.h"
const char* Event::getName() const {
    return this->name;
}

Date Event::getDate() const {
    return this->date;
}

int Event::getStartHour() const {
    return this->startHour;
}

int Event::getEndHor() const {
    return this->endHour;
}

void Event::setName(const char* name) {
    std::strcpy(this->name, name);
}

void Event::setDate(const Date& date) {
    this->date = date;
}

void Event::setStartHour(int startHour) {
    this->startHour = startHour;
}

void Event::setEndHour(int endHour) {
    this->endHour = endHour;
}

Event::Event(const char* name, const Date& date, int startHour, int endHour) {
    setName(name);
    setDate(date);
    setStartHour(startHour);
    setEndHour(endHour);
}


void Event::printEvent() const {
    std::cout << "Event name: " << name << std::endl;
    std::cout << "Available on: ";
    date.printDate();
    std::cout << "Begins at: " << startHour << "o'clock" << std::endl;
    std::cout << "Ends at: " << endHour << "o'clock" << std::endl;
}