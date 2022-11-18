#include "binary_trees.h"

/**
 * binary_tree_rotate_right - rotate a node to the right
 * @node: pointer to a node in a binary tree
 * Return: pointer to the new parent
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *node)
{
	binary_tree_t *tmp;

	if (!node)
		return (NULL);

	tmp = node->left;

	if (!tmp)
		return (node);

	node->left = tmp->right;
	if (node->left)
		(node->left)->parent = node;

	tmp->right = node;
	tmp->parent = node->parent;
	if (tmp->parent)
	{
		if ((tmp->parent)->left == node)
			(tmp->parent)->left = tmp;
		else
			(tmp->parent)->right = tmp;
	}
	node->parent = tmp;

	return (tmp);
}
