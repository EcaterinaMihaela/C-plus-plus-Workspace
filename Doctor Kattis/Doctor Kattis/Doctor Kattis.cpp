//https://open.kattis.com/problems/doctorkattis

#include <iostream>
#include <deque>
#include <unordered_map>
#include <fstream>
#include <algorithm>
using namespace std;

int main() 
{
    ifstream inputFile("input.txt");

    if (!inputFile)
    {
        cerr << "Error opening the file" << endl;
        return 1;
    }

    int t;
    inputFile >> t;  // citim numărul de comenzi

    deque<pair<string, int>> clinic;  // pentru a păstra pisicile și infecțiile lor
    unordered_map<string, int> infectionLevels;  // toate infectiile pt fiecare pisica ca sa le gest usor
    while (t!=0) 
    {
        int command;
        inputFile >> command;  // citim comanda

        if (command == 0)       //caz 0 pisica vine la clinica,nu returneaza nimic
        {
            string catName;
            int infectionLevel;
            inputFile >> catName >> infectionLevel;  //se citeste numele si niv de infectie al pisicii
            clinic.push_back({ catName, infectionLevel });      //se adauga la clinica pisica
            infectionLevels[catName] = infectionLevel;          //se adauga niv de infectie la map ul de infectii al tutuor pisicilor
        }
        else if (command == 1)      //caz 1 ,se actualizeaza niv de infectie al pisicii prin adaugare la vechi cel nou
        {
            string catName;
            int increaseInfection;
            inputFile >> catName >> increaseInfection;  //se citesc atributele pisicii,nume si noua val care se adauga la infectie
            infectionLevels[catName] += increaseInfection;  //la niv curent infectia creste cu valoarea noua

            for (auto& p : clinic)  //se actualizeaza infectia la val noua in deque
            {
                if (p.first == catName) //in pair la nume actualizeaza infectia
                {
                    p.second = infectionLevels[catName];
                    break;
                }
            }
        }
        else if (command == 2)  //caz 2,pisica tratata,pleaca din clinica,returneaza  numele pisicii
        {
            string catName;
            inputFile >> catName;  
          
            clinic.erase(remove_if(clinic.begin(), clinic.end(), [&](const pair<string, int>& p)   //sterge pisica tratata
                {
                return p.first == catName;
                }), clinic.end());
            infectionLevels.erase(catName);
        }
        else if (command == 3)  //caz 3,Ouery()- pisica cu cel mai mare grad de infectie,returneaza numele ei
        {
            if (clinic.empty()) 
            {
                cout << "The clinic is empty" << endl;      ///daca clinica e goala
            }
            else 
            {
                auto maxInfection = max_element(clinic.begin(), clinic.end(), [](const pair<string, int>& p1, const pair<string, int>& p2) 
                    {
                    return p1.second < p2.second;
                    });
                cout << maxInfection->first << endl;        //afiseaza numele pisicii cu infectia ces mai mare
            }
        }
        t--;    //decrementam t pana nu mai avem comenzi
    }

    inputFile.close();

    return 0;
}
