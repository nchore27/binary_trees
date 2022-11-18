#include "binary_trees.h"


/**
 * binary_tree_h - measure the height of a binary tree by edge count
 * @tree: root of binary tree
 * base case is -1 for NULL node
 * Return: maximal number of edges on left or right
 */
int binary_tree_h(const binary_tree_t *tree)
{
	int count;

	count = -1;
	if (tree)
		count = 1 + MAX(binary_tree_h(tree->left),
				binary_tree_h(tree->right));
	return (count);
}
/**
 * binary_tree_balance - returns the difference of the maximal edge count on
 * left and  maximal edge count on right
 * @tree: ptr to root of tree
 * Return: balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (binary_tree_h(tree->left) -
		binary_tree_h(tree->right));

}
