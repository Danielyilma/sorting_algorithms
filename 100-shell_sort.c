#include "sort.h"

/**
 * shell_sort - sorts by a gap and uses
 * the principle of insertion sort
 *
 * @array: - the array to be sorted
 * @size: - size of the array
 *
 * Return: nothing
*/
void shell_sort(int *array, size_t size)
{
	size_t j = 0, gap = 0, temp_gap = 0;
	int i = 0;

	if (!array || size < 2)
	return;

	while (temp_gap <= size)
	{
		gap = temp_gap;
		temp_gap = gap * 3 + 1;
	}

	for (; gap >= 1; gap = (gap - 1) / 3)
	{
		for (j = gap; j < size; j++)
		{
			for (i = j - gap; i >= 0 && array[i] > array[i + gap]; i -= gap)
			{
				swap(&array[i + gap], &array[i]);
			}
		}
		print_array(array, size);
	}
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
