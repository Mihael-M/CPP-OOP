#pragma once
#include <iostream>
#include "Date.h"



class Event {
private:
	char name[21] = "unknown";
	Date date;
	unsigned startHour = 0;
	unsigned endHour = 0;
public:
    Event() = default;
    Event(const char* name, const Date& date, int startHour, int endHour);

    const char* getName() const;
    Date getDate() const;
    int getStartHour() const;
    int getEndHor() const;

    void setName(const char* name);
    void setDate(const Date& date);
    void setStartHour(int startHour);
    void setEndHour(int endHour);

    void printEvent() const;


};