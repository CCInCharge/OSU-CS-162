/******************************************************************************
** Program name: binarySearch.cpp
** Author: Charles Chen
** Date: 02/28/2017
** Description:
Implementation of binary search algorithm, based on Gaddis Ch 9.1.
******************************************************************************/

#include <iostream>
#include <fstream>
#include <vector>

/*
binarySearch(std::vector<int> numbers, int searchValue)
binarySearch takes a vector of integers and a search value, and returns the
index of this search value from the vector. Returns -1 if the number is not
found
*/
int binarySearch(std::vector<int> numbers, int searchValue)
{
    // If there are no numbers in the vector, then the value that is searched
    // for is not in the vector
    if (numbers.size() == 0)
    {
        return -1;
    }

    int index = -1;
    int first = 0;
    int last = numbers.size() - 1;

    // While the numbers hasn't been found, bisect the search array in half
    while ((numbers[index] != searchValue) && (first <= last))
    {
        // Find the midpoint of the current subarray
        index = (last + first) / 2;

        // If the midpoint is tne number that is being searched for, return
        // its index
        if (numbers[index] == searchValue)
        {
            return index;
        }
        else if (numbers[index] > searchValue)
        {
            last = index - 1;
        }
        else
        {
            first = index + 1;
        }
    }
    return -1;
}

int main()
{
    std::ifstream numbersFile("sorted.txt");

    std::vector<int> numbers;
    int current;

    // Reads in data from file into vector
    while (numbersFile >> current)
    {
        numbers.push_back(current);
    }

    // Prints elements in vector
    std::cout << "Vector:" << std::endl;
    for (int i = 0; i < numbers.size(); i++)
    {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Using binary search to find index of number in vector";
    std::cout << std::endl;

    std::cout << "Index of 0: ";
    std::cout << binarySearch(numbers, 0) << std::endl;
    std::cout << "Index of 1: ";
    std::cout << binarySearch(numbers, 1) << std::endl;
    std::cout << "Index of 2: ";
    std::cout << binarySearch(numbers, 2) << std::endl;
    std::cout << "Index of 3: ";
    std::cout << binarySearch(numbers, 3) << std::endl;
    std::cout << "Index of 9: ";
    std::cout << binarySearch(numbers, 9) << std::endl;
    std::cout << "Index of 10: ";
    std::cout << binarySearch(numbers, 10) << std::endl;

}
