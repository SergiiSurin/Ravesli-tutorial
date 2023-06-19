// Medium.cpp : displays a message in "telegraphic" style:
// message letters should appear one at a time with some delay.



#include <iostream>
#include <windows.h>

int main()
{
    std::cout << "Enter a massage to send by teletype: \n";

	
		char ch;
		while (std::cin.get(ch))
		{ 
			Sleep(1000);
			std::cout << ch;
			Sleep(1000);
		}
		return 0;
	
}
