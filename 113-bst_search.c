#include "binary_trees.h"
/**
 * bst_search - searches for node in tree!
 * @value: value to find
 * @tree: ptr to current root node
 * Return: node if found or NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);
	if (value == tree->n)
		return ((bst_t *)tree);
	else if (value < tree->n)
		return (bst_search(tree->left, value));
	else
		return (bst_search(tree->right, value));
}
