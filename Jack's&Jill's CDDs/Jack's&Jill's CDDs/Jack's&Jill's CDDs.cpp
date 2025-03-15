//https://open.kattis.com/problems/cd
/*Jack and Jill have decided to sell some of their Compact Discs, while they still have some value. They have decided to sell one of each of the CD titles that they both own. How many CDs can Jack and Jill sell?

Neither Jack nor Jill owns more than one copy of each CD.

Input
The input consists of a sequence of test cases. The first line of each test case contains two positive integers 
 and 
, each at most one million, specifying the number of CDs owned by Jack and by Jill, respectively. This line is followed by 
 lines listing the catalog numbers of the CDs owned by Jack in increasing order, and 
 more lines listing the catalog numbers of the CDs owned by Jill in increasing order. Each catalog number is a positive integer no greater than one billion. The input is terminated by a line containing two zeros. This last line is not a test case and should not be processed.

Output
For each test case, output a line containing one integer, the number of CDs that Jack and Jill both own.

Sample Input 1	Sample Output 1
3 3     
1
2
3
1
2
4
0 0
2*/
#include <iostream>
#include <set>
using namespace std;

void reading(set<int>& s, int SIZE) 
{
    int value;
    for (int i = 0; i < SIZE; i++) 
    {
        cin >> value;       //se citesc nr de catalog
        s.insert(value);    // si se adauga intr un set pt a fii doar o data
    }
}

/*
void displaying(const set<int>& s) 
{
    for (auto i = s.begin(); i != s.end(); ++i) 
    {
        cout << *i << " "; // folosim iterator pentru a parcurge set-ul
    }
    cout << endl;
}
*/

int CDs_both_own(const set<int>& s1, const set<int>& s2)
{
    int count = 0;
    for (auto i = s1.begin(); i != s1.end(); ++i) 
    {
        if (s2.find(*i) != s2.end())    //daca elementul curent din s1 exista in s2
        {
            count++;        //numara cate cd uri au in comun
        }
    }
    return count;       //si returneaza numarul
}

int main() 
{
    while (true) 
    {
        int N, M;       //num de cd uri detinute de jack and jill
        cin >> N >> M;

        if (N == 0 && M == 0) 
        {
            break;
        }

        set<int> Jack;  
        set<int> Jill;

        reading(Jack, N);
        //displaying(Jack);

        reading(Jill, M);
        //displaying(Jill);

        int commonCount = CDs_both_own(Jack, Jill);
        cout << commonCount << endl;
    }
    return 0;
}
