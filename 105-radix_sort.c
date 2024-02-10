#include "sort.h"
void count(int *array, int place, int size);

void radix_sort(int *array, size_t size)
{
	int i, largest = 0, place = 1;

	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > largest)
		largest = array[i];
	}

	while (largest != 0)
	{
		count(array, place, (int)size);
		print_array(array, size);
		place *= 10;
		largest /= 10;
	}
}

void count(int *array, int place, int size)
{
	int *count, index;
	int i, *array2;

	/*allocating memory for counting array and copy array*/
	count = calloc(10, sizeof(int));
	if (count == NULL)
		return;

	array2 = malloc(sizeof(int) * size);
	if (array2 == NULL)
	{
		free(count);
		return;
	}

	/*counting num of occurence in the array*/
	for (i = 0; i < size; i++)
	{
		index = array[i] / place;
		count[index % 10]++;
	}

	/*prefix sum of the counting array*/
	for (i = 1; i < size; i++)
		count[i] = count[i] + count[i - 1];

	/*filling the copied array with the place of digit order*/
	for (i = size - 1; i >= 0; i--)
	{
		index = array[i] / place;
		count[index % 10]--;
		array2[count[index % 10]] = array[i];
	}

	/*copying the copied array back to the orignal array*/
	for (i = 0; i < size; i++)
		array[i] = array2[i];

	free(array2);
	free(count);
}
