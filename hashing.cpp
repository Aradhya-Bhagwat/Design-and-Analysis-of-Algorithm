/* Implement Direct access file using hashing (linear probing with and without replacement) perform following 
operations on it 
a) Create Student Database[ Roll no, Name, Marks]  
b) Display Database 
c) Add a record 
d) Search a record 
e) Modify a record
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct student
{
    string name;
    int roll;
    float marks;
};

class Hashtable
{
    private:
    student table[10];

    int Hashfunction(int key)
    {
        return (key % 10);
    }

    public:
    Hashtable()
    {
        for (int i = 0; i < 10; i++)
        {
            table[i].roll = -1;
            table[i].marks = -1;
        }
    }

    // Linear Probing without Replacement
    void create(string name, int roll, float marks)
    {
        int index = Hashfunction(roll);
        int i = index;
        if (table[index].roll == -1)
        {
            table[i].name = name;
            table[i].roll = roll;
            table[i].marks = marks;
        }
        else
        {
            i = (i + 1) % 10;
            while (i != index)
            {
                if (table[i].roll == -1)
                {
                    table[i].name = name;
                    table[i].roll = roll;
                    table[i].marks = marks;
                    break;
                }
                i = (i + 1) % 10;
            }
            if (i == index)
                cout << "Hash Table Full." << endl;
        }
    }

    // Linear Probing with Replacement
    void createR(string name, int roll, float marks)
    {
        int index = Hashfunction(roll);
        if (table[index].roll == -1)
        {
            table[index].name = name;
            table[index].roll = roll;
            table[index].marks = marks;
            return;
        }

        int existingRoll = table[index].roll;
        int existingHome = Hashfunction(existingRoll);
        if (existingHome != index)
        {
            student temp = table[index];
            table[index].name = name;
            table[index].roll = roll;
            table[index].marks = marks;
            int i = (index + 1) % 10;
            while (i != index)
            {
                if (table[i].roll == -1)
                {
                    table[i] = temp;
                    return;
                }
                i = (i + 1) % 10;
            }
            cout << "Hash Table Full while re-inserting replaced record." << endl;
        }
        else
        {
            int i = (index + 1) % 10;
            while (i != index)
            {
                if (table[i].roll == -1)
                {
                    table[i].name = name;
                    table[i].roll = roll;
                    table[i].marks = marks;
                    return;
                }
                i = (i + 1) % 10;
            }
            cout << "Hash Table Full." << endl;
        }
    }

    void display()
    {
        cout << "Student Database : " << endl;
        cout << "Index\tRoll No.\tName\tMarks" << endl;
        for (int i = 0; i < 10; i++)
        {
            cout << i << "\t" << table[i].roll << "\t\t" << table[i].name << "\t" << table[i].marks << endl;
        }
    }

    void saveToBinaryFile()
    {
        ofstream fout("student_db.dat", ios::binary);
        if (!fout)
        {
            cerr << "Error: Could not open file for writing.\n";
            return;
        }

        for (int i = 0; i < 10; i++)
        {
            if (table[i].roll != -1)
            {
                int nameLen = table[i].name.length();
                fout.write((char *)&table[i].roll, sizeof(table[i].roll));
                fout.write((char *)&table[i].marks, sizeof(table[i].marks));
                fout.write((char *)&nameLen, sizeof(nameLen));
                fout.write(table[i].name.c_str(), nameLen);
            }
        }

        fout.close();
        cout << "Database saved to 'student_db.dat' successfully.\n";
    }

    void loadFromBinaryFile()
    {
        ifstream fin("student_db.dat", ios::binary);
        if (!fin)
        {
            cerr << "Error: Could not open file for reading.\n";
            return;
        }

        while (fin.peek() != EOF)
        {
            int roll;
            float marks;
            int nameLen;
            string name;

            fin.read((char *)&roll, sizeof(roll));
            fin.read((char *)&marks, sizeof(marks));
            fin.read((char *)&nameLen, sizeof(nameLen));

            char *nameBuffer = new char[nameLen + 1];
            fin.read(nameBuffer, nameLen);
            nameBuffer[nameLen] = '\0';
            name = string(nameBuffer);
            delete[] nameBuffer;

            create(name, roll, marks);
        }

        fin.close();
        cout << "Database loaded from 'student_db.dat' successfully.\n";
    }

    void searchRecord(int roll)
    {
        int index = Hashfunction(roll);
        int i = index;
        while (table[i].roll != -1)
        {
            if (table[i].roll == roll)
            {
                cout << "Record found at index " << i << ":\n";
                cout << "Name: " << table[i].name << ", Marks: " << table[i].marks << endl;
                return;
            }
            i = (i + 1) % 10;
            if (i == index)
                break;
        }
        cout << "Record not found.\n";
    }

    void modifyRecord(int roll)
    {
        int index = Hashfunction(roll);
        int i = index;
        while (table[i].roll != -1)
        {
            if (table[i].roll == roll)
            {
                cout << "Enter new name: ";
                cin >> table[i].name;
                cout << "Enter new marks: ";
                cin >> table[i].marks;
                cout << "Record updated.\n";
                return;
            }
            i = (i + 1) % 10;
            if (i == index)
                break;
        }
        cout << "Record not found.\n";
    }
};

int main()
{
    int n, ch, roll;
    string name;
    float marks;
    Hashtable ht;

    do
    {
        cout << "\n--- MENU ---\n";
        cout << "1. Create Database (Without Replacement)\n";
        cout << "2. Create Database (With Replacement)\n";
        cout << "3. Display Database\n";
        cout << "4. Add Record\n";
        cout << "5. Search Record\n";
        cout << "6. Modify Record\n";
        cout << "7. Save to Binary File\n";
        cout << "8. Load from Binary File\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter number of students (less than 10): ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                cout << "Enter Name, Roll, Marks: ";
                cin >> name >> roll >> marks;
                ht.create(name, roll, marks);
            }
            break;

        case 2:
            cout << "Enter number of students (less than 10): ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                cout << "Enter Name, Roll, Marks: ";
                cin >> name >> roll >> marks;
                ht.createR(name, roll, marks);
            }
            break;

        case 3:
            ht.display();
            break;

        case 4:
            cout << "Enter Name, Roll, Marks: ";
            cin >> name >> roll >> marks;
            ht.create(name, roll, marks);
            break;

        case 5:
            cout << "Enter Roll Number to search: ";
            cin >> roll;
            ht.searchRecord(roll);
            break;

        case 6:
            cout << "Enter Roll Number to modify: ";
            cin >> roll;
            ht.modifyRecord(roll);
            break;

        case 7:
            ht.saveToBinaryFile();
            break;

        case 8:
            ht.loadFromBinaryFile();
            break;

        case 0:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (ch != 0);

    return 0;
}