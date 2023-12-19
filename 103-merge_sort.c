#include "sort.h"

/**
 * merge_sort - sorting algorithm by using recursively spliting the array
 * and merging the array in the way up
 *
 * @array: array to be sorted
 * @size:  the size of the array
 *
 * Return: nothing
*/

void merge_sort(int *array, size_t size)
{
	int i = 0, *array2 = malloc(sizeof(int) * size);

	if (!array2 || size <= 1)
	return;

	merge_split(array, 0, size - 1, array2);

	for (i = 0; i < (int)size; i++)
	{
		array[i] = array2[i];
	}
	free(array2);
}

/**
 * merge_split- split the list in half recursively
 *
 * @array: the array to be splitted
 * @start: the start of the array
 * @end: end of the array
 * @array2: temporary array
 *
 * Return: nothing
*/

void merge_split(int *array, int start, int end, int *array2)
{
	int mid, i;

	if (start >= end)
	return;

	if ((start + end) % 2 == 0)
	mid = (start + end - 1) / 2;
	else
	mid = (start + end) / 2;

	merge_split(array, start, mid, array2);
	merge_split(array, mid + 1, end, array2);
	merge(array, start, end, array2);

	for (i = start; i <= end; i++)
	{
		array[i] = array2[i];
	}

}

/**
 * merge - merge the splitted array
 *
 * @start: the start of the array
 * @end: the end of the array
 * @array1: the array that will be sorted
 * @array2: temporary array
 *
 * Return: nothing
*/

void merge(int *array1, int start, int end, int *array2)
{
	int i, j, mid, k;

	mid = (start + end) / 2;
	printf("Merging...\n[left]: ");
	for (i = start; i <= mid; i++)
	{
		if (i != start)
		printf(", ");
		printf("%d", array1[i]);
	}
	printf("\n[right]: ");
	for (i = mid + 1; i <= end; i++)
	{
		if (i != mid + 1)
		printf(", ");
		printf("%d", array1[i]);
	}
	for (i = start, j = mid + 1, k = start; i <= mid && j <= end; k++)
	{
		if (array1[i] < array1[j])
			array2[k] = array1[i++];
		else if (array1[i] > array2[j])
			array2[k] = array1[j++];
	}
	while (j <= end)
		array2[k++] = array1[j++];
	while (i <= mid)
		array2[k++] = array1[i++];

	printf("\n[Done]: ");
	for (i = start; i <= end; i++)
	{
		if (i != start)
		printf(", ");
		printf("%d", array2[i]);
	}
	printf("\n");
}
