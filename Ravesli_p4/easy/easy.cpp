// easy.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

void convertion(double* dist);

int main()
{
    double distance;
    std::cout << "Enter distance at versta: ";
    std::cin >> distance;
    double tmp = distance;
    convertion(&distance);
    std::cout << tmp << " verst = " << distance << " km \n";
}

void convertion(double* dist)
{
    *dist = *dist * 1.0668;
}