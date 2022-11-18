#include "binary_trees.h"
/**
 * binary_tree_is_leaf - check if a node is a leaf
 * @node: a binary tree node
 * Return: 1 for True, 0 for False
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (!node)
		return (0);
	if (node->left || node->right)
		return (0);
	return (1);
}
/**
 * binary_tree_leaves - counts leaves in a binary-tree
 * @tree: pointer to root of binary tree
 * Return: leaf count
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t count;

	count = 0;
	if (binary_tree_is_leaf(tree))
	{
		count = 1;
	}
	else if (tree)
	{
		count = binary_tree_leaves(tree->right)
			+ binary_tree_leaves(tree->left);
	}
	return (count);
}
