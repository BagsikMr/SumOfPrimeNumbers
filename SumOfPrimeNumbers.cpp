#include <iostream>

using namespace std;

#define MAKS_ROZMIAR_TABLICY_DLA_BAJTA 128
#define PIERWSZA_LICZBA_PIERWSZA 2
//Notka dla mnie
//FIX do naprawy
//TEST/Y do usuniêcia,testowania
//przerzuæ komendy na dó³ potem

bool CzyDaSieRozbic(int sprawdzana, int skladnik, int* pns) //pns - pojemnik na skladniki
{
    int ite = 0;
    int tempspr = sprawdzana;
    tempspr -= skladnik;
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
bool CzyLiczbaPierwsza(int a)
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
int NastepnaLiczbaP(int a)
{
    a++;
    while (CzyLiczbaPierwsza(a) == false)
    {
        a++;
    }
    return a;
}
void ZapelnienieDwojkami(int* tablica, int ilosckomorek, int odktorej)
{
    for (int a = odktorej; a < ilosckomorek + 1; a++)
    {
        tablica[a] = 2;
    }
}
bool WszystkieRowne(int* tablica, int ilosckomorek, int odktorej)
{
    int porownanie;
    bool wystapienie = false;
    porownanie = tablica[odktorej];
    for (int a = odktorej; a < ilosckomorek; a++)
    {
        if (porownanie != tablica[a])
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
void IleKomorek(int* tablica, int* ilosckomorek, int* wartosc)
{
    int temp = 0;
    while (*wartosc >= 0)
    {
        *wartosc -= tablica[temp++];
        if (*wartosc > 0)
        {
            temp++;
            (*ilosckomorek)++;
        }
    }
}
void Rozbicie(int sprawdzana, int skladnik)
{
    int* pojemniknaskladowe; //do przechowywania zmiennych
    int ilosckomorek = 0, ite = 0, tempspr, tempsprpjs, iteratortablicy = 0;
    bool pierwszyraz = true;
    pojemniknaskladowe = new int[MAKS_ROZMIAR_TABLICY_DLA_BAJTA];

    for (int a = 0; a < MAKS_ROZMIAR_TABLICY_DLA_BAJTA; a++)
    {
        pojemniknaskladowe[a] = PIERWSZA_LICZBA_PIERWSZA;
    }

    while (pojemniknaskladowe[0] <= skladnik)
    {
        ilosckomorek = 0;
        ite = 0;
        tempspr = sprawdzana;
        tempsprpjs = sprawdzana - skladnik;

        IleKomorek(pojemniknaskladowe, &ilosckomorek, &tempsprpjs);

        if (pierwszyraz == false) //jeœli pierwszy element nie bêdzie zerem to reszta mi potrzebnych te¿ nie,
        {
            if (ilosckomorek < iteratortablicy) //zabezpieczenie wyjœcia poza u¿yteczn¹ tablice
            {
                iteratortablicy = 0;
            }
            while (WszystkieRowne(pojemniknaskladowe, ilosckomorek, iteratortablicy) == false)
            {
                iteratortablicy++;
            }
            pojemniknaskladowe[iteratortablicy] = NastepnaLiczbaP(pojemniknaskladowe[iteratortablicy]);
            iteratortablicy++;
            ZapelnienieDwojkami(pojemniknaskladowe, ilosckomorek, iteratortablicy); //na prawo od liczby która lvl up robi, zape³nia mi tablice dwójkami
        }
        pierwszyraz = false;
        ilosckomorek = 0;

        if (pojemniknaskladowe[0] <= skladnik)
        {
            if (CzyDaSieRozbic(sprawdzana, skladnik, pojemniknaskladowe) == true)
            {
                tempspr -= skladnik;
                cout << skladnik;
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
int main()
{
    int ilelini = 0, liczba, maks;
    cin >> ilelini;
    for (int a = 0; a < ilelini; a++)
    {
        cin >> liczba;
        cin >> maks;
        if (CzyLiczbaPierwsza(maks) == true)
        {
            if (liczba == maks)
            {
                cout << maks << endl;
            }
            else
            {
                Rozbicie(liczba, maks);
            }
        }
    }
    return 0;
}