#include "sort.h"

void quick_sort(int *array, size_t size)
{
    split(array, 0, size, size);
}

void split(int *array, int start, int end, int size)
{
    int i = start, pivot = end - 1;

    if (start == end)
    return;

    for (; i < end; i++)
    {
        if (array[i] > array[pivot] && pivot > i)
        {
            swap(&array[i], &array[pivot]);
            print_array(array, size);
        }
        else if (array[i] < array[pivot] && pivot < i)
        {
            swap(&array[i], &array[pivot]);
            print_array(array, size);
        }
    }
    split(array, start, pivot, size);
    split(array, pivot + 1, end, size);
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}