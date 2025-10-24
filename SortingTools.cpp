#include "SortingTools.h"

SortingTools::SortingTools(int n)
{
    int a;
    this->n = n;
    srand(time(0));
    for(int i = 0; i < n; i++)
    {
        a = rand() % 100;
        arr.push_back(a);
    }
    cout << "rolled numbers: ";
    printVector();
}

SortingTools::~SortingTools()
{
    saveToFile("wynik.txt");
    arr.clear();
    cout << "Saved data to file wynik.txt and cleared vector. \n";
}

void SortingTools::MySwap(int a, int b)
{
    int temp = arr[b];
    arr[b] = arr[a];
    arr[a] = temp;
}

void SortingTools::BubbleSort()
{
    for(int i = 0; i < n - 1; i++)
    {
        for(auto ptr = arr.begin(); ptr < arr.end() - i - 1; ptr++)
        {
            if(*ptr > *(ptr + 1))
                MySwap(ptr - arr.begin(), ptr + 1 - arr.begin());
        }
    }
}

int SortingTools::FindThePivot(int low, int high)
{
    int mid = (low + high) / 2;
    int a = arr[low];
    int b = arr[mid];
    int c = arr[high];

    if((a > b) != (a > c)) return low;
    else if((b > a) != (b > c)) return mid;
    else return high; 
}

int SortingTools::Partition(int low, int high)
{
    int pivotIndex = FindThePivot(low, high);
    int pivotValue = arr[pivotIndex];

    MySwap(pivotIndex, high);

    int i = low - 1;

    for(int j = low; j < high; j++)
    {
        if(arr[j] < pivotValue)
        {
            i++;
            MySwap(i, j);
        }
    }
    MySwap(i + 1, high);
    return i + 1;
}

void SortingTools::QuickSort(int low, int high)
{
    if (low < high)
    {
        int pi = Partition(low, high);

        QuickSort(pi + 1, high);
        QuickSort(low, pi - 1);
    }
}

void SortingTools::BinaryTreeFunction()
{
    BinaryTree* root = nullptr;
    for(auto& el : arr)
        insert(root, el);

    cout << "Binary tree in-order: ";
    PrintInOrder(root);
    cout << "\n";

    deleteTree(root);
}

void SortingTools::insert(BinaryTree*& root, int a)
{
    if(!root){
        root = new BinaryTree(a);
        return;
    }

    if(a < root->value)
        insert(root->left, a);
    else
        insert(root->right, a);
}

void SortingTools::deleteTree(BinaryTree* root)
{
    if(!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

void SortingTools::PrintInOrder(BinaryTree *root) const
{
    if(!root) return;

    PrintInOrder(root->left);
    cout << root->value << " ";
    PrintInOrder(root->right);
}

void SortingTools::printVector() const
{
    for(auto& el : arr)
        cout << el << " ";
    cout << "\n" << "\n";
}

void SortingTools::saveToFile(const string &fileName) const
{
    ofstream file(fileName);
    for(auto& el : arr)
        file << el << " ";
    file << endl;

    file.close();
}
