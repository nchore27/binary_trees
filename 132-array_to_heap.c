#include "binary_trees.h"
/**
 * tree_delete - delete a binary tree
 * @tree: pointer to binary tree
 */
void tree_delete(binary_tree_t *tree)
{
	if (!tree)
		return;
	if (tree->left)
		tree_delete(tree->left);
	if (tree->right)
		tree_delete(tree->right);
	free(tree);
}
/**
 * array_to_heap - loops through array and inserts into heap
 * @array: ptr to array
 * @size: size of array
 * Return: root of tree or NULL for failure
 */
heap_t *array_to_heap(int *array, size_t size)
{
	size_t i;
	heap_t *root, *temp;

	if (size < 1 || !(array))
		return (NULL);
	root = NULL;
	for (i = 0; i < size; i++)
	{
		temp = heap_insert(&root, array[i]);
		if (temp == NULL)
		{
			tree_delete(root);
			return (NULL);
		}
	}
	return (root);
}
