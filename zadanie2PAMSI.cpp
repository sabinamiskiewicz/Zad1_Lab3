#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

template <typename T>
class Tablica{
	T *dane;
	int rozm;
public:
/*Domyslny*/
	Tablica(int rozmiar): rozm(rozmiar)
	{
		cout << "w konstruktorze\n";
		dane=new T[rozmiar];
	}
	/*Destruktor*/
	~Tablica() 
	{
		cout << "w destruktorze\n";
		delete[] dane;
	}
	/*Konstruktor kopuijacy*/
	Tablica(const Tablica<T> & inna): rozm(inna.wezRozmiar())
	{
		cout << "w konstruktorze kopiujacym\n";
		dane = new T[rozm];
		copy(inna.begin(), inna.end(), dane);
	}
	
	const int wezRozmiar() const {return rozm;}
	const T *begin() const {return dane;}
	const T *end() const {return dane+rozm;}
	T& operator [](size_t i) {return dane[i];}
	const T& operator [](size_t i) const//nie zmieniam klasy, zadnego pola
	{
		return dane[i];
	}
	Tablica & operator = (const T *tab)
	{
		cout << "proba przypisania tablicy z pierwszym elementem: " << *tab << endl;
		return *this;
	}
	/*Funkcja doajaca element do konca tablicy
	alokuje tablice o 1 wieksza od rozmiaru starej
	kopiuje stara do nowej
	usuwa stara
	dodaje elem na koniec tablicy nowej*/
	void push_back(const T & elem)
	{
		T *tab1=new T[rozm+1];
		copy(dane,dane+rozm,tab1);
		tab1[rozm]=elem;
		delete[] dane;
		dane=tab1;
		rozm++;
	}
	/*Funkcja wusuwaj¹ca ostatni element tablicy
	alokuje tablice
	kopiuje zawartosc starej do nowej
	usuwa stara
	zmiejsza rozmiar*/
	void pop_back()
	{
		T *tab1=new T[rozm-1];
		copy(dane,dane+rozm-1,tab1);
		delete[] dane;
		dane=tab1;
		rozm--;
	}
	/*Funkcja wyœwietlajaca tablice*/
	void wyswietl (ostream & wyjscie)
	{
		for(int i=0;i<rozm;i++)
		{
			wyjscie << dane[i] << endl;
		}
	}
	/*Funckja wczytujaca do tablicy*/
	void wczytaj(istream & wejscie)
	{
		for(int i = 0; i < rozm; i++)
		{
			wejscie >> dane[i];
		}
	}
	/*Funkcja przypisujaca wartosc obiektu pierwszemu obiektowi drugiemu i na odwrót*/
	void swap(Tablica& inna){
		Tablica temp(inna);
		inna.dane = dane;
		inna.rozm = rozm;

		rozm = temp.rozm;
		dane = new int[rozm];
		copy(temp.begin(), temp.end(), dane);
	}

};
template <typename T>
ostream & operator<<(ostream & out, Tablica<T>& tab) {
	tab.wyswietl(out);
	return out;
}

template <typename T>
istream & operator>>(istream & in, Tablica<T>& tab) {
	tab.wczytaj(in);
	return in;
}

/*!
* \brief Funkcja glowna
*
* Funkcja glowna zapoczatkowywuje dzialanie programu.
* Zawiera wywolania.
* Testuje dzialanie programu.
*/
int main()
{
	Tablica<int> x(2);
	cout << "Podaj " << x.wezRozmiar() << " liczb\n";
	cin >> x;

	Tablica<int> y(2);
	cout << "Podaj " << y.wezRozmiar() << " liczb\n";
	cin >> y;
/*
	cout << "Dodaje 666 i 777\n";
	x.push_back(666); x.push_back(777);

	cout << x;
	cout << "Wzwalam koncowke\n";
	x.pop_back();
*/
	cout << "X:" << x;
	cout << "Y:" << y;
	x.swap(y);
	cout << "X:" << x;
	cout << "Y:" << y;

	int rozmiar; cin>>rozmiar;
	return 0;
}