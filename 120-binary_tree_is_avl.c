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
 * binary_tree_is_balanced - returns if difference in heights is <= 1
 * @tree: ptr to root of tree
 * Return: balance factor
 */
int binary_tree_is_balanced(const binary_tree_t *tree)
{
	if (!tree)
		return (1);
	if (ABS(binary_tree_h(tree->left) -
		    binary_tree_h(tree->right)) > 1)
		return (0);
	if (binary_tree_is_balanced(tree->left) &&
		binary_tree_is_balanced(tree->right))
		return (1);
	return (0);

}
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
 * binary_tree_is_avl - checks if a binary tree is an AVL tree
 * AVL trees are binary search trees
 * Wherein the height of a left subtree is never 1 greater than that
 * of a right subtree, and vice versa
 * AVL trees look extremely symmetrical relative to binary trees
 * that lack such strict balance requirements
 * @tree: ptr to root of a binary tree
 * Return: 1 if AVL, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!bst_check(tree, NULL, NULL))
		return (0);
	if (binary_tree_is_balanced(tree))
		return (1);
	return (0);
}
