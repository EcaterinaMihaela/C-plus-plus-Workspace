#ifndef POMFRUCTIFER_H
#define POMFRUCTIFER_H

#include <string>
#include <iostream>
using namespace std;

class PomFructifer
{
private:
	string specie;
	string perioada_recoltare;
	double productie;

public:
	//constructor implicit
	PomFructifer() :specie(""), perioada_recoltare(""), productie(0.0) {}

	//constructor cu parametrii
	PomFructifer(const string& specie,const string& perioada_recoltare,int productie)
		:specie(specie),perioada_recoltare(perioada_recoltare),productie(productie){}

	//constructor de copiere
	PomFructifer(const PomFructifer& other):
		specie(other.specie),perioada_recoltare(other.perioada_recoltare),productie(other.productie){}
	
	//operatorul ==
	bool operator==(const PomFructifer& other) const
	{
		return this->specie == other.specie;
	}

	//operator de extractie
	friend istream& operator>>(istream& in, PomFructifer& s)
	{
		cout << "Introdu specia pomului fructifer: ";
		in >> s.specie;
		cout << "Introdu perioada de recoltare:";
		in >> s.perioada_recoltare;
		cout << "Introdu productia anuala: ";
		in >> s.productie;

		return in;
	}

	friend ostream& operator<< (ostream & out, PomFructifer & s)
	{
		out << "Specia pomului fructifer este: " << s.specie << ",perioada de recoltare este: " << s.perioada_recoltare << ",productia este de " << s.productie << "kg pe an" << endl;
		return out;
	}
};
#endif
