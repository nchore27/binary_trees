#include "binary_trees.h"
/**
 * child_count - returns 1 for 0/2 children, 0 for 1 child
 * @tree: ptr to binary tree node
 * Return: 0 or 1
 */
int child_count(const binary_tree_t *tree)
{
	int count;

	count = 0;
	if (tree)
	{
		if (tree->left)
			++count;
		if (tree->right)
			++count;
	}
	return (count);
}
/**
 * binary_tree_check - checks if tree is full
 * @tree: root of binary tree
 * @func: function to apply to each node
 * Return: 1 if full, 0 otherwise
 */
int binary_tree_check(const binary_tree_t *tree,
			  int (*func)(const binary_tree_t *node))
{
	int i;

	if (tree)
	{
		i = func(tree);
		if (i == 0)
			return (1);
		if (i == 1)
			return (0);
		return (binary_tree_check(tree->left, func) &&
			binary_tree_check(tree->right, func));
	}
	return (0);
}
/**
 * binary_tree_is_full- function wrapper for binary_tree_check
 * @tree: ptr to node
 * Return: binary_tree_check result
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	return (binary_tree_check(tree, child_count));
}
