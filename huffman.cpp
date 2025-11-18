/*Implement an example of a Greedy Approach such as the Knapsack Problem, Huffman Code or Job sequencing with 
deadlines.*/

#include <iostream>
#include <queue>
#include <cstdlib>
#include <cctype>

using namespace std;

struct Symbol
{
    char sym;
    int freq;
    int code[10];
};

struct Huff_Tree
{
    char sym;
    int freq;
    Huff_Tree *lptr, *rptr;
};

Symbol ARR[20];

// Priority queue to store the nodes of the Huffman tree, ordered by frequency
priority_queue<pair<int, Huff_Tree *>, vector<pair<int, Huff_Tree *>>, greater<>> PQ;

Huff_Tree *gethtnode()
{
    Huff_Tree *temp = new Huff_Tree;
    temp->sym = '\0';
    temp->freq = -1;
    temp->lptr = temp->rptr = nullptr;
    return temp;
}

int accept()
{
    int n;
    cout << "\n\nEnter the number of Symbols: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "\nSymbol: ";
        cin >> ARR[i].sym;
        cout << "Frequency: ";
        cin >> ARR[i].freq;

        for (int j = 0; j < 10; j++)
        {
            ARR[i].code[j] = -1;
        }
    }
    return n;
}

void insertpq(Huff_Tree *t)
{
    PQ.push({t->freq, t});
}

Huff_Tree *delmin()
{
    if (PQ.empty()) return nullptr;
    Huff_Tree *temp = PQ.top().second;
    PQ.pop();
    return temp;
}

void insertsyms(int n)
{
    for (int i = 0; i < n; i++)
    {
        Huff_Tree *nht = gethtnode();
        nht->sym = ARR[i].sym;
        nht->freq = ARR[i].freq;
        insertpq(nht);
    }
}

Huff_Tree *create()
{
    while (PQ.size() > 1)
    {
        Huff_Tree *n1 = delmin();
        Huff_Tree *n2 = delmin();

        Huff_Tree *n3 = gethtnode();
        n3->freq = n1->freq + n2->freq;
        n3->lptr = n1;
        n3->rptr = n2;

        insertpq(n3);
    }
    return delmin();
}

bool search(Huff_Tree *t, char x)
{
    if (t == nullptr)
        return false;
    if (t->sym == x)
        return true;
    return search(t->lptr, x) || search(t->rptr, x);
}

void coding(Huff_Tree *hth, int n)
{
    for (int i = 0; i < n; i++)
    {
        Huff_Tree *temp = hth;
        int j = 0;

        while (temp->lptr != nullptr && temp->rptr != nullptr)
        {
            if (search(temp->lptr, ARR[i].sym))
            {
                ARR[i].code[j++] = 0;
                temp = temp->lptr;
            }
            else
            {
                ARR[i].code[j++] = 1;
                temp = temp->rptr;
            }
        }
    }
}

void display(int n)
{
    cout << "\n\nSYMBOL\tFREQUENCY\tCODE\n";
    for (int i = 0; i < n; i++)
    {
        cout << "\n  " << ARR[i].sym << "   \t   " << ARR[i].freq << "   \t";
        if (ARR[i].code[0] == -1)
            cout << "0/1";
        else
        {
            for (int j = 0; ARR[i].code[j] != -1; j++)
                cout << ARR[i].code[j];
        }
    }
}

void freeTree(Huff_Tree *root)
{
    if (root == nullptr)
        return;
    freeTree(root->lptr);
    freeTree(root->rptr);
    delete root;
}

int main()
{
    int no_syms;
    char con;

    do
    {
        cout << "\n\tGenerate HUFFMAN CODES\n";

        no_syms = accept();

        while (!PQ.empty())
            PQ.pop();

        insertsyms(no_syms);
        Huff_Tree *hthead = create();

        coding(hthead, no_syms);
        display(no_syms);

        freeTree(hthead);

        cout << "\n\nDo you want to continue (y/n): ";
        cin >> con;
    } while (tolower(con) == 'y');

    return 0;
}