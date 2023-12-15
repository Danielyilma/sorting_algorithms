#include "sort.h"

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