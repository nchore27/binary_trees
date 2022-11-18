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
 * binary_tree_nodes - counts nodes in a binary-tree with at least one child
 * @tree: pointer to root of binary tree
 * Return: nodes-with-children count
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree && !(binary_tree_is_leaf(tree)))
	{
		return (1 + binary_tree_nodes(tree->left) +
			binary_tree_nodes(tree->right));
	}
	return (0);
}
