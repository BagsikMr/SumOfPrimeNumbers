#include <iostream>
#include <memory>
#include <algorithm>

using namespace std;

const int MAX_ARRAY_SIZE = 128;
const int FIRST_PRIME_NUMBER = 2;

bool CanBeDecomposed(int numberToCheck, int component, int* pns);
bool IsPrimeNumber(int a);
int NextPrimeNumber(int a);
void FillWithTwos(int* array, int numberOfCells, int startFrom);
bool AllEqual(int* array, int numberOfCells, int startFrom);
void NumberOfCells(int* array, int* numberOfCells, int* value);
void Decompose(int numberToCheck, int component);
int main()
{
    int numberOfCases = 0, number, max;
    cout << "Enter how many causes you want to consider\n";
    cin >> numberOfCases;
    for (int a = 0; a < numberOfCases; a++)
    {
        cout << "Enter a number\n";
        cin >> number;
        cout << "Enter the maximum prime number\n";
        cin >> max;
        if (IsPrimeNumber(max))
        {
            if (number == max)
            {
                cout << max << endl;
            }
            else
            {
                Decompose(number, max);
            }
        }
    }
    return 0;
}

bool CanBeDecomposed(int numberToCheck, int component, int* pns) //pns - pojemnik na componenti
{
    int ite = 0;
    int tempCheck = numberToCheck;
    tempCheck -= component;
    while (true)
    {
        tempCheck -= pns[ite];
        ite++;
        if (tempCheck == 0)
        {
            return true;
        }
        if (tempCheck < 0)
        {
            return false;
        }
    }
}
bool IsPrimeNumber(int a)
{
    if (a < 2) return false;
    for (int i = 2; i*i <= a; i++)
    {
        if (a % i == 0)
        {
            return false;
        }
    }

    return true;

}
int NextPrimeNumber(int a)
{
    a++;
    while (!IsPrimeNumber(a))
    {
        a++;
    }
    return a;
}
void FillWithTwos(int* array, int numberOfCells, int startFrom)
{
    std::fill(array + startFrom, array + numberOfCells + 1, 2);
}
bool AllEqual(int* array, int numberOfCells, int startFrom)
{
    int comparasionValue = array[startFrom];
    for (int i = startFrom; i < numberOfCells; i++)
    {
        if (comparasionValue != array[i])
        {
            return false;
        }
    }
    return true;
}
void NumberOfCells(int* array, int* numberOfCells, int* value)
{
    int temp = 0;
    while (*value >= 0)
    {
        *value -= array[temp++];
        if (*value > 0)
        {
            (*numberOfCells)++;
        }
        temp++;
    }
}
void Decompose(int numberToCheck, int component)
{
    auto componentContainer = std::make_unique<int[]>(MAX_ARRAY_SIZE);

    int numberOfCells = 0, iterator = 0, tempCheck, tempCheckPrev, arrayIterator = 0;
    bool firstTime = true;

    for (int i = 0; i < MAX_ARRAY_SIZE; i++)
    {
        componentContainer[i] = FIRST_PRIME_NUMBER;
    }

    while (componentContainer[0] <= component)
    {
        numberOfCells = 0;
        iterator = 0;
        tempCheck = numberToCheck;
        tempCheckPrev = numberToCheck - component;

        NumberOfCells(componentContainer.get(), &numberOfCells, &tempCheckPrev);

        if (!firstTime)
        {
            if (numberOfCells < arrayIterator)
            {
                arrayIterator = 0;
            }
            while (!AllEqual(componentContainer.get(), numberOfCells, arrayIterator))
            {
                arrayIterator++;
            }
            componentContainer[arrayIterator] = NextPrimeNumber(componentContainer[arrayIterator]);
            arrayIterator++;
            FillWithTwos(componentContainer.get(), numberOfCells, arrayIterator);
        }
        firstTime = false;
        numberOfCells = 0;

        if (componentContainer[0] <= component)
        {
            if (CanBeDecomposed(numberToCheck, component, componentContainer.get()))
            {
                tempCheck -= component;
                cout << component;
                while (tempCheck != 0)
                {
                    tempCheck -= componentContainer[iterator];
                    cout << "+" << componentContainer[iterator];
                    iterator++;
                }
                cout << endl;
            }
        }
    }

}