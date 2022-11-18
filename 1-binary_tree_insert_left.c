#include "binary_trees.h"

/**
 * binary_tree_insert_left - insert a node as the left child
 * @parent: parent of node to insert
 * @value: value to insert on left of parent
 * This function builds on the one to create a node (file 0-...)
 * If a node is already there, move it down as left child
 * Return: pointer to the newly inserted node
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (!parent)
		return (NULL);
	new = binary_tree_node(parent, value);
	if (!new)
		return (NULL);

	if (parent->left)
	{
		new->left = parent->left;
		(new->left)->parent = new;
	}
	parent->left = new;
	return (new);
}
