#include "binary_trees.h"

/**
 * binary_tree_depth - measure the depth of a node
 * @node: a binary tree node
 * Return: the number of edges from the node to the root
 */
size_t binary_tree_depth(const binary_tree_t *node)
{
	size_t count;

	count = 0;
	if (node)
		while (node->parent)
		{
			node = node->parent;
			++count;
		}
	return (count);
}
