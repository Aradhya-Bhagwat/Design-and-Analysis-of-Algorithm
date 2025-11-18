/*A business house has several offices in different countries; they want to lease phone lines to
connect them with each other and the phone company charges different rent to connect different
pairs of cities. Business house wants to connect all its offices with a minimum total cost. Solve
the problem using Prim’s algorithm.*/

#include <iostream>
using namespace std;

void prims(int cost[][100], int n, int start_v)
{
    // Array to store the nearest vertex
    int near[n];
    int t[n][2];
    int total = 0; 

    near[start_v] = -1;

    for (int i = 0; i < n; i++) 
    {
        if (i != start_v) 
        {
            near[i] = start_v;
        }
    }

    int r = 0; 
    while (r < n - 1) 
    {
        int min = 999; // Minimum cost of the edge
        int u, v; 

        for (int i = 0; i < n; i++) 
        {
            if (near[i] != -1 && cost[i][near[i]] < min) 
            {
                v = near[i];
                u = i;
                min = cost[i][near[i]];
            }
        }

        t[r][0] = u;
        t[r][1] = v;
        r++;

        near[u] = -1;
        total = total + min;

        for (int i = 0; i < n; i++) 
        {
            if (near[i] != -1 && cost[i][u] < cost[i][near[i]]) 
            {
                near[i] = u;
            }
        }
    }

    cout << "Minimum Spanning Tree Edges:\n";
    for (int i = 0; i < n - 1; i++) 
    {
        cout << "(" << t[i][0] << ", " << t[i][1] << ") " << endl;
    }
    cout << "Minimum Cost of Spanning Tree: " << total << endl;
}

int main() 
{
    int n; 
    cout << "Enter the number of vertices: ";
    cin >> n;

    int cost[100][100]; 
    cout << "Enter the cost matrix (Enter 999 to represent no edge):\n";
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            cout << "Enter cost of ( " << i << " , " << j << " ) : ";
            cin >> cost[i][j];
        }
    }

    int start_vertex; 
    cout << "Enter the starting vertex: ";
    cin >> start_vertex;
    prims(cost, n, start_vertex);

    return 0;
}