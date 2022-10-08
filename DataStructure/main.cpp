#include "main.h"
#include "utils.h"

// example for each problem --

// MergeSort
void sortMain()
{
    int array[] = { 9, 3, 5, 8 };
    auto size = sizeof(array) / sizeof(array[0]);

    cout << "Array: \n";
    printArray(array, size);

    mergeSort(array, 0, size - 1);

    cout << "\nSorted Array: \n";
    printArray(array, size);
}

// Iversion using MergeSort
void iversionMain()
{
    int array[] = { 9, 3, 5, 8, 1 };
    auto size = sizeof(array) / sizeof(array[0]);

    cout << "Array: \n";
    printArray(array, size);

    int count = count_inv(array, 0, size - 1);

    cout << "\nSorted Array: \n";
    printArray(array, size);

    cout << "\nInversions: " << count;
}

// Clises
void closePairMain()
{
    vector<point2D> P{{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    // sort according to X
    sort(P.begin(), P.end(), [](const point2D& a, const point2D& b) {return a.x < b.x; });
    // Takes sort points sorted accroding to X
    float min_ = closesetPair(P, 0, P.size() - 1);
    cout << min_;
}


int main()
{
    vector<int> Vec{ 1, 2, 3, 4 };
    closePairMain();

    return 0;
}
