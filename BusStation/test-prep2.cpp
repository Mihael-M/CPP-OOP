// test-prep2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BusStation.h"

int main()
{
    Passenger passenger1("Alice", 25);
    Passenger passenger2("Bob", 30);
    Passenger passenger3("Charlie", 40);
    Passenger passenger4("Diana", 35);
    Passenger passengers[] = { passenger1,passenger2 };
    Passenger passengers2[] = { passenger3,passenger4 };
    Bus bus1("omi", 10, 20, 20,passengers,2);
    Bus bus2("omi", 10, 20, 21,passengers2,2);
    Bus busses[] = { bus1,bus2 };
    BusStation bs(busses, 3, 2);
    std::cout<<bs.hasTicket(passenger1);
}

