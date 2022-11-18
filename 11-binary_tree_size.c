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
