// Simple.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

template <typename T>
T getValue();

int getDenominator(double floatValue);
double speed(int distance, double time);

int main()
{
    std::cout << "Enter running distance , meter: ";
	int distance = getValue<int>();

	std::cout << "Enter the time, minute.seconds: ";
	double time = getValue<double>();

	int denominator = getDenominator(time);
	int numerator = static_cast<int>(time);

	std::cout << "You have entered time: " << numerator << " minutes and " << denominator << " seconds. \n\n";

	std::cout << "You ran the distance at a speed: " << speed(distance, time) << " km/hour \n";


	return 0;
}

template <typename T>
T getValue()
{
	while (true)
	{
		
		T a;
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

int getDenominator(double floatValue)
{
	int factor = 1;
	double temp = floatValue;
	while ((temp - static_cast<int>(temp)) != 0)
	{
		temp *= 10;
		factor *= 10;
	}
	int wholePart = static_cast<int>(floatValue);
	int fractionalPart = (floatValue - wholePart) * factor;
	return fractionalPart;
}

double speed(int distance, double time)
{
	int minuteTime = static_cast<int>(time);
	double secondTime = (time - minuteTime) * 100;
	time = minuteTime * 60 + secondTime;
	return (distance/1000) / (time/3600);
}
