#include "binary_trees.h"

/**
 * sata - recursive function to make a Sorted Array To AVL
 * @array: pointer to an array
 * @lo: minimum index to consider in the array (included)
 * @hi: upper index to consider (excluded)
 * @parent: parent of node to create
 * Return: pointer to created node
 */
avl_t *sata(int *array, size_t lo, size_t hi, avl_t *parent)
{
	avl_t *node;
	size_t mid;

	if (lo >= hi)
		return (NULL);

	mid = (lo + hi - 1) / 2;
/*	printf("creating node for array[%lu] = %i\n", mid, array[mid]);*/
	node = binary_tree_node(parent, array[mid]);
	if (!node)
		return (NULL);
	node->left = sata(array, lo, mid, node);
/*	printf("going right for node %i\n", node->n);*/
	node->right = sata(array, mid + 1, hi, node);
	return (node);
}

/**
 * sorted_array_to_avl - build an AVL tree from a sorted array
 * @array: pointer to a sorted array
 * @size: size of array
 * Return: pointer to the root of the tree or NULL
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root;

	if (!array)
		return (NULL);
	root = sata(array, 0, size, NULL);
	return (root);
}
