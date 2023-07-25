#include "sort.h"

/**
 * insertion_sort_list -> Sorts a dbly lnked lst of integers
 * @list: Dbly Lnked Lst
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *n;

	if (list == NULL || (*list)->next == NULL)
		return;
	n = (*list)->next;
	while (n)
	{
		while ((n->prev) && (n->prev->n > n->n))
		{
			n = swap_node(n, list);
			print_list(*list);
		} n = n->next;
	}
}

/**
 *swap_node -> Swap two nodes
 *@node: Node
 *@list: Lst Node
 *Return: Node
 */

listint_t *swap_node(listint_t *node, listint_t **list)
{
	listint_t *prev = node->prev, *now = node;

	prev->next = now->next;
	if (now->next)
		now->next->prev = prev;
	now->next = prev;
	now->prev = prev->prev;
	prev->prev = now;
	if (now->prev)
		now->prev->next = now;
	else
		*list = now;
	return (now);
}
