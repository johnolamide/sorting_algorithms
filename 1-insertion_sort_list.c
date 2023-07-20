#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: double pointer to the head of the list
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		tmp = current->prev;
		while (tmp != NULL && tmp->n > current->n)
		{
			tmp->next = current->next;
			if (current->next != NULL)
				current->next->prev = tmp;
			current->next = tmp;
			current->prev = tmp->prev;
			tmp->prev = current;
			if (current->prev == NULL)
				*list = current;
			else
				current->prev->next = current;
			print_list(*list);
			tmp = current->prev;
		}
		current = current->next;
	}
}
