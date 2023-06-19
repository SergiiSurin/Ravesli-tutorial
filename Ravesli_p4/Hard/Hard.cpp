// Hard.cpp : combines two sorted in ascending order
// array into one(also ordered) array


#include <iostream>
#include <vector>
#include <stdio.h>

void initArray(std::vector<int>& arr);
void combinesSortedArrays(int size, const std::vector<int>& arr1, const std::vector<int>& arr2, std::vector<int>& result);

int main()
{
    std::vector<int> array1;
    std::vector<int> array2;
    std::vector<int> result;

    std::cout << "Enter the elements of the first array: ";
    initArray(array1);
    
    std::cout << "Enter the elements of the second array: ";
    initArray(array2);
       
    int size = array1.size() + array2.size();

    combinesSortedArrays(size, array1, array2, result);

    std::cout << "Result array: ";
    for (auto const& element : result)
        std::cout << element << ' ';
    std::cout << "\n\n";
}

void initArray(std::vector<int>& arr)
{
    while (1)
    {
        int num;
        std::cin >> num;
        arr.push_back(num);
        char ch;
        std::cin.get(ch);
        if (ch == '\n')
            break;
    }
}

void combinesSortedArrays(int size, const std::vector<int>& arr1, const std::vector<int>& arr2, std::vector<int>& result)
{
    std::vector<int>::const_iterator it1;
    it1 = arr1.begin();

    std::vector<int>::const_iterator it2;
    it2 = arr2.begin();


    for (int i = 0; i < size; ++i)
    {
        if ((it1 == arr1.end()) && (it2 == arr2.end()))
            break;

        if ((it1 == arr1.end()) && (it2 != arr2.end()))
        {
            result.push_back(*it2);
            ++it2;
            continue;
        }

        if ((it1 != arr1.end()) && (it2 == arr2.end()))
        {
            result.push_back(*it1);
            ++it1;
            continue;
        }

        if (*it1 < *it2)
        {
            result.push_back(*it1);
            ++it1;
        }
        else
        {
            result.push_back(*it2);
            ++it2;
        }
    }
   
}
