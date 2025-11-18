/*Write a program for Hamiltonian Problem OR N-Queen problem using Backtracking approach.*/

#include <iostream>
#include <cmath>
using namespace std;

int x[10];

bool Place(int k, int i)
{
    for (int j = 1; j < k; j++)
    {
        if (x[j] == i || abs(x[j] - i) == abs(j - k))
        {
            return false;
        }
    }
    return true;
}

void placeBoard(int n)
{
    cout << "Solution: \n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (x[i] == j)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}

void NQueen(int k, int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (Place(k, i)) 
        {
            x[k] = i; 
            if (k == n) 
            {
                placeBoard(n);
            } 
            else 
            {
                NQueen(k + 1, n); 
            }
        }
    }
}

int main() 
{
    int n;
    cout << "Enter the number of queens: ";
    cin >> n;
    NQueen(1, n); 
    return 0;
}