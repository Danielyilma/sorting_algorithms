#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list
 *
 * @list: head of the doubly linked list
 *
 * Return: nothing
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *iter = *list, *temp;

	while (iter != NULL)
	{
		temp = iter->next;

		while (iter->prev != NULL && iter->prev->n > iter->n)
		{
			swap_node(iter->prev, iter);

			if (iter->prev == NULL)
			*list = iter;
			print_list(*list);
		}

		if (iter->prev == NULL)
		*list = iter;

		iter = temp;
	}

}

/**
 * swap - swaps two node of doubly linked list
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
