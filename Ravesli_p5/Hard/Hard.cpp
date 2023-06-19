// Hard.cpp : a timer program that, after a predetermined interval,
// time(which the user enters) gives a beep


#include <iostream>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <iomanip>

class Timer
{
private:
    int m_hh;
    int m_mm;
    int m_ss;
public:
    Timer (int hh = 0, int mm = 0, int ss = 0)
        : m_hh(hh), m_mm(mm), m_ss(ss)
    {
    }
    //void setTimer(int hh, int mm, int ss) { m_hh = hh; m_mm = mm; m_ss = ss; }
    int timeToSec();
    Timer& operator--();
    friend std::ostream& operator<<(std::ostream& out, const Timer& t1);
    friend std::istream& operator>>(std::istream& in, Timer& t1);
};

std::ostream& operator<<(std::ostream& out, const Timer& t1)
{
    std::cout.fill('0');
    out << std::setw(2) << std::right << t1.m_hh << ":" << std::setw(2) << std::right << t1.m_mm << ":" << std::setw(2) << std::right << t1.m_ss;
    return out;
}

std::istream& operator>>(std::istream& in, Timer& t1)
{
    char c;
        
    in >> t1.m_hh;
    in >> c; // игнорируем разделитель ':'
    in >> t1.m_mm;
    in >> c; // игнорируем разделитель ':'
    in >> t1.m_ss;
    
    return in;
}

void SetWindowSize(COORD newsize)//newaize recive the number of characters been showed on window
{
    CONSOLE_SCREEN_BUFFER_INFOEX consolesize;

    consolesize.cbSize = sizeof(consolesize);

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    GetConsoleScreenBufferInfoEx(hConsole, &consolesize);

    COORD c;
    c.X = newsize.X;
    c.Y = newsize.Y;
    consolesize.dwSize = c;
    consolesize.dwMaximumWindowSize = c; //change the window max size

    consolesize.srWindow.Left = 0;
    consolesize.srWindow.Right = c.X;
    consolesize.srWindow.Top = 0;
    consolesize.srWindow.Bottom = c.Y;
    //srWindow, c and dwMaximumWindowSize are the same
    //here i don't use pixels. for that i must get the current font size and then calculate the number of characters

    SetConsoleScreenBufferInfoEx(hConsole, &consolesize);
    SetConsoleWindowInfo(hConsole, FALSE, &consolesize.srWindow);
}

void gotoxy(int x, int y)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position = { short(x), short(y) };

    SetConsoleCursorPosition(hStdout, position);
}

void wait(Timer& time)
	{
		clock_t end_wait;
        int start = time.timeToSec();
		end_wait = clock() + start * CLK_TCK;
		
        gotoxy(25, 1);
        std::cout << time;

		while (clock() < end_wait) 
		{
            int current = (end_wait - clock()) / 1000;
            if((start - current) > 1)
            { 
                --start;
                --time;
                gotoxy(25,1);
			    std::cout << time;            
            }
            Sleep(1000);
		}
        gotoxy(25, 1);
        std::cout << --time;
	}

int main()
{
    COORD position = { 80, 25 };
    SetWindowSize(position);
    
    std::cout << "Enter timer interval in format (hh:mm:ss): ";
    Timer time;
    gotoxy(43, 0);
    std::cout << "  :  :  ";
   /* int hh, mm, ss;
    
    gotoxy(43, 0);
    std::cin >> hh;
    
    gotoxy(46, 0);
    std::cin >> mm;
    
    gotoxy(49, 0);
    std::cin >> ss;
    
    time.setTimer(hh, mm, ss);*/
    gotoxy(43, 0);
    std::cin >> time;
	std::cout << "Start of Waiting!";

    CONSOLE_CURSOR_INFO curs = { 0 };
    curs.dwSize = sizeof(curs);
    curs.bVisible = FALSE;
    // получаешь handle для stdout и устанавливаешь для этого хэндла видимость курсора curs.bVisible = FALSE;
    ::SetConsoleCursorInfo(::GetStdHandle(STD_OUTPUT_HANDLE), &curs); 
 
	wait(time);	
   
    std::cout << "\nEnd of Waiting!\n";
	Beep(500, 500);
		
	return 0;	
}

int Timer::timeToSec()
{
    return m_hh * 3600 + m_mm * 60 + m_ss;
}

Timer& Timer::operator--()
{
    if (m_ss == 0)
    {
        if (m_mm == 0)
        {
            --m_hh;
            m_mm = 59;
            m_ss = 59;
        }
        else
        { 
            --m_mm;
            m_ss = 59;
        }
    }
    else
    { 
    --m_ss;
    }
    return *this;
    
}
