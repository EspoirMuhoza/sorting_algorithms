#include "sort.h"

/**
 * shell_sort - Function that sorts an array of integer
 * @array: array of integers to be sorted
 * @size: amount of elements in array
 */
void shell_sort(int *array, size_t size)
{
	int i, j, gap, n, Knuth_max, temp;

	if (!array || size < 2)
		return;

	n = (int)size;
	for (gap = 1; gap < n; gap = (gap * 3) + 1)
	{
		Knuth_max = gap;
	}
/* Start with the largest Knuth seq value less than n as gap, */
/* and work down sequence to a gap of 1 */
	for (gap = Knuth_max; gap > 0; gap = (gap - 1) / 3)
	{
		for (i = gap; i < n; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = temp;
		}
		print_array(array, size);
	}
}
