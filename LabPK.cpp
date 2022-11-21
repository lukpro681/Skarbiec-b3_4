#include <iostream>
#include <algorithm>
#define ZadanieP

using namespace std;
/* Zmieniając ostatnią literę w poniższej instrukcji na D (dodatkowe), lub P (podstawowe)
*  wybierasz aktywne zadanie.
*
*  UWAGA: jeśli rozwiązanie zadań wymaga podziału programu na pliki to dodaj je wszystkie do
*  projektu, ale przy każdym zadaniu "includuj" tylko te, które jego dotyczą.
*  Poniższe bloki dotyczą zadań z zajeć.
*/
 

#ifdef ZadanieD

template<typename typ, size_t rozmiar> class Urna {
private:
	typ m_Urna[rozmiar] = {};
	int m_rozmiar;
	int m_licznik = m_rozmiar;
public:
	Urna() {}
	Urna(typ* u, int rozmiar)
		:m_rozmiar(rozmiar)
	{
		if (typeid(this) == typeid(u)) //jeżeli typ danych urny jest równy typowi danych innej urny
			wypelnijTablice(u, rozmiar);
	}
	void setRozmiar(int rozmiar) { m_rozmiar = rozmiar; }
	int getRozmiar() { return m_rozmiar; }
	void wypelnijTablice(typ* ur, int rozmiar2) { //rozmiar2 = rozmiar drugiej urny
		if (rozmiar2 >= m_rozmiar)
		{
			for (size_t i = 0; i < m_rozmiar; i++)
			{
				m_Urna[i] = ur[i];
			}
		}
		else
		{
			for (size_t i = 0; i < rozmiar2; i++)
			{
				m_Urna[i] = ur[i];
			}
		}
	}

	typ losowanie()
	{
		srand(time(0));
		typ wynik;
		if (m_licznik <= 0)
			reset();
		int los = rand() % m_licznik--;
		wynik = m_Urna[los];
		swap(m_Urna[los], m_Urna[m_licznik]);
		return wynik;
	}
	void reset() { m_licznik = rozmiar; }

	bool operator==(const Urna& ur) const
	{
		int licznik_elem = 0; //licznik znalezionych elementow
		bool wystepuje = 0; // zmienna sterująca potrzebna do if
		if (this->m_rozmiar <= ur.m_rozmiar)
		{
			for (size_t i = 0; i < this->m_rozmiar; i++)
			{
				if (wystepuje)
				{
					licznik_elem++;
					wystepuje = 0;
				}
				for (size_t j = 0; j < ur.m_rozmiar; j++)
				{
					if (wystepuje)
						break;
					if (this->m_Urna[i] == ur.m_Urna[j])
						wystepuje = 1;
				}
			}
			if (licznik_elem == this->m_rozmiar)
				return true;
			else return false;
		}
		else
		{
			for (size_t i = 0; i < ur.m_rozmiar; i++)
			{
				if (wystepuje)
				{
					licznik_elem++;
					wystepuje = 0;
				}
				for (size_t j = 0; j < this->m_rozmiar; j++)
				{
					if (wystepuje)
						break;
					if (ur.m_Urna[i] == this->m_Urna[j])
						wystepuje = 1;
				}
			}
			if (licznik_elem == ur.m_rozmiar)
				return true;
			else return false;
		}
	}
};

int main() {
	int tab1[] = { 1,2,3,4,5,6,7,8 };
	int tab2[] = { 4,2,5,1,6,8,3,3 };
	int tab3[] = { 1,2,3,4,5,6,7,8 };

	Urna<int, 8> u1(tab1, 8);
	Urna<int, 8> u2(tab2, 8);
	Urna<int, 8> u3(tab3, 8);

	cout << typeid(u1).name() << endl;
	cout << typeid(u2).name() << endl;

	cout << u1.losowanie() << endl;
	cout << u2.losowanie() << endl;


	if (u1 == u2)
		cout << "Te same" << endl;
	else cout << "nie" << endl;

	if (u1 == u3)
		cout << "Te same" << endl;
	else cout << "nie" << endl;
}
#endif

#ifdef ZadanieP

template<typename typ, size_t rozmiar>
typ tablica(typ(&tablica)[rozmiar])
{
	cerr << "[";
	for (size_t i = 0; i < rozmiar; i++)
	{
		cerr << tablica[i] << " ";
	}
	cerr << "]\n";
}

template<size_t rozmiar>
char tablica(char(&tablica)[rozmiar])
{
	cerr << "[";
	for (size_t i = 0; i < rozmiar; i++)
	{
		cerr << (char)tablica[i] << " ";
	}
	cerr << "]\n";
}

template<typename typ, size_t rozmiar>
typ sortowanie(typ* tab, size_t rozmiar) { //algorytm zrobiony w ramach laboratioriów na przedmiocie AiSD
	{
		for (int i = 0; i < rozmiar - 1; i++)
			for (int j = i + 1; j < rozmiar; j++)
				if (tab[i] > tab[j])
				{
					elementy temp = tab[i];
					tab[i] = tab[j];
					tab[j] = temp;
				}
		return tab;
	}
}

template<typename typ>
typ powtarzanie(typ *elem_tab)
{
	sortowanie(elem_tab, rozmiar);
	int licznik_powtorzen = 1, najwiecej_powtorzen = 1;
	for (int i = 1; i < rozmiar; i++)
	{
		if (typeid(tab).name() == char&& tab[i] == tab[i - 1])				//w przypadku tablicy char
			if (tablica[i] != ' ' && tablica[i] != '\n' && tablica[i] != '\t') // ^
			{ licznik_powtorzen++; }										   // ^

		if (tab[i] == tab[i - 1])
			licznik_powtorzen++;
		else
		{
			if (licznik_powtorzen > najwiecej_powtorzen)
			{
				najwiecej_powtorzen = licznik_powtorzen;
				elem_tab = tab[i - 1];
			}
			licznik_powtorzen = 1;
		}
	}

	if (licznik_powtorzen > najwiecej_powtorzen)
		elem_tab = tab[rozmiar - 1];

	return elem_tab;
}

//void test_int()
//{
//	int tab[] = { 5, 8, 8, 9, 10, 8, 4, 8 };
//	tablica(tab, 5);
//	if (powtarzanie(tab) == 8)
//		cerr << "OK\n";
//	else cerr << "FAIL\n";
//}													W instrukcji napisane żeby w mainie było
//														a co w instrukcji to święte
//void test_char()
//{
//	char tab[] = { 'a', 'a', 'c', 'b', 'e' };
//	tablica(tab,5);
//	if (powtarzanie(tab) == 'a')
//		cerr << "OK\n";
//	else cerr << "FAIL\n";
//	
//}

int main() {
	int tab1[] = { 5, 8, 8, 9, 10, 8, 4, 8 };
	char tab2[] = { 'a', 'a', 'c', 'b', 'e' };
	tablica(tab1, 8);
	tablica(tab2, 5);
	cout << "TABLICA 1: " << typeid(tab1).name() << endl;
	if (powtarzanie(tab1) == 8)
		cerr << "OK\n";
	else cerr << "FAIL\n";
	cout << "TABLICA 2: " << typeid(tab2).name() << endl;
	if (powtarzanie(tab2) == 'a')
		cerr << "OK\n";
	else cerr << "FAIL\n";
}

#endif

#ifdef ZadanieA

// TU UMIEŚĆ KOD ROZWIAZANIA ZADANIA AMBITNEGO

#endif

