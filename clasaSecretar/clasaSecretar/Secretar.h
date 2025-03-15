#ifndef SECRETAR_H
#define SECRETAR_H

#include <iostream>
#include <string.h>
using namespace std;

class Secretar 
{
private:
	string nume_secretar;
	string nume_institutie;
	int vechime;
	int nr_clase_deservite;

public:
	//Constructor implicit
	Secretar() :nume_secretar(""), nume_institutie(""), vechime(0), nr_clase_deservite(0) {}

	//Constructor cu parametrii
	Secretar(const string& nume_secretar,const string& nume_institutie, int vechime, int nr_clase_deservite):
		nume_secretar(nume_secretar), nume_institutie(nume_institutie),vechime(vechime),nr_clase_deservite(nr_clase_deservite){}

	//Constructor de copiere
	Secretar(const Secretar& other):nume_secretar(other.nume_secretar), nume_institutie(other.nume_institutie),vechime(other.vechime),nr_clase_deservite(other.nr_clase_deservite){}

	//Operator >
	bool operator>(const Secretar& other) const
	{
		return nr_clase_deservite > other.nr_clase_deservite;
	}

	friend istream& operator>>(istream& in, Secretar& s)
	{
		cout << "Nume secretar: ";
		in >> s.nume_secretar;
		cout << " Nume intitutie: ";
		in >> s.nume_institutie;
		cout << "Vechime: ";
		in >> s.vechime;
		cout << "Nr clase deservite: ";
		in >> s.nr_clase_deservite;
		return in;
	}

	friend ostream& operator<<(ostream& out, const Secretar& s)
	{
		out << "Nume secretar : " << s.nume_secretar << ",nume institutie: " << s.nume_institutie << ",vechime: " << s.vechime << ",nr clase deservite: " << s.nr_clase_deservite << "." << endl;
		return out;
	}

	int getNrClaseDeservite() const
	{
		return nr_clase_deservite;
	}
};
#endif