

//https://vjudge.net/contest/652391#problem/F
/*Cerinta:You are given an array of n integers, and your task is to find two values(at distinct positions) whose sum is x.
Input
The first input line has two integers n and x: the array size and the target sum.
The second line has n integers a_1, a_2, \dots, a_n: the array values.
Output
Print two integers : the positions of the values.If there are several solutions, you may print any of them.If there are no solutions, print IMPOSSIBLE.
Constraints

1 \le n \le 2 \cdot 10 ^ 5
1 \le x, a_i \le 10 ^ 9

Example
Input :
4 8
2 7 5 1

Output :
    2 4
*/
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;  //n-nr de elem din array si x-suma target

    vector<int> array(n);
    for (int i = 0; i < n; i++) 
    {
       cin >> array[i];     //valorile array ului
    }

    unordered_map<int, int> seen;   //unorder map care retine elementele deja procesate din vector și pozițiile lor 

    for (int i = 0; i < n; i++) 
    {
        int complement = x - array[i];  //elementul care contribuie la suma e aflat din suma -element

        if (seen.find(complement) != seen.end())    //daca elementul ce contribuie la suma exista
        {
           cout << seen[complement] + 1 << " " << i + 1 <<endl; //afiseaza pozitiile elem :complement si array[i]
            return 0; 
        }

        seen[array[i]] = i;         //adauga elementul curent si poz sa in map
    }

   cout << "IMPOSSIBLE" <<endl;     //daca nu exista afiseaza imposibil

    return 0;
}
