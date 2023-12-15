#include "sort.h"

/**
 * quick_sort - implementation of quick sort with recursion
 *
 * @array: array to be sorted
 * @size: the size of the array
 *
 * Return: nothing
*/

void quick_sort(int *array, size_t size)
{
	split(array, 0, size, size);
}

/**
 * split - sorts by splitting left and right
 * with respect to pivot
 *
 * @array: the array to be sorted
 * @start: the start of left or the right with respect to pivot
 * @end: end of the splitted array
 * @size: size of the array
 *
 * Return: nothing
*/

void split(int *array, int start, int end, int size)
{
	int i = start, pivot = end - 1;
	int temp_piv = start;

	if (start >= pivot)
	return;

	for (; i < end - 1; i++)
	{
		if (array[i] <= array[pivot] && temp_piv != i)
		{
			swap(&array[i], &array[temp_piv]);
			temp_piv++;
			print_array(array, size);
		}
		else if (array[i] <= array[pivot] && temp_piv == i)
		temp_piv++;
	}

	if (temp_piv != pivot)
	{
		swap(&array[temp_piv], &array[pivot]);
		print_array(array, size);
		pivot = temp_piv;
	}

	split(array, start, pivot, size);
	split(array, pivot + 1, end, size);
}

/**
 * swap - swaps two elements content
 *
 * @a: the first element
 * @b: the second element
 *
 * Return: nothing
*/

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
