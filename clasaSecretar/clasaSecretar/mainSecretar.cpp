#include <iostream>
#include "Secretar.h"
#include "Scoala.h"
#include <vector>
#include <algorithm>
using namespace std;

void testSecretari()
{
	int nrScoli;
	cout << "Introdu nr de scoli: ";
	cin >> nrScoli;

	vector<Secretar> secretari(nrScoli);
	//Citire secretari
	for (int i = 0; i < nrScoli; i++)
	{
		cout << "Secretarul " << i + 1<<": \n";
		cin >> secretari[i];
	}

	//Sortarea descrescatoare a secretarilor dupa nr de clase deservite
	sort(secretari.begin(), secretari.end(), [](const Secretar & a, const Secretar & b)
	{
		return a > b;
	});

	for (const auto& secretar : secretari)
	{
		cout << secretar << "\n";
	}
}

int main()
{
	testSecretari();

	//Cream obj de tip scoala
	Scoala<string>gimnaziala("Scoala gimnaziala nr 5");
	gimnaziala.adaugaActivitate("intocmire cataloage");
	gimnaziala.adaugaActivitate("Inscriere clasa a 5 a");
	gimnaziala.afiseazaActivitati();

	Scoala<string>liceu("Liceul tehnologic Matei Basarab Strehaia");
	liceu.adaugaActivitate("Consiliere elevi pt facultate");
	liceu.adaugaActivitate("Inscriere elevi pt liceu");
	liceu.afiseazaActivitati();

	Scoala<string>ScoalaSpec("Scoala Aurel Vlaicu pt copii cu nevoi speciale");
	ScoalaSpec.adaugaActivitate("Inscriere in program special de recuperare");
	ScoalaSpec.adaugaActivitate("Organizare activitati terapeutice");
	ScoalaSpec.afiseazaActivitati();

	return 0;
}