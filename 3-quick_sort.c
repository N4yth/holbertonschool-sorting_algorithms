#include "sort.h"

void quick_sort_recu(int *array, size_t size, int *full_arr, size_t full_size);

/**
 * quick_sort - function that will sort an array with the quick sort algorithm
 *
 * @array: the array to sort
 * @size: the size of the array
 *
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array != NULL)
		quick_sort_recu(array, size, array, size);
}



/**
 * quick_sort_recu - the function that will do the recurtion on itself to sort
 *
 * @array: the array to sort
 * @size: the size of the array to sort
 * @full_arr: the full array to print
 * @full_size: the size of the full array
 *
 * Return: Nothing
 */

void quick_sort_recu(int *array, size_t size, int *full_arr, size_t full_size)
{
	size_t idx = 0;
	size_t j, tmp;
	int pivot = array[size - 1];

	for (j = 0; j < size; j++)
	{
		if (array[j] <= pivot)
		{
			if (j != idx)
			{
				tmp = array[j];
				array[j] = array[idx];
				array[idx] = tmp;
				print_array(full_arr, full_size);
			}
			idx++;
		}
	}

	if (size <= 2)
		return;

	quick_sort_recu(array, idx - 1, full_arr, full_size);
	quick_sort_recu(array + idx, size - idx, full_arr, full_size);
}
