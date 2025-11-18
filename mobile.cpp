/*
1.	Write a program for Iterative and Recursive Binary Search and verify the time complexity. 
2.	Write a program to perform quick/merge sort using Divide and Conquer strategy and verify the time complexity.
    a.	Accept Mobile user information (e.g. MobileNo, Name, BillAmount etc.).
    b.	Display the data in descending order of MobileNo. (Recursive Quick Sort)
    c.	Display the data in ascending order of BillAmount (Heap Sort)
    d.	Display details for Mobileno specified by user (Linear Search and Recursive and Non-recursive Binary Search)
    e.	Display the number of passes and comparisons for different test cases (Worst, Average, Best case).
*/

#include <iostream>
#include <string>
using namespace std;

class Mobile 
{
private:
    string name;
    long long num;
    double bill;

public:
    friend void get(Mobile records[], int n);
    void display()
    {
        cout << "Name = " << name << endl;
        cout << "Number = " << num << endl;
        cout << "Bill Amount = " << bill << endl;
    }
    friend void linear(Mobile records[], int size, long long sno);
    friend void binary(Mobile records[], int low, int high, long long sno);
    friend void quickSort(Mobile records[], int low, int high);
    friend int partition(Mobile records[], int low, int high);
    friend void heapify(Mobile records[], int n, int i);
    friend void heapSort(Mobile records[], int n);
};

void get(Mobile records[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Name: ";
        cin >> records[i].name;
        cout << "Enter Number: ";
        cin >> records[i].num;
        cout << "Enter Bill Amount: ";
        cin >> records[i].bill;
    }
}

void linear(Mobile records[], int size, long long sno)
{
    for (int i = 0; i < size; i++)
    {
        if (records[i].num == sno)
        {
            cout << "\nMobile Found!" << endl;
            records[i].display();
            return;
        }
    }
    cout << "Phone not Found!" << endl;
}

void binary(Mobile records[], int low, int high, long long sno)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (records[mid].num == sno)
        {
            cout << "\nMobile Found!" << endl;
            records[mid].display();
            return;
        }
        if (records[mid].num < sno)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << "Phone not Found!" << endl;
}

int partition(Mobile records[], int low, int high)
{
    long long pivot = records[high].num;
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (records[j].num >= pivot) // Descending order
        {
            i++;
            swap(records[i], records[j]);
        }
    }

    swap(records[i + 1], records[high]);
    return i + 1;
}

void quickSort(Mobile records[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(records, low, high);
        quickSort(records, low, pi - 1);
        quickSort(records, pi + 1, high);
    }
}

void heapify(Mobile records[], int n, int i)
{
    int largest = i; 
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && records[left].bill > records[largest].bill)
        largest = left;

    if (right < n && records[right].bill > records[largest].bill)
        largest = right;

    if (largest != i)
    {
        swap(records[i], records[largest]);
        heapify(records, n, largest);
    }
}

void heapSort(Mobile records[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--) heapify(records, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(records[0], records[i]);
        heapify(records, i, 0);
    }
}

int main()
{
    int n, ch;
    cout << "Enter Number of Records: ";
    cin >> n;

    Mobile records[n];
    get(records, n);

    long long sno;
    cout << "\nEnter Number to Search: ";
    cin >> sno;
    cout << "1. Linear Search\n2. Binary Search\nHow do you want to search? : ";
    cin >> ch;

    switch (ch)
    {
    case 1:
        linear(records, n, sno);
        break;
    case 2:
        quickSort(records, 0, n - 1); 
        binary(records, 0, n - 1, sno);
        break;
    default:
        cout << "Invalid Choice!" << endl;
        break;
    }

    cout << "\nRecords Sorted by Mobile Number (Descending - Quick Sort):\n";
    quickSort(records, 0, n - 1);
    for (int i = 0; i < n; i++)
        records[i].display();

    cout << "\nRecords Sorted by Bill Amount (Ascending - Heap Sort):\n";
    heapSort(records, n);
    for (int i = 0; i < n; i++)
        records[i].display();

    return 0;
}
