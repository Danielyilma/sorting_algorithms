#include "sort.h"

void heap_sort(int *array, size_t size)
{
	int i = size - 1;

	heapify(array, size);

	while (i > 0)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		i--;
		sift_down(array, 0, i, size);
	}  
}

void heapify(int *array, int size)
{
	int end = size -1, parent = (end) / 2;

	for (; parent >= 0; parent--)
	{
		sift_down(array, parent, end, size);
	}

}

void sift_down(int *array, int start, int end, int size)
{
	int parent = start, i = 2 * parent + 1;
	int greater;

	while (i <= end)
	{
		if (i + 1 > end || array[i] > array[i + 1])
		greater = i;
		else
		greater = i + 1;

		if (array[parent] < array[greater])
		{
			swap(&array[parent], &array[greater]);
			print_array(array, size);
		}
		else
		break;

		parent = greater;
		i = 2 * parent + 1;
	}
}

void swap(int *num1, int *num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}