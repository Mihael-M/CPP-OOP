#pragma once
#include<iostream>
struct Date {
    int year = 0;
    int month = 0;
    int day = 0;


    Date() = default;
    Date(int year, int month, int day);

    void printDate() const;
};
