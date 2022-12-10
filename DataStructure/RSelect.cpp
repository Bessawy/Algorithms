#include "main.h"
#include <stdlib.h> 


int getRandomizedPivot(const int start, const int end) {
	srand(time(0));
	int size = end - start + 1;
	return rand() % size + start;
}

int randomPartition(int arr[], const int start, const int end, const int pivot) {
	int pivot_value = arr[pivot];
	int i = start + 1;

	// swap pivot to start location
	arr[pivot] = arr[start];
	arr[start] = pivot_value;

	for (int j = start + 1; j <= end; ++j)
	{
		if (arr[j] < pivot_value)
		{
			int temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
			i++;
		}
	}

	arr[start] = arr[i - 1];
	arr[i - 1] = pivot_value;
	return i - 1;
}

int randomSelect(int arr[], const int start, const int end, const int ith) {
	int size = end - start + 1;

	if (size == 1)
		return arr[start];

	int pivot = getRandomizedPivot(start, end);
	int pivot_index = randomPartition(arr, start, end, pivot);

	if (pivot_index == ith) {
		return arr[pivot_index];
	}
	else if(pivot_index < ith)
	{
		randomSelect(arr, pivot_index + 1, end, ith - pivot_index);

	}
	else {
		randomSelect(arr, start, pivot_index-1, ith);
	}

}
