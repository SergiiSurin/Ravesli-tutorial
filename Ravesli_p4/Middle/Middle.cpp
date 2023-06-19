// Middle.cpp : calculates the arithmetic mean sequences of fractional numbers entered
// from the keyboard. After entering by the user of the last number, the program should 
// display the minimum and the maximum number in the sequence. Number of sequence numbers
// the user enters.


#include <iostream>
#include <limits>

int main()
{
    int numSequence;
    std::cout << "Enter the number of sequence numbers: ";
    std::cin >> numSequence;

    std::cout << "Enter the sequence: ";
    
    int count = 0;
    double min = DBL_MAX, max = DBL_MIN, average = 0, sum = 0;
    while (count < numSequence)
    {
        double sequence;
        std::cin >> sequence;
        if (sequence < min)
            min = sequence;
        if (sequence > max)
            max = sequence;
        sum += sequence;
        ++count;
    }

    std::cout << "The average number of the sequence: " << sum/numSequence << '\n';
    std::cout << "The minimum number of the sequence: " << min << '\n';
    std::cout << "The maximum number of the sequence: " << max << '\n';

}
