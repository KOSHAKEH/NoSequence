#include <iostream>
#include <algorithm>
#include <vector>
#include "NoSequence.h"
using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");

    const int size = 10;
    int arr1[size] = { 1, 1, 1, 4, 5, 5, 7, 8, 9, 9 };
    vector<int> arr2(size);

    int* const arr1Begin = arr1;
    int* const arr1End = arr1 + size;
    int* const arr2Begin = arr2.data();
    int* const arr2End = arr2.data() + size;

    cout << "Оригинальный arr1:\n";
    print(arr1Begin, arr1End);
    cout << "\n";

    cout << "arr2 - копия arr1 без упорядочивания дубликатов (ignoreCount = 2):\n";
    int count2 = copy_if(arr1Begin, arr1End, arr2Begin, arr2End, NoSequence(2));
    print(arr2Begin, arr2Begin + count2);
    cout << "\n";

    cout << "arr2 - копия arr1 без упорядочивания дубликатов (ignoreCount = 1):\n";
    int count1 = copy_if(arr1Begin, arr1End, arr2Begin, arr2End, NoSequence(1));
    print(arr2Begin, arr2Begin + count1);

    return 0;
}

