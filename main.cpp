#include "SortingTools.h"

int main()
{
    int n;
    cout << "\n Please specify the size of the array: ";
    cin >> n;
    cout << "\n";
    SortingTools sorter1(n);
    
    cout << "Bubble Sort: \n";
    sorter1.BubbleSort();
    sorter1.printVector();

    SortingTools sorter2(n);

    cout << "Quick Sort: \n";
    sorter2.QuickSort(0, n - 1);
    sorter2.printVector();

}