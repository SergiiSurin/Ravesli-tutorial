// mystring.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#include <iomanip>

class MyString
{
public:
	MyString();
	MyString(const char* str);
	~MyString();
	MyString(const MyString& other);
	MyString& operator=(const MyString& other);
	bool operator==(const MyString& other);
	char& operator[](int index) { return m_str[index]; }
	MyString operator+(const MyString& other);
	friend std::ostream& operator<<(std::ostream& out, const MyString& other);
	friend std::istream& operator>>(std::istream& in, MyString& other);
	int length() { return m_length; }
	MyString(MyString&& other);
	
private:
	char* m_str;
	int m_length;
};

MyString::MyString()
{
	m_str = nullptr;
	m_length = 0;
}

MyString::MyString(const char* str)
{
	m_length = strlen(str);
	m_str = new char[m_length + 1];
	for (int i = 0; i < m_length; ++i)
	{
		m_str[i] = str[i];
	}
	m_str[m_length] = '\0';
} 

MyString::~MyString()
{
	delete[] m_str;
}

MyString MyString::operator+(const MyString& other)
{
	if (m_str == nullptr)
	{
		return other;
	}
	MyString newStr;
	newStr.m_length = m_length + other.m_length;
	newStr.m_str = new char[newStr.m_length + 1];
	int i = 0;
	for (; i < m_length; ++i)
		newStr.m_str[i] = m_str[i];
	for (int j = 0; j < other.m_length; ++i, ++j)
		newStr.m_str[i] = other.m_str[j];
	newStr.m_str[newStr.m_length] = '\0';
	return newStr;
}

MyString::MyString(const MyString& other)
{
	if (other.m_str == nullptr)
	{
		m_str = nullptr;
		m_length = 0;
	}
	m_length = strlen(other.m_str);
	m_str = new char[m_length + 1];
	for (int i = 0; i < m_length; ++i)
		m_str[i] = other.m_str[i];
	m_str[m_length] = '\0';
	
}

MyString::MyString(MyString&& other)
{
	m_length = other.m_length;
	m_str = other.m_str;
	other.m_str = nullptr;
}

MyString& MyString::operator=(const MyString& other)
{
	if (m_str != nullptr)
	{ 
		delete[] m_str;
	}
	m_length = strlen(other.m_str);
	m_str = new char[m_length + 1];
	for (int i = 0; i < m_length; ++i)
		m_str[i] = other.m_str[i];
	m_str[m_length] = '\0';
	return *this;
}

bool MyString::operator==(const MyString& other)
{
	if (m_length != other.m_length)
		return false;
	for (int i = 0; i < m_length; ++i)
	{
		if (m_str[i] != other.m_str[i])
			return false;
	}
	return true;
}

std::ostream& operator<<(std::ostream& out, const MyString& str1)
{
	out << str1.m_str;
	return out;
}

std::istream& operator>>(std::istream& in, MyString& str1)
{
	
	in.get(str1.m_str, 35);
	str1.m_length = strlen(str1.m_str);		
	return in;
}

int main()
{
	MyString string1 ("Hello ");
	//std::cout << string1.length();
	//std::cout << std::endl;
	MyString string2 ("World!");
	//std::cout << string2.length();
	//std::cout << std::endl;
	MyString string3("                                              ");
	std::cin >> string3;
	std::cout << std::endl;
	std::cout << string3;
	string3 = string1 + string2;
	/*string1 = string1 + string2;
	std::cout << string1.length();
	std::cout << std::endl;
	std::cout << string1;
	std::cout << std::endl;
	string3 = string3 + string1;
	
	std::cout << string2.length();
	std::cout << std::endl;
	if(string1==string3)
	std::cout << string3[6];
	string3[0] = 'Q';*/
	std::cout << std::endl;
	std::cout << string3;
	return 0;
}
