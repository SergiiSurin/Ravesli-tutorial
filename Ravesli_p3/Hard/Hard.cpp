// Hard.cpp : Write a telegraph program that receives a message from the user and
// displays it on the screen as a sequence of dots and dashes. Output dots and dashes
// may be accompanied by a sound signal of appropriate duration.


#include <iostream>
#include <string>
#include <Windows.h>


struct morzeLetter
{
   char symbol;
   const char* morze;
};

morzeLetter MorzeAlfabet[32]
{
    { 'А', "·-"},
    { 'Б', "-···" },
    { 'В', "·--" },
    { 'Г', "--·" },
    { 'Д', "-··"},
    { 'Е', "·" },
    { 'Ж', "···-" },
    { 'З', "--··" },
    { 'И', "··"},
    { 'Й', "·---" },
    { 'К', "-·-" },
    { 'Л', "·-··" },
    { 'М', "--"},
    { 'Н', "-·" },
    { 'О', "---" },
    { 'П', "·--·" },
    { 'Р', "·-·"},
    { 'С', "···" },
    { 'Т', "-" },
    { 'У', "··-" },
    { 'Ф', "··-·"},
    { 'Х', "····" },
    { 'Ц', "-·-·" },
    { 'Ч', "---·" },
    { 'Ш', "----"},
    { 'Щ', "--·-" },
    { 'Ъ', "·--·-·" },
    { 'Ы', "-·--" },
    { 'Ь', "-··-"},
    { 'Э', "··-··" },
    { 'Ю', "··--" },
    { 'Я', "·-·-" }
};

void upperCase(std::string& str);
std::string transmitToMorze(const char* str);
void sound(const std::string& str);

int main()
{
    system("chcp 1251");

   // receiving a message from the user
    std::string str;
    std::cout << "Enter the message in russian to transmit into Morze signals: \n";
    getline(std::cin, str);
        
   // converting characters to one case 
    upperCase(str);
    std::cout << str << std::endl;

   // converting std::string to C-string 
    const char* strConst = str.c_str();
    
    // transmit C-string to code of Morze 
    std::string codeMorze = transmitToMorze(strConst);
    
    std::cout << codeMorze << '\n';
    sound(codeMorze);

    return 0;
}

void upperCase(std::string &str)
{
    for (auto &symbol: str)
    {
        if (symbol == ' ')
            continue;
        else
        {
            if ((symbol <= -1) && (symbol >= -32))
            {
                symbol -= 32;
            }
            else
                continue;
        }        
    }    
}

std::string transmitToMorze(const char* str)
{
    std::string codeMorze;

    while (*str != '\0')
    {
        if (*str == ' ')
            codeMorze += " ";
        else
        {
            int index = static_cast<int>(*str) + 64;
            codeMorze += MorzeAlfabet[index].morze;
        }
        ++str;
    }
    return codeMorze;
}

void sound(const std::string& str)                        
{                                                      
    for (auto& symbol : str)
    {
        if(symbol == ' ')
            Sleep(700);
        if (symbol == '·')
            Beep(600, 150);
        if (symbol == '-') 
            Beep(600, 450);
        Sleep(100);
    }
    
}
