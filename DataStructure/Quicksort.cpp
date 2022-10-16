
#include "main.h"


int QuickSort::getPivot(int arr[], const int start, const int end)
{
	if (pivot == first)
		return start;
	else if (pivot == last)
		return end;
	else if (pivot == median)
	{
		int size = end - start + 1;
		int first = arr[start];
		int last = arr[end];

		vector<pair<int, int>> median;
		median.push_back(make_pair(arr[start], start));
		median.push_back(make_pair(arr[end], end));

		if (size % 2 == 0)
		{
			int middle = start + (size / 2) - 1;
			median.push_back(make_pair(arr[middle], middle));
		}
		else
		{
			int middle = start + (size / 2);
			median.push_back(make_pair(arr[middle], middle));
		}

		std::sort(median.begin(), median.end());
		return median[1].second;

	}
}


int QuickSort::partition(int arr[], const int start, const int end, const int pivot)
{
	compar_count = compar_count + (end - start);

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


void QuickSort::sort(int arr[], const int start, const int end)
{
	if (end - start <= 0)
		return;

	int pivot = getPivot(arr, start, end);
	int mid = partition(arr, start, end, pivot);
	
	if (start != mid)
		sort(arr, start, mid - 1);

	if (end != mid)
		sort(arr, mid + 1, end);
}
