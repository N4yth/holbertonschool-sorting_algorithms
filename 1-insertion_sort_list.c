#include "sort.h"

listint_t *move_node(listint_t *h, listint_t *node);

/**
 * insertion_sort_list - sort a doubly linked list with insertion
 *
 * @list: the head of doubly linked list
 *
 * Return: nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *tmp_current = *list;

	tmp_current = tmp_current->next;
	while (tmp_current != NULL)
	{
		while (tmp_current->n < tmp_current->prev->n)
		{
			tmp_current = move_node(tmp_current->prev, tmp_current);
			if (tmp_current->prev == NULL)
			{
				*list = tmp_current;
				print_list(*list);
				break;
			}
			print_list(*list);
		}
		tmp_current = tmp_current->next;
		if (tmp_current == NULL)
			break;
	}

}

/**
 * move_node - swap a node with the previous one
 *
 * @Pr_node: previous node to swap
 * @node: current node to swap
 *
 * Return: the adresse of the swap node that became previous
 */

listint_t *move_node(listint_t *Pr_node, listint_t *node)
{
	if (Pr_node->prev == NULL)
		node->prev = NULL;
	else
	{
		Pr_node->prev->next = node;
		node->prev = Pr_node->prev;
	}
	if (node->next == NULL)
		Pr_node->next = NULL;
	else
	{
		node->next->prev = Pr_node;
		Pr_node->next = node->next;
	}
	node->next = Pr_node;
	Pr_node->prev = node;

	return (node);
}
