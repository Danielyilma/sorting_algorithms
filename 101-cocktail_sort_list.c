#include "sort.h"

/**
 * cocktail_sort_list - sorts using bubble sort concept
 * but it sorts both ways per a single loop
 *
 * @list: the list to be sorted
 *
 * Return: nothing
*/

void cocktail_sort_list(listint_t **list)
{
	listint_t *iter;
	int size = size_of_list(*list), i = 0, j = 0;

	if (list == NULL || (*list) == NULL || (*list)->next == NULL)
	return;

	for (i = 0; i < size - 1; i++)
	{
		iter = (*list)->next;
		for (j = 1; j < size - i; j++)
		{
			if (iter->prev->n > iter->n)
			{
				swap_node(iter->prev, iter);
				if (j == 1)
				*list = iter;
				iter = iter->next;
				print_list(*list);
			}
			if (j + 1 != size - i)
			iter = iter->next;
		}

		iter = iter->prev;
		for (j--; j > 1; j--)
		{
			if (iter->prev->n > iter->n)
			{
				swap_node(iter->prev, iter);
				if (j == 2)
				*list = iter;
				iter = iter->next;
				print_list(*list);
			}
			iter = iter->prev;
		}
	}
}

/**
 * size_of_list - compute the size of the doubly linked list
 *
 * @head: head node of the list
 *
 * Return: integer which is the size
*/

int size_of_list(listint_t *head)
{
	int i = 0;

	while (head != NULL)
	{
		i++;
		head = head->next;
	}
	return (i);
}

/**
 * swap_node - swaps two node of doubly linked list
 *
 * @left: the left node to be swapped
 * @right: the right node to be swapped
 *
 * Return: nothing
*/

void swap_node(listint_t *left, listint_t *right)
{
	listint_t *temp;

	/*swaping left previous next pointer and right next previous pointer*/
	if (left->prev)
	left->prev->next = right;

	if (right->next)
	right->next->prev = left;

	/*swaping next pointers*/
	left->next = right->next;
	right->next = left;

	/*swaping previous pointers*/
	temp = left->prev;
	left->prev = right;
	right->prev = temp;
}
