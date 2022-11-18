#include "binary_trees.h"

/**
 * exponent - simple exponent helper function
 * @base: base of number
 * @power: power that the base will be raised to
 * Return: base to the exponent
 */
size_t exponent(size_t base, size_t power)
{
	size_t result;

	result = 1;
	while (power > 0)
	{
		result *= base;
		--power;
	}
	return (result);
}
/**
 * binary_tree_height - measure the height of a binary tree
 * @tree: root of binary tree
 * Return: maximal number of edges between the root and a leaf node
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t count;

	count = 0;
	if (tree && (tree->left || tree->right))
		count = 1 + MAX(binary_tree_height(tree->left),
				binary_tree_height(tree->right));

	return (count);
}
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
 * binary_tree_is_perfect - "perfect" basically means full and symmetric
 * and the nodecount of each level of the tree will be a power of 2
 * we compare our total nodes to the nodecount of a perfect tree of that height
 * @tree: ptr to binary tree node
 * Return: 1 if perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t sum, i, j;

	j = binary_tree_height(tree) + 1;
	sum = 0;
	for (i = 0; i < j; i++)
		sum += exponent(2, i);
	if (sum == binary_tree_size(tree))
		return (1);
	return (0);
}
