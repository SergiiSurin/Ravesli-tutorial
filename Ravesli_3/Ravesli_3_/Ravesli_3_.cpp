// Ravesli_3_.cpp : An ice cream sandwich is a string formed by two identical ends and
// different middle. An ice cream sandwich must have a minimum length of three
// character, and at least two of those characters must be different.

#include <iostream>
#include <string>

bool isIcecreamSandwich(std::string str, int len);

int main()
{
    std::string sequence;
    std::cout << "Enter a sequence of two characters longer than three: ";
    std::cin >> sequence;
    
    int len = sequence.length();
        
   std::cout << std::endl << "The " << sequence << " is" << ((isIcecreamSandwich(sequence, len)) ? " " : " not ") << "an Icecream Sandwich" << std::endl;
   
}

bool isIcecreamSandwich(std::string str, int len)
{
    if (len < 3)
        return false;
    int count = 1;
    char tmp = str[0];
    std::string reverseStr = str;
    for (int i = 0, j = len-1; i < len; ++i, --j)
    {
        if (tmp != str[i] && i<=(len/2))
            ++count;
        reverseStr[j] = str[i];
        tmp = str[i];
    }
    if (count != 2)
        return false;
    return (str == reverseStr);
}
