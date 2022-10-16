// C++ program for counting inversion using Divide and Conquer
#include "main.h"

long long count_mid_inv(int array[], const int begin, const int mid, const int end)
{
	long long count = 0;
	const int arrSize_1 = mid - begin + 1;
	const int arrSize_2 = end - mid;

	auto* arr_1 = new int[arrSize_1];
	auto* arr_2 = new int[arrSize_2];

	auto ind_1 = 0,
		ind_2 = 0,
		main = begin;

	for (auto i = 0; i < arrSize_1; ++i)
		arr_1[i] = array[begin + i];
	for (auto i = 0; i < arrSize_2; i++)
		arr_2[i] = array[mid + i + 1];

	while (ind_1 < arrSize_1 && ind_2 < arrSize_2)
	{
		if (arr_1[ind_1] < arr_2[ind_2])
		{
			array[main] = arr_1[ind_1];
			++ind_1;
		}
		else
		{
			array[main] = arr_2[ind_2];
			count = count + (arrSize_1 - ind_1);
			++ind_2;
		}
		++main;
	}

	while (ind_1 < arrSize_1)
	{
		array[main] = arr_1[ind_1];
		++ind_1;
		++main;
	}

	while (ind_2 < arrSize_2)
	{
		array[main] = arr_2[ind_2];
		++ind_2;
		++main;
	}

	delete[] arr_1;
	delete[] arr_2;

	if (count < 0)
	{
		cout << count;
	}

	return count;
}


long long count_inv(int array[], const int begin, const int end)
{
	if (begin >= end)
	{
		return 0;
	}
	else
	{
		int const mid = begin + (end - begin) / 2;
		long long first_inv = count_inv(array, begin, mid);
		long long second_inv = count_inv(array, mid + 1, end);
		long long mid_inv = count_mid_inv(array, begin, mid, end);
		
		return first_inv + mid_inv + second_inv;
	}
}







