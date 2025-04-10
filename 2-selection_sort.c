#include "sort.h"
/**
 * bubble_sort - function that sort an array
 * @array: pointeur to array
 * @size: lenght to array
 *
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t min = 0, tmp = 0, i, j, k;

	for (i = 0; i < (size - 2); i++)
	{
		min = i;

		for (j = i + 1 ; j < (size); j++)
		{
			if (array[min] > array[j])
				min = j;
		}

		if (min != i)
		{
			tmp = array[i];
			array[i] = array[min];
			array[min] = tmp;
		}

		for (k = 0; k < (size); k++)
		{
			printf("%d", array[k]);
			if (k < (size - 1))
				printf(", ");
		}

		printf("\n");
	}
}
