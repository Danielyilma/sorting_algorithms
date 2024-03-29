#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void swap_node(listint_t *left, listint_t *right);
void selection_sort(int *array, size_t size);
size_t smallest_num(int *array, size_t start, size_t end);
void quick_sort(int *array, size_t size);
void split(int *array, int start, int end, int pivot);
void swap(int *a, int *b);
void shell_sort(int *array, size_t size);
int size_of_list(listint_t *head);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void merge(int *array1, int start, int end, int *array2);
void merge_split(int *array, int start, int end, int *array2);
void heap_sort(int *array, size_t size);
void heapify(int *array, int size);
void sift_down(int *array, int start, int end , int size);
void radix_sort(int *array, size_t size);
#endif
