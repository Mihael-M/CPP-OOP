// Event.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "EventManager.h"

int main()
{
    Date date1(2012, 3, 14);
    Date date2(2015, 2, 28);
    Date date3(2023, 12, 31);
    Date date4(2025, 10, 6);

    Event event1("Lookout", date3, 13, 15);
    Event event2("Pinockio", date2, 16, 17);
    Event event3("Pluto", date1, 12, 18);
    Event event4("Cristmas", date4, 15, 20);
    Event event5("Clalcium", date4, 16, 18);
    Event eventsList[] = { event1,event2,event3 };

    EventManager list(eventsList, 3);

    list.addEvent(event4);
    list.addEvent(event5);
    list.printEvents();
    std::cout << std::endl;


    list.deleteEvent("Carse");
    list.printEvents();
    std::cout << std::endl;

    std::cout << "The longest event is: " << std::endl;
    list.findLongestEvent().printEvent();
    std::cout << std::endl;


    std::cout << list.getEventsAtDate(date2) << std::endl;

   
}