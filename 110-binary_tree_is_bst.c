#include "binary_trees.h"
/**
 * bst_check - checks if a tree is a bst
 * @tree: ptr to root of tree on first call, subtrees after that
 * @min: ptr to node holding min value
 * @max: ptr to node holding min value
 * Return: 1 if BST, 0 if not
 */
int bst_check(const binary_tree_t *tree, const binary_tree_t *min,
	      const binary_tree_t *max)
{
	if (!tree)
		return (1);
	if (min && tree->n <= min->n)
		return (0);
	if (max && tree->n >= max->n)
		return (0);
	return (bst_check(tree->left, min, tree) &&
		bst_check(tree->right, tree, max));
}
/**
 * binary_tree_is_bst - wrapper for function that actually checks bst
 * @tree: ptr to root of tree
 * Return: 1 if BST, 0 if not
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (bst_check(tree, NULL, NULL));
}
