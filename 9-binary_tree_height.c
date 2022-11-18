#include "binary_trees.h"

/**
 * binary_tree_height - measure the height of a binary tree
 * @tree: root of binary tree
 * Return: maximal number of edges between the root and a leaf node
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree && (tree->left || tree->right))
		return (1 + MAX(binary_tree_height(tree->left),
				binary_tree_height(tree->right)));

	return (0);
}
