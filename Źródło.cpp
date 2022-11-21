#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <new>
#include <random>

using namespace std;
#define Zad2

#ifdef Zad1

class Zbior
{
	size_t m_liczbaElementow = 0;
	double* m_elementy = nullptr;
	double m_dolnaGranica = 0;
	double m_gornaGranica = 0;
	void alokuj(int);
	void zwolnij();
	double suma() const
	{
		double wynik = 0;
		for (size_t i = 0; i < m_liczbaElementow; i++)
		{
			wynik += m_elementy[i];
		}
		return wynik;
	}
public:
	Zbior(size_t liczElem, double dGran, double gGran);
	~Zbior() { zwolnij(); }
	void setLm(size_t l_elem, double dGran, double gGran)
	{	
		if (l_elem == 0)
		{
			zwolnij();

		}
		uniform_real_distribution<double> zakres(dGran, dGran);
		random_device generator;
		if (m_elementy != nullptr) // zaalokowane
		{
			if (this->m_liczbaElementow != l_elem) //realokacja
			{
				double* temp = new double[l_elem];
				size_t liczba = (l_elem < m_liczbaElementow) ? l_elem : m_liczbaElementow;
				for (size_t i = 0; i < liczba; i++)
				{
					if (m_elementy[i] < dGran || m_elementy[i] > gGran)
						temp[i] = zakres(generator);
					else temp[i] = m_elementy[i];
				}
				for (size_t i = liczba; i < l_elem; i++)
				{
					temp[i] = zakres(generator);
				}
				zwolnij();
				m_elementy = temp;
			}
			else { //brak realokacji, WERYFIKACJA czy elementy istniej¹ce
				for (size_t i = 0; i < l_elem; i++)
				{
					if (m_elementy[i] < dGran || m_elementy[i] > gGran)
						m_elementy[i] = zakres(generator);
				}
			}
		}
		else { //brak alokacji
		alokuj(l_elem);
		for (int i = 0; i < l_elem; i++)
		{ 
				m_elementy[i] = zakres(generator);
		}
		
	}
	m_liczbaElementow = l_elem;
	m_dolnaGranica = dGran;
	m_gornaGranica = gGran;
		
	}
	bool operator>(const Zbior& zb);
	bool operator<(const Zbior& zb);
	operator double();
	static Zbior fromInt(int n)
	{
		return Zbior(n, 0, 1);
	}
};


Zbior::operator double()
{
	return suma();
}

bool Zbior::operator>(const Zbior& zb) {
	return this->suma() > zb.suma();
}
bool Zbior::operator<(const Zbior& zb) {
	return this->suma() < zb.suma();
}


void Zbior::alokuj(int n)
{
	if (n > 0)
	{
		m_elementy = new(std::nothrow) double[n];
		m_liczbaElementow = n;
}
}

void Zbior::zwolnij()
{
	if (m_elementy != nullptr)
	{
		delete[] m_elementy;
		m_elementy = nullptr;
	}
}

Zbior::Zbior(size_t liczElem, double dGran, double gGran)
{
	alokuj(liczElem);
	uniform_real_distribution<double> zakres(dGran, dGran);
	random_device generator;
	for (int elem = 0; elem < liczElem; elem++)
		m_elementy[elem] = zakres(generator);
}

int main() {

}

#endif

#ifdef Zad2

using namespace std;

template<class T>
												
T wartosci(T& kol) {
	T wynik;
	for (auto iter = kol.begin(); iter != kol.end(); ++iter) {
		int liczba = count(kol.begin(), kol.end(), *iter);
		if (liczba >= 2) {
			wynik.push_back(*iter);
			cout << *iter << " ";
		}
		
	}
	sort(wynik.begin(), wynik.end());
	wynik.erase(unique(wynik.begin(), wynik.end()), wynik.end());
	return wynik;
}


int main()
{

	int n;
	cin >> n;
	random_device srng;
	mt19937 rng(srng());
	uniform_int_distribution<int> dist(0, 9);
	vector<int> vec(n);
	for (auto iter = vec.begin(); iter != vec.end(); iter++)
		*iter = dist(rng);
	for (int& element : vec)
		cout << element << " ";

	cout << endl;

	auto newvec = wartosci(vec);
	cout << endl;
	reverse(newvec.begin(), newvec.end());
	for (int& element : newvec)
		cout << element << " ";
}

#endif