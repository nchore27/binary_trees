#include "binary_trees.h"
/**
 * bst_insert - inserts a node into a bst so that it remains a bst
 * @tree: double ptr to root of tree
 * @value: int value at node
 * Return: ptr to the new node in the tree
 */
bst_t *bst_insert(bst_t **tree, int value)
{

	binary_tree_t *temp, *parent, *new;

	if (!tree)
		return (NULL);
	if (!(*tree))
	{
		*tree = binary_tree_node(*tree, value);
		return (*tree);
	}
	temp = (*tree);
	while (temp)
	{
		parent = temp;
		if (value > temp->n)
			temp = temp->right;
		else if (value < temp->n)
			temp = temp->left;
		else
			return (NULL);
	}
	new = binary_tree_node(parent, value);
	if (parent->n < value)
		parent->right = new;
	if (parent->n > value)
		parent->left = new;
	return (new);
}
