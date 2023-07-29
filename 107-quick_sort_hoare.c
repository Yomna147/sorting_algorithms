#include "sort.h"

/**
*swap -> swap two elements
*@array: Ary
*@item1: Element 1
*@item2: Element 2
*/

void swap(int *array, ssize_t item1, ssize_t item2)
{
	int i;

	i = array[item1];
	array[item1] = array[item2];
	array[item2] = i;
}

/**
 *hoare_partition -> Hoare partition scheme
 *@array: Ary
 *@first: First Ary Element
 *@last: Last Ary Element
 *@size: Ary's sze
 *Return: Position
 */

int hoare_partition(int *array, int first, int last, int size)
{
	int a = first - 1, b = last + 1;
	int p = array[last];

	while (1)
	{
		do {
			a++;
		} while (array[a] < p);
		do {
			b--;
		} while (array[b] > p);
		if (a >= b)
			return (a);
		swap(array, a, b);
		print_array(array, size);
	}
}

/**
 *qs -> Quicksort algorithm
 *@array: Array
 *@first: Element 1
 *@last: Element 2
 *@size: Array's size
 */

void qs(int *array, ssize_t first, ssize_t last, int size)
{
	ssize_t p = 0;

	if (first < last)
	{
		p = hoare_partition(array, first, last, size);
		qs(array, first, p - 1, size);
		qs(array, p, last, size);
	}
}

/**
 *quick_sort_hoare -> Srts an ary of intgrs in asnding order
 *@ary: Ary
 *@size: Ary's size
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	qs(array, 0, size - 1, size);
}
