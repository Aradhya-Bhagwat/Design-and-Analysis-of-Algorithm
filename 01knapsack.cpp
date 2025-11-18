/*Implement 0/1 Knapsack OR Traveling Salesperson problem using Dynamic Programming*/

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int knapsack(int W, vector<int> &weights, vector<int> &values, int n)
{
    vector<vector<int>> B(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            if (weights[i] <= w)
            {
                B[i][w] = max(values[i] + B[i - 1][w - weights[i]], B[i - 1][w]);
            }
            else
            {
                B[i][w] = B[i - 1][w];
            }
        }
    }

    cout << "\nDP Table (B):\n";
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            cout << setw(3) << B[i][w] << " ";
        }
        cout << endl;
    }

    int w = W;
    vector<int> selectedItems;

    for (int i = n; i > 0 && w > 0; i--)
    {
        if (B[i][w] != B[i - 1][w])
        {
            selectedItems.push_back(i);
            w -= weights[i];
        }
    }

    cout << "\nItems selected :\n";
    for (int i = selectedItems.size() - 1; i >= 0; i--)
    {
        int idx = selectedItems[i];
        cout << "Item " << idx << ": Value = " << values[idx] << ", Weight = " << weights[idx] << endl;
    }

    return B[n][W];
}

int main()
{
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    vector<int> values(n + 1), weights(n + 1);

    cout << "Enter the values of items:\n";
    for (int i = 1; i <= n; i++)
    {
        cout << "Value of item " << i << ": ";
        cin >> values[i];
    }

    cout << "Enter the weights of items:\n";
    for (int i = 1; i <= n; i++)
    {
        cout << "Weight of item " << i << ": ";
        cin >> weights[i];
    }

    cout << "Enter knapsack capacity: ";
    cin >> W;

    int maxValue = knapsack(W, weights, values, n);
    cout << "\nMaximum value in Knapsack: " << maxValue << endl;

    return 0;
}
