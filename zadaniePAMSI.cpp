#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int *alokacja_tablicy(int rozmiar);
int *alokacja_tablicy_kopii(int *tablica, int rozmiar);
void zwolnienie_pamieci(int *tablica);
int *wczytaj_z_tekstu(istream& wejscie,int rozmiar);
void wczytaj_do_tekstu(ostream& wyjscie,int rozmiar,int *tablica);
int *zmiana_rozmiaru(int *tablica, int rozmiar,int rozmiar_new);

/*!
* \brief Funkcja glowna
*
* Funkcja glowna zapoczatkowywuje dzialanie programu.
* Zawiera wywolania funcji.
* Zawiera Sprawdzenie dzialanie funkcji.
*/
int main()
{
	int rozmiar=6;
	int *wskaznik=alokacja_tablicy(rozmiar);
	cout<<alokacja_tablicy_kopii(wskaznik,rozmiar)[0]<<endl;
	zwolnienie_pamieci(wskaznik);
	wczytaj_z_tekstu(cin,rozmiar);
	cout<<alokacja_tablicy_kopii(wskaznik,rozmiar)[0]<<endl;
	wczytaj_do_tekstu(cout,rozmiar,wskaznik);
	int rozmiar_new;
	cin>>rozmiar_new;
	int *nowa_tablica=zmiana_rozmiaru(wskaznik,rozmiar,rozmiar_new);
	cin>>rozmiar;
	return 0;
}
/*!
* \brief Funkcja alokujacja tablice dynamiczna.
*
* Zwraca tablice nowo zaalokowana,
*/
int *alokacja_tablicy(int rozmiar)
{
//int *tablica = new int[rozmiar];
	return new int[rozmiar];
}
/*!
* \brief Funkcja kopiujaca
*
* Funkcja alokuje nowa tablice.
* Kopuje zawartosc starej tablicy do nowej.
* Zwraca nowa tablice, wypelniona starymi wartosciami.
*/
int *alokacja_tablicy_kopii(int *tablica, int rozmiar)
{
	int *tablica_kopii=new int[rozmiar];
	copy (tablica,tablica+rozmiar-1,tablica_kopii);
	return tablica_kopii;
}
/*!
* \brief Funkcja zwalniajaca pamiec
*
* Usuwa rezerwowany obszar przez tablice.
*/
void zwolnienie_pamieci(int *tablica)
{
	delete tablica;
}
/*!
* \brief Funkcja wczytujaca z tekstu.
*
* Alokuje tablice.
* Wypelnia ja warosciami pochodzacymi ze strumienia wejsciowego.
* Zwraca tablice
*/
int *wczytaj_z_tekstu(istream& wejscie,int rozmiar)
{
	int *tablica = new int[rozmiar];
	for(int i=0;i<rozmiar;i++)
		{
			wejscie>>tablica[i];
		}
	return tablica;
}
/*!
* \brief Funkcja wczytuje do tekstu
*
* Na wyjscie tekstowe podaje zawarosc tablicy.
*/
void wczytaj_do_tekstu(ostream& wyjscie,int rozmiar,int *tablica)
{
	for(int i=0;i<rozmiar;i++)
		{
			wyjscie<<tablica[i];
		}
}
/*!
* \brief Funkcja zmieniajaca rozmiar
*
* Alokuje tablice.
* Gdy rozmiar nowej jest mniejszy rowny, to kopiuje zawartosc starej do nowej.
* Gdy rozmiar nowej jest miejszy, to kopiuje zawarotsc starej do nowej, a pozostale wypelnia zerami.
* Zwraca tablice.
*/
int *zmiana_rozmiaru(int *tablica, int rozmiar,int rozmiar_new)
{
	int *tablica1=new int[rozmiar_new];
	if (rozmiar_new<=rozmiar)
		{
			copy (tablica,tablica+rozmiar_new-1,tablica1);
		}
	else
		{
			copy (tablica,tablica+rozmiar-1,tablica1);
			for(int i=rozmiar;i<rozmiar_new;i++)
				{
					tablica1[i]=0;
				}
		}
	return tablica1;
}