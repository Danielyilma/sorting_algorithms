#include "sort.h"

/**
 * selection_sort - sorts an array by selecting
 * the smallest from the unsorted side and adds it to sorted side
 *
 * @array: the array
 * @size: the size of the array
 *
 * Return: nothing
*/

void selection_sort(int *array, size_t size)
{
	size_t i = 0, sidx, temp;

	for (i = 0; i < size; i++)
	{
		sidx = smallest_num(array, i, size);

		if (sidx != i)
		{
			temp = array[i];
			array[i] = array[sidx];
			array[sidx] = temp;
			print_array(array, size);
		}
	}
}

/**
 * smallest_num - find the smallest number from the unsorted array
 *
 * @array: the array to be sorted
 * @start: the start of the unsorted array
 * @end: the end of the unsorted array
 *
 * Return: smallest number index
 *
*/

size_t smallest_num(int *array, size_t start, size_t end)
{
	size_t sidx = start;

	for (; start < end; start++)
	{
		if (array[start] < array[sidx])
		sidx = start;
	}
	return (sidx);
}
