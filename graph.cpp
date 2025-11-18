/*
Consider a friend's network on Facebook social web site. Model it as a graph to represent each 
nodes as user and a link to represent a friendship relationshipbetween them using adjacency list
representation and perform DFS and BFS traversals
    1.Create a Graph using Adjacency List (Friend Name, ID)
    2.Display the graph
    3.Perform the recurssive and non-recurssive traversal using Depth First Search(Using ID)
    4.Perform the recurssive and non-recurssive traversal using Breadth First Search(Using ID)
*/

#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;

class node 
{
    public:
    string name;
    int id;
    node* next;
    friend class graph;
};

class graph 
{
    private:
    node* head[20];
    bool visited[20];  
    int n;

    public:
    void create() 
    {
        char ch;
        cout << "Enter number of vertices: ";
        cin >> n;

        for (int i = 0; i < n; i++) 
        {
            head[i] = new node;
            cout << "Enter Facebook User " << i << ": ";
            cin >> head[i]->name;
            head[i]->id = i;
            head[i]->next = nullptr;
        }
        for (int i = 0; i < n; i++) 
        {
            node* temp = head[i];
            while (true) 
            {
                cout << "\nIs there any FB Friend connected with " << head[i]->name << " (Y/N)? ";
                cin >> ch;

                if (ch == 'Y' || ch == 'y') 
                {
                    node* current = new node;
                    cout << "Enter the connected Friend id: ";
                    cin >> current->id;

                    if (current->id < 0 || current->id >= n) 
                    {
                        cout << "Invalid vertex id. Please enter a valid id.\n";
                        continue;
                    }
                    current->name = head[current->id]->name;
                    current->next = nullptr;
                    temp->next = current;
                    temp = current;
                } 
                else if (ch == 'N' || ch == 'n') 
                {
                    break;
                } 
                else 
                {
                    cout << "Invalid input. Please enter Y or N.\n";
                }
            }
        }
    }

    void display() 
    {
        cout << "\nGraph Adjacency List:\n";
        for (int i = 0; i < n; i++) 
        {
            cout << "Vertex " << head[i]->id << " (" << head[i]->name << "): ";
            node* temp = head[i]->next;
            while (temp != nullptr) 
            {
                cout << temp->name << " (" << temp->id << ") ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    void DFS() 
    {
        cout << "\nDepth First Search (Recursive):\n";
        for (int i = 0; i < n; i++) 
        {
            visited[i] = false;  
        }
        for (int i = 0; i < n; i++) 
        {
            if (!visited[i]) 
            {
                DFS_I(i);
            }
        }
        cout << endl;
    }

    void DFS_I(int v) 
    {
        visited[v] = true;
        cout << head[v]->name << " (" << head[v]->id << ") ";

        node* temp = head[v]->next;
        while (temp != nullptr) 
        {
            if (!visited[temp->id]) 
            {
                DFS_I(temp->id);
            }
            temp = temp->next;
        }
    }

    void DFS_NR() 
    {
        cout << "\nDepth First Search (Non-Recursive):\n";
        for (int i = 0; i < n; i++) 
        {
            visited[i] = false;  
        }

        stack<int> s;
        for (int i = 0; i < n; i++) 
        {
            if (!visited[i]) 
            {
                s.push(i);
                while (!s.empty()) 
                {
                    int v = s.top();
                    s.pop();
                    if (!visited[v]) 
                    {
                        visited[v] = true;
                        cout << head[v]->name << " (" << head[v]->id << ") ";
                    }
                    node* temp = head[v]->next;
                    while (temp != nullptr) 
                    {
                        if (!visited[temp->id]) 
                        {
                            s.push(temp->id);
                        }
                        temp = temp->next;
                    }
                }
            }
        }
        cout << endl;
    }

    void BFS() 
    {
        cout << "\nBreadth First Search (Non-Recursive):\n";
        for (int i = 0; i < n; i++) 
        {
            visited[i] = false;  
        }

        queue<int> q;
        for (int i = 0; i < n; i++) 
        {
            if (!visited[i]) 
            {
                visited[i] = true;
                q.push(i);

                while (!q.empty()) 
                {
                    int v = q.front();
                    q.pop();
                    cout << head[v]->name << " (" << head[v]->id << ") ";

                    node* temp = head[v]->next;
                    while (temp != nullptr) 
                    {
                        if (!visited[temp->id]) 
                        {
                            visited[temp->id] = true;
                            q.push(temp->id);
                        }
                        temp = temp->next;
                    }
                }
            }
        }
        cout << endl;
    }
};

int main() 
{
    graph g;
    g.create();
    g.display();
    g.DFS();
    g.DFS_NR();
    g.BFS();
    return 0;
}