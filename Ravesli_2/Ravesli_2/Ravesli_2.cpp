/* Ravesli_2.cpp : write a program that determines the minimum number 
in a sequence of positive numbers that the user has entered. If there 
are negative numbers in the sequence, then you must inform the user 
about this and offer to repeat the input again.*/

#include <iostream>
#include "limits.h"

bool enterOneMoreNumber()
{
    char ch;
    do
    {
        std::cout << "Would you like to enter one more number (y/n)? ";
        std::cin >> ch;
    } while (ch != 'y' && ch != 'n');

    return (ch == 'y');
}

int main()
{
    int num = 0;
    int min = INT_MAX;
   
    std::cout << "Enter any sequence of positive numbers. " << std::endl;
    
    while (true)
    { 
        std::cin >> num;
        if (num < 0)
        {
            std::cout << "You entered a negative number. Please enter a correct positive number " << std::endl;
            continue;
        }

    if (num < min)
        min = num;

    if (!enterOneMoreNumber())
        break;
    
    }
    std::cout << "The minimal number in sequence is " << min << std::endl;
}
