// class_container.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "ArrInt.h"


int main()
{
    ArrInt array{ 7, 6, 5, 4, 3, 2, 1 }; 
    for (int count = 0; count < array.getLength(); ++count)
        std::cout << array[count] << ' ';
    std::cout << std::endl;
    array = { 1, 4, 9, 12, 15, 17, 19, 21 };

    for (int count = 0; count < array.getLength(); ++count)
        std::cout << array[count] << ' ';
    std::cout << std::endl;

    array.resize(7);
    array.insertBefore(15, 4);
    array.remove(7);
    array.insertAtEnd(35);
    array.insertAtBeginning(50);

    for (int count = 0; count < array.getLength(); ++count)
        std::cout << array[count] << ' ';
    std::cout << std::endl;
}

