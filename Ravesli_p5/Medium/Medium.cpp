// Medium.cpp : displays a cost table, for example,
// apples in the range from 100 g to 1 kg in 100 g increments.


#include <iostream>
#include <iomanip>

int main()
{
    std::cout << "Enter the price per 1 kilo of apples: ";
    double price;
    std::cin >> price;
    std::cout << "\t  Weigh\t" << "  Cost\n";
    std::cout << "\t   (g)\t" << " (dol.)\n";
    int weigh = 100;
    
    while (weigh <= 1000)
    {
        std::cout << std::fixed;
        std::cout << std::setprecision(2) << "\t " << std::setw(5) << std::right << weigh << "\t " << std::setw(5) << std::right << weigh * price / 1000 << '\n';
        weigh += 100;
    }

}

