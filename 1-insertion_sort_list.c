#include "sort.h"

/**
 * insertion_sort_list - function to sorts a doubly linked list
 * order using an insertion sort algorithm
 * @list: doubly linked list of integers to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *lead, *follow, *new, *temp;

	if (!list || !(*list) || !((*list)->next))
		return;

	/* dance begins with 1st from house left following */
	follow = (*list);
	lead = (*list)->next;
	while (lead)
	{
		new = lead->next;
		while (follow && lead->n < follow->n)
		{
			if (follow->prev)
				follow->prev->next = lead;
			else
				*list = lead;
			if (lead->next)
				lead->next->prev = follow;
			temp = lead->next;
			lead->next = follow;
			lead->prev = follow->prev;
			follow->next = temp;
			follow->prev = lead;
			print_list(*list);
			follow = lead->prev;
		}
		lead = new;
		if (lead)
			follow = lead->prev;
	}
}
