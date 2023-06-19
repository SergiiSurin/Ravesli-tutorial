// Easy.cpp : recalculation of the value of the time interval specified in
// minutes to a value expressed in hours and minutes


#include <iostream>

int main()
{
    std::cout << "Enter the time interval in minutes: ";
    int minutesTime;
    std::cin >> minutesTime;

    std::cout << minutesTime << " minutes = " << minutesTime/60 << " h. " << minutesTime%60 << " min.\n";

    return 0;
}
