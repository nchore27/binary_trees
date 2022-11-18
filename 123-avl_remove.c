#include "binary_trees.h"

/**
 * set_parent - set the parent of the node to remove right
 * @node: node to remove
 * @swap: node to swap it with
 */
void set_parent(bst_t *node, bst_t *swap)
{
	if (!node)
		return;
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
 * Return: the minimum node
 */
bst_t *delete_min(bst_t *tree)
{

	if (!tree)
		return (NULL);
	while (tree->left)
		tree = tree->left;
	if (tree->right)
		(tree->right)->parent = tree->parent;
	if (tree->parent)
	{
		if ((tree->parent)->left == tree)
			(tree->parent)->left = tree->right;
		else
			(tree->parent)->right = tree->right;
	}
	return (tree);
}


/**
 * simple_remove - remove a value in a BST
 * @root: pointer to the root
 * @value: value to remove
 * Return: pointer to the deleted node or NULL
 */
bst_t *simple_remove(bst_t *root, int value)
{
	bst_t *tmp, *removed;

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
		return (NULL);
	if ((tmp->right) && (tmp->left))
	{
		removed = delete_min(tmp->right);
		tmp->n = removed->n;
		return (removed);
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
	}
	return (tmp);
}

/**
 * re2_balance - re balances the tree to keep its AVL property
 * @tree: pointer to the root of the subtree to consider
 * Return: pointer to the new root
 */
avl_t *re2_balance(avl_t *tree)
{
	int balance;

	if (!tree)
		return (NULL);
	balance = binary_tree_balance((const binary_tree_t *)tree);
	if (balance > 1) /*left leaning tree*/
	{
		if (binary_tree_balance((const avl_t *)tree->left) <= -1)
			tree->left = binary_tree_rotate_left(tree->left);
		tree = binary_tree_rotate_right(tree);
	}
	else if (balance < -1) /*right leaning tree*/
	{
		if (binary_tree_balance((const avl_t *)tree->right) >= 1)
			tree->right = binary_tree_rotate_right(tree->right);
		tree = binary_tree_rotate_left(tree);
	}
	return (tree);
}

/**
 * avl_remove - insert a new value in an AVL node
 * @root: pointer to the root of the tree
 * @value: value to insert
 * Return: pointer to the new root
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *remove, *tmp;

	remove = simple_remove(root, value);
	if (!remove)
		return (root);
	tmp = remove->parent;
	free(remove);
	if (tmp)
	{
		while (tmp->parent)
		{
			tmp = re2_balance(tmp);
			tmp = tmp->parent;
		}
/* at this point tmp is pointing to the root */
		root = re2_balance(tmp);
	}
	return (root);
}
