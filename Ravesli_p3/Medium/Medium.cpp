// Medium.cpp : write a program that calculates the sum of the first n positive integers
// even numbers.The number of numbers to be added is entered by the user.

#include <iostream>

int getValue();

int main()
{
    std::cout << "Enter the number of summed numbers: ";
	int num = getValue();
	int oddNum = 1;
	int count = 0;
	int sumOdd = 0;
	while (count < num)
	{
		if (oddNum % 2 == 0)
		{
			++count;
			std::cout << "The " << count << "\t positive even integers is " << oddNum << "\n";
			sumOdd += oddNum;
			oddNum += 2;
		}
		else 
			++oddNum;
	}
	std::cout << "The sum of the first " << num << " positive even integers is " << sumOdd << "\n\n";
}


int getValue()
{
	while (true)
	{

		int a;
		std::cin >> a;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Oops, that input is invalid.  Please try again.\n";
		}
		else
		{
			std::cin.ignore(32767, '\n');
			std::cout << '\n';
			return a;
		}
	}
}