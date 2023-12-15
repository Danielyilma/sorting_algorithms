#include "sort.h"

/**
 * bubble_sort - sorting an array by swaping adjacent elements
 *
 * @array: the array to be sorted
 * @size: the size of the array
 *
 * Return: nothing
*/

void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, temp;

	for (i = 0; i < size; i++)
	{
		for (j = 1; j < size - i; j++)
		{
			if (array[j - 1] > array[j])
			{
				temp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = temp;
				print_array(array, size);
			}
		}
	}
}
