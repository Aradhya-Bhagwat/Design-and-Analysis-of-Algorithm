/*Write a program to implement AVL tree for Dictionary. A Dictionary stores keywords & its meaning. Provide facility
for adding new keywords, updating meaning of any entry. Provide a facility to display whole data sorted in ascending
order. Also find how many maximum comparisons may require for finding any keyword. Use a Height balanced tree and 
find the complexity for finding a keyword.*/

#include <iostream>
#include <string>
using namespace std;

class AVL
{
    string word;
    string meaning;
    AVL *left, *right;

    public:
    friend class Tree;
};

class Tree
{
    public:
    AVL *root;

    Tree()
    {
        root = nullptr;
    }

    AVL *LL(AVL *parent);
    AVL *RR(AVL *parent);
    AVL *LR(AVL *parent);
    AVL *RL(AVL *parent);
    int diff(AVL *temp);
    int height(AVL *temp);
    AVL *balance(AVL *temp);
    void insert();
    AVL *insert(AVL *root, AVL *temp);
    void inorder(AVL *root);
    void searchAndUpdate();
    void searchWord();
};

AVL *Tree::LL(AVL *parent)
{
    AVL *temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}

AVL *Tree::RR(AVL *parent)
{
    AVL *temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}

AVL *Tree::LR(AVL *parent)
{
    AVL *temp = parent->left;
    parent->left = RR(temp);
    return LL(parent);
}

AVL *Tree::RL(AVL *parent)
{
    AVL *temp = parent->right;
    parent->right = LL(temp);
    return RR(parent);
}

int Tree::height(AVL *temp)
{
    if (temp == nullptr) return 0;
    int l = height(temp->left);
    int r = height(temp->right);
    return max(l, r) + 1;
}

int Tree::diff(AVL *temp)
{
    return height(temp->left) - height(temp->right);
}

AVL *Tree::balance(AVL *temp)
{
    int balanceFactor = diff(temp);

    if (balanceFactor > 1)
    {
        if (diff(temp->left) > 0)
            temp = LL(temp);
        else
            temp = LR(temp);
    }
    else if (balanceFactor < -1)
    {
        if (diff(temp->right) > 0)
            temp = RL(temp);
        else
            temp = RR(temp);
    }
    return temp;
}

void Tree::insert()
{
    char ch = 'y';
    do
    {
        AVL *temp = new AVL;
        cout << "Enter Word: ";
        cin >> temp->word;
        cout << "Enter Meaning: ";
        cin >> temp->meaning;
        temp->left = temp->right = nullptr;
        root = insert(root, temp);
        cout << "Do you want to insert another word (y/n)? ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
}

AVL *Tree::insert(AVL *root, AVL *temp)
{
    if (root == nullptr)
    {
        root = new AVL;
        root->word = temp->word;
        root->meaning = temp->meaning;
        root->left = root->right = nullptr;
    }
    else if (temp->word < root->word)
    {
        root->left = insert(root->left, temp);
        root = balance(root);
    }
    else if (temp->word > root->word)
    {
        root->right = insert(root->right, temp);
        root = balance(root);
    }
    else
    {
        cout << "Word already exists. Duplicate entries are not allowed.\n";
    }
    return root;
}

void Tree::inorder(AVL *root)
{
    if (root != nullptr)
    {
        inorder(root->left);
        cout << "Word: " << root->word << " - Meaning: " << root->meaning << endl;
        inorder(root->right);
    }
}

void Tree::searchAndUpdate()
{
    string key;
    cout << "Enter word to update meaning: ";
    cin >> key;
    int comparisons = 0;
    AVL *current = root;

    while (current != nullptr)
    {
        comparisons++;
        if (key == current->word)
        {
            cout << "Current Meaning: " << current->meaning << endl;
            cout << "Enter New Meaning: ";
            cin >> current->meaning;
            cout << "Meaning updated successfully after " << comparisons << " comparisons.\n";
            return;
        }
        else if (key < current->word)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }
    cout << "Word not found in dictionary after " << comparisons << " comparisons.\n";
}

void Tree::searchWord()
{
    string key;
    cout << "Enter word to search: ";
    cin >> key;
    int comparisons = 0;
    AVL *current = root;

    while (current != nullptr)
    {
        comparisons++;
        if (key == current->word)
        {
            cout << "Word found!\n";
            cout << "Word: " << current->word << " - Meaning: " << current->meaning << endl;
            cout << "Comparisons made: " << comparisons << endl;
            cout << "\nNote: Maximum comparisons in AVL tree is O(log n) because the height of AVL tree is always kept balanced.\n";
            return;
        }
        else if (key < current->word)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }
    cout << "Word not found after " << comparisons << " comparisons.\n";
    cout << "\nNote: Maximum comparisons in AVL tree is O(log n) because the height of AVL tree is always kept balanced.\n";
}

int main()
{
    Tree t;
    int choice;

    do
    {
        cout << "\nAVL Dictionary Menu\n";
        cout << "1. Insert Word\n";
        cout << "2. Display (Inorder Traversal)\n";
        cout << "3. Update Meaning\n";
        cout << "4. Search Word\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            t.insert();
            break;
        case 2:
            cout << "\n Dictionary Contents (Sorted) \n";
            t.inorder(t.root);
            break;
        case 3:
            t.searchAndUpdate();
            break;
        case 4:
            t.searchWord();
            break;
        case 5:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}