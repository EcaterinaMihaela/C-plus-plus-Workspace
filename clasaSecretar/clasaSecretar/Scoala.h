#ifndef SCOALA_H
#define SCOALA_H
#include <iostream>
#include <vector>
using namespace std;

template<typename TipActivitate>
class Scoala
{
private:
	string numeScoala;
	vector<TipActivitate> activitati;
public:
	//constructor implicit
	Scoala() :numeScoala("") {};

	//Constructor cu parametrii
	Scoala(const string& numeScoala) :numeScoala(numeScoala) {};


	//functie pt adaugarea unei activitati
	void adaugaActivitate(const TipActivitate& activitate)
	{
		activitati.push_back(activitate);
	}

	void afiseazaActivitati()const
	{
		cout << "Activitati pt scoala: " << numeScoala << ":\n";
		for (const auto& activitate : activitati)
		{
			cout << "- " << activitate << "\n";
		}
	}
};

#endif