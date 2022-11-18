#include "binary_trees.h"

/**
 * binary_tree_size - measure the size of a binary tree
 * @tree: root of the tree
 * Return: number of nodes in the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t count;

	count = 0;
	if (tree)
		count = 1 + binary_tree_size(tree->left)
			+ binary_tree_size(tree->right);

	return (count);
}
/**
 * heap_to_sorted_array - turns heap into sorted array
 * @heap: ptr to root of heap
 * @size: size of array
 * Return: ptr to array
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *array;
	size_t i;

	if (!heap)
		return (NULL);
	*size = binary_tree_size(heap);
	array = malloc(sizeof(int) * (*size));
	if (array == NULL)
		return (NULL);
	for (i = 0; i < *size; i++)
		array[i] = heap_extract(&heap);
	return (array);
}
