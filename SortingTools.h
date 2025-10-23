#ifndef SORTINGTOOLS_H
#define SORTINGTOOLS_H

#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
using namespace std;
class SortingTools
{
private:
    int n;
    vector<int> arr;
public:
    SortingTools(int n);
    ~SortingTools();


    void MySwap(int a, int b);


    //Bubble Sort
    void BubbleSort();

    //Quick Sort
    int FindThePivot(int low, int high);
    int Partition(int low, int high);
    void QuickSort(int low, int high);

    //Helpers
    void printVector() const;
    void saveToFile(const string& fileName) const;   
};

#endif
