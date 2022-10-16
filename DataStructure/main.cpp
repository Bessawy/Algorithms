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
    std::ifstream textfile;
    int val = 0;
    vector<int> integars;
    textfile.open("IntArray.txt");

    cout << "The file is open! : " << textfile.is_open() << endl;
    for (std::string line; getline(textfile, line); )
    {
        val = stoi(line);
        integars.push_back(val);
    }

    int* array = &integars[0];
    auto size = integars.size();

    // Commented since array is too large
    // cout << "Array: \n";
    // printArray(array, size);
    // cout << endl;
    long long int count = count_inv(array, 0, size - 1);

    // cout << "\nSorted Array: \n";
    // printArray(array, size);

    cout << "\nInversions: " << count;

}

// Closest 2D pairs
void closePairMain()
{
    vector<point2D> P{{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    // sort according to X
    sort(P.begin(), P.end(), [](const point2D& a, const point2D& b) {return a.x < b.x; });
    // Takes sort points sorted accroding to X
    float min_ = closesetPair(P, 0, P.size() - 1);
    cout << min_;
}

// Karatsuba Multiplication
void Multiply(vector<int> x, vector<int> y, int n)
{
    string X = "3141592653589793238462643383279502884197169399375105820974944592";
    string Y = "2718281828459045235360287471352662497757247093699959574966967627";
    int size = X.length();

    vector<int> X_int;
    vector<int> Y_int;

    for (int i = 0; i < size; ++i)
    {
        X_int.push_back(int(X[i] - '0'));
        Y_int.push_back(int(Y[i] - '0'));
    }

    vector<int> sum = kara_Multi(X_int, Y_int);

    for (int i = 0; i < sum.size(); ++i)
    {
        cout << sum[i];
    }

}

// Quicksort
void Quicksort_()
{
    std::ifstream textfile;
    int val = 0;
    vector<int> integars;
    textfile.open("Quicksort.txt");

    cout << "The file is open! : " << textfile.is_open() << endl;
    for (std::string line; getline(textfile, line); )
    {
        val = stoi(line);
        integars.push_back(val);
    }

    int* arr = &integars[0];
    auto size = integars.size();

    //int arr[] = { 2, 4, 3, 8, 7};
    //int size = sizeof(arr) / sizeof(arr[0]);

    QuickSort sort_arr;
    sort_arr.compar_count = 0;
    sort_arr.sort(arr, 0, size - 1);

    printArray(arr, size);

    cout << endl << "Comparison count: " << sort_arr.compar_count;
}

int main()
{


    return 0;
}
