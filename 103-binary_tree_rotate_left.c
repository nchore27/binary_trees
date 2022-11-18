#include "binary_trees.h"
/**
 * binary_tree_rotate_left - left-rotates a binary tree
 * @tree: ptr to root of tree
 * Return: ptr to new root of tree
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *temp;

	if (!tree)
		return (NULL);
	temp = tree->right;
	if (!temp)
		return (tree);
	tree->right = (temp)->left;
	if (temp->left)
		temp->left->parent = tree;
	temp->parent = tree->parent;
	if (tree->parent)
	{
		if (tree == tree->parent->left)
			tree->parent->left = temp;
		else
			tree->parent->right = temp;
	}
	temp->left = tree;
	tree->parent = temp;
	return (temp);
}
