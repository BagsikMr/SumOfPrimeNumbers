#include <iostream>

using namespace std;

const int MAX_ARRAY_SIZE_FOR_BYTE = 128;
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
        if (IsPrimeNumber(max) == true)
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
    int tempspr = numberToCheck;
    tempspr -= component;
    while (true)
    {
        tempspr -= pns[ite];
        ite++;
        if (tempspr == 0)
        {
            return true;
        }
        if (tempspr < 0)
        {
            return false;
        }
    }
}
bool IsPrimeNumber(int a)
{
    int ldz = 0;
    for (int i = a; i > 0; i--)
    {
        if (a % i == 0)
        {
            ldz++;
        }
    }
    if (ldz == 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int NextPrimeNumber(int a)
{
    a++;
    while (IsPrimeNumber(a) == false)
    {
        a++;
    }
    return a;
}
void FillWithTwos(int* array, int numberOfCells, int startFrom)
{
    for (int a = startFrom; a < numberOfCells + 1; a++)
    {
        array[a] = 2;
    }
}
bool AllEqual(int* array, int numberOfCells, int startFrom)
{
    int porownanie;
    bool wystapienie = false;
    porownanie = array[startFrom];
    for (int a = startFrom; a < numberOfCells; a++)
    {
        if (porownanie != array[a])
        {
            wystapienie = true;
        }
    }
    if (wystapienie == true) // jeœli pojawi³a siê przynajmniej jedna inna liczba to zwracam false
    {
        return false;
    }
    else // jeœli nie to true
    {
        return true;
    }
}
void NumberOfCells(int* array, int* numberOfCells, int* value)
{
    int temp = 0;
    while (*value >= 0)
    {
        *value -= array[temp++];
        if (*value > 0)
        {
            temp++;
            (*numberOfCells)++;
        }
    }
}
void Decompose(int numberToCheck, int component)
{
    int* pojemniknaskladowe; //do przechowywania zmiennych
    int numberOfCells = 0, ite = 0, tempspr, tempsprpjs, iteratortablicy = 0;
    bool pierwszyraz = true;
    pojemniknaskladowe = new int[MAX_ARRAY_SIZE_FOR_BYTE];

    for (int a = 0; a < MAX_ARRAY_SIZE_FOR_BYTE; a++)
    {
        pojemniknaskladowe[a] = FIRST_PRIME_NUMBER;
    }

    while (pojemniknaskladowe[0] <= component)
    {
        numberOfCells = 0;
        ite = 0;
        tempspr = numberToCheck;
        tempsprpjs = numberToCheck - component;

        NumberOfCells(pojemniknaskladowe, &numberOfCells, &tempsprpjs);

        if (pierwszyraz == false) //jeœli pierwszy element nie bêdzie zerem to reszta mi potrzebnych te¿ nie,
        {
            if (numberOfCells < iteratortablicy) //zabezpieczenie wyjœcia poza u¿yteczn¹ tablice
            {
                iteratortablicy = 0;
            }
            while (AllEqual(pojemniknaskladowe, numberOfCells, iteratortablicy) == false)
            {
                iteratortablicy++;
            }
            pojemniknaskladowe[iteratortablicy] = NextPrimeNumber(pojemniknaskladowe[iteratortablicy]);
            iteratortablicy++;
            FillWithTwos(pojemniknaskladowe, numberOfCells, iteratortablicy); //na prawo od liczby która lvl up robi, zape³nia mi tablice dwójkami
        }
        pierwszyraz = false;
        numberOfCells = 0;

        if (pojemniknaskladowe[0] <= component)
        {
            if (CanBeDecomposed(numberToCheck, component, pojemniknaskladowe) == true)
            {
                tempspr -= component;
                cout << component;
                while (tempspr != 0)
                {
                    tempspr -= pojemniknaskladowe[ite];
                    cout << "+" << pojemniknaskladowe[ite];
                    ite++;
                }
                cout << endl;
            }
        }
    }

    delete[] pojemniknaskladowe;
}