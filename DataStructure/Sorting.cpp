

// Merge sub array
void merge(int array[], int const begin, int const mid, int const end)
{
    auto const arraySize_1 = mid - begin + 1;
    auto const arraySize_2 = end - mid;
    
    auto ind_1 = 0,
        ind_2 = 0,
        main = begin;

    auto* arr_1 = new int[arraySize_1];
    auto* arr_2 = new int[arraySize_2];

    for (auto i = 0; i < arraySize_1; ++i)
    {
        arr_1[i] = array[begin + i];
    }
    for (auto i = 0; i < arraySize_2; ++i)
    {
        arr_2[i] = array[mid + i + 1];
    }

    while (ind_1 < arraySize_1 && ind_2 < arraySize_2)
    {
        if (arr_1[ind_1] < arr_2[ind_2])
        {
            array[main] = arr_1[ind_1];
            ++ind_1;
        }
        else
        {
            array[main] = arr_2[ind_2];
            ++ind_2;
        }      
        ++main;
    }

    while (ind_1 < arraySize_1)
    {
        array[main] = arr_1[ind_1];
        ++ind_1;
        ++main;
    }

    while (ind_2 < arraySize_2)
    {
        array[main] = arr_2[ind_2];
        ++ind_2;
        ++main;
    }

    delete[] arr_1;
    delete[] arr_2;
}

// Recursive sorting function 
void mergeSort(int array[], const int begin, const int end)
{
    if (begin >= end)
        return;

    int const mid = begin + (end - begin)/2;

    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

