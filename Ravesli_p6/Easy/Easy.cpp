// Easy.cpp : сравнивает два введенных с клавиатуры числа
// и выводит какое число меньше, или, если числа равны —
// соответствующее сообщение.


#include <iostream>

int main()
{
    int num1, num2;
    std::cout << "Enter 2 integers: ";
    std::cin >> num1 >> num2;

    if (num1 == num2)
        std::cout << '\t' << num1 << " is equel " << num2 << '\n';
    else
    {        
        std::cout << '\t' << ((num1 < num2) ? num1 : num2) << " less than " << ((num1 < num2) ? num2 : num1) << '\n';                 
    }
    return 0; 
}

