#include "binary_trees.h"

/**
 * binary_tree_inorder - traverse a tree using pre-order
 * @tree: root of binary tree
 * @func: function to apply to each node
 * pre order traversal is visiting the node left subtree then the node
 * then its right subtree
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!func)
		return;
	if (tree)
	{
		binary_tree_inorder(tree->left, func);
		func(tree->n);
		binary_tree_inorder(tree->right, func);
	}
}
