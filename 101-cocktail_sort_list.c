#include "sort.h"
/**
 * swap1 -> swps nodes from lft to rht
 * @list: Lst
 * @had: Hed Node
 * @aux: Auxiliar Node
 */

void swap1(listint_t **list, listint_t *head, listint_t *aux)
{
	if (head->prev)
		head->prev->next = aux;
	else
		*list = aux;
	if (aux->next)
		aux->next->prev = head;
	head->next = aux->next;
	aux->prev = head->prev;
	aux->next = head;
	head->prev = aux;
	print_list(*list);

}

/**
 * swap2 -> Swps nodes frm rht to lft
 * @lst: Lst
 * @had: Hed Node
 * @aux: Auxiliar Node
 */

void swap2(listint_t **list, listint_t *head, listint_t *aux)
{
	aux = head->prev;
	aux->next->prev = aux->prev;
	if (aux->prev)
		aux->prev->next = aux->next;
	else
		*list = aux->next;
	aux->prev = aux->next;
	aux->next = aux->next->next;
	aux->prev->next = aux;
	if (aux->next)
		aux->next->prev = aux;
	print_list(*list);
}

/**
 * coktal_srt_lst -> srts a dbly lnkd lst of intgrs
 * @list: Lst
 **/

void cocktail_sort_list(listint_t **list)
{
	listint_t *h, *a;
	int b = 1;

	if (list)
	{
		h = *list;
		while (b != 0)
		{
			b = 0;
			while (h->next)
			{
				if (h->n > h->next->n)
				{
					a = h->next;
					swap1(list, h, a);
					b = 1;
				}
				else
					h = h->next;
			}
			if (b == 0)
				break;
			b = 0;
			while (h->prev)
			{
				if (h->prev->n > h->n)
				{
					swap2(list, h, a);
					b = 1;
				}
				else
					h = h->prev;
			}

		}
	}
}
