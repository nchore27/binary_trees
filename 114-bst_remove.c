#include "binary_trees.h"

/**
 * set_parent - set the parent of the node to remove right
 * @node: node to remove
 * @swap: node to swap it with
 */
void set_parent(bst_t *node, bst_t *swap)
{
		if (node->parent)
		{
			if ((node->parent)->left == node)
				(node->parent)->left = swap;
			else
				(node->parent)->right = swap;
		}
}

/**
 * delete_min - delete the minimum node in a binary search tree
 * @tree: pointer to root
 * Return: value of the minimum node
 */
int delete_min(bst_t *tree)
{
	int value;

	if (!tree)
		return (INT_MAX);
	while (tree->left)
		tree = tree->left;
	value = tree->n;
	if (tree->right)
		(tree->right)->parent = tree->parent;
	if (tree->parent)
	{
		if ((tree->parent)->left == tree)
			(tree->parent)->left = tree->right;
		else
			(tree->parent)->right = tree->right;
	}
	free(tree);
	tree = NULL;
	return (value);
}


/**
 * bst_remove - remove a value in a BST
 * @root: pointer to the root
 * @value: value to remove
 * Return: pointre to the root
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *tmp;

	if (!root)
		return (NULL);
	tmp = root;
	while (tmp)
	{
		if (tmp->n < value)
			tmp = tmp->right;
		else if (tmp->n > value)
			tmp = tmp->left;
		else
			break;
	}
	if (!tmp)
		return (root);
	if ((tmp->right) && (tmp->left))
	{
		tmp->n = delete_min(tmp->right);
	}
	else
	{
		if (!(tmp->right) && !(tmp->left))
		{
			set_parent(tmp, NULL);
		}
		else if (!(tmp->right))
		{
			(tmp->left)->parent = tmp->parent;
			set_parent(tmp, tmp->left);
		}
		else
		{
			(tmp->right)->parent = tmp->parent;
			set_parent(tmp, tmp->right);
		}
		free(tmp);
		tmp = NULL;
	}
	return (root);
}
