/*Mike and Joe are playing a game with some stones. Specifically, they have 
n piles of stones of sizes a1,a2,a3,...an​
 . These piles are arranged in a circle.
The game goes as follows. Players take turns removing some positive number of stones from a pile in clockwise order starting from pile 
1
Formally, if a player removed stones from pile i
on a turn, the other player removes stones from pile 
((imodn)+1) on the next turn.

If a player cannot remove any stones on their turn (because the pile is empty), they lose. Mike goes first.
If Mike and Joe play optimally, who will win?

Input
Each test contains multiple test cases. The first line contains the number of test cases 
1≤t≤1000). Description of the test cases follows.

The first line of each test case contains a single integer 
1≤n≤50)  — the number of piles.

The second line contains n integers a1,a2,...an (1<=ai<=10^9) the size of piles

Output
For each test case print the winner of the game, either "Mike" or "Joe" on its own line (without quotes).

Examples
Input
2  cazuri de test
1   o gramada
37  cu 37 de pietre
2   2 gramezi
100 100    cu 100 de pietre fiecare

Output
Mike
Joe*/

#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    int t;
    cin >> t; //cazurile de test

    while (t--) {
        int n;
        cin >> n; // Citim numărul de mormane
        vector<int> piles(n);

        // Citim dimensiunile mormanelor
        for (int i = 0; i < n; i++) {
            cin >> piles[i];
        }

        // Calculăm XOR-ul tuturor pilelor
        int xor_sum = 0;
        for (int i = 0; i < n; i++) {
            xor_sum ^= piles[i];
        }

        // Dacă XOR-ul este 0, Joe câștigă, altfel Mike câștigă
        if (xor_sum == 0) {
            cout << "Joe" << endl;
        }
        else {
            cout << "Mike" << endl;
        }
    }

    return 0;
}
