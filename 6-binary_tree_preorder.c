#include "binary_trees.h"

/**
 * binary_tree_preorder - traverse a tree using pre-order
 * @tree: root of binary tree
 * @func: function to apply to each node
 * pre order traversal is visiting the node, then its left subtree
 * then its right subtree
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!func)
		return;
	if (tree)
	{
		func(tree->n);
		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}
}
