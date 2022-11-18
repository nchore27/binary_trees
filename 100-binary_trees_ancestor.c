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
/**
 * move_up - moves up a node target times
 * @node: ptr to tree node
 * @target: number of times to move up
 * Return: new node location
 */
binary_tree_t *move_up(binary_tree_t *node, size_t target)
{
	if (node)
		while (target > 0)
		{
			node = node->parent;
			--target;
		}
	return (node);
}
/**
 * binary_trees_ancestor - finds shallowest common ancestor of two nodes
 * shout out to our given prototype being too long for betty
 * @first: the first node on the tree
 * @second: the second node on the tree
 * Return: ancestor or NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	size_t depth_first, depth_second;
	binary_tree_t *f, *s;

	if (!first || !second)
		return (NULL);
	f = (binary_tree_t *)first, s = (binary_tree_t *)second;
	depth_first = binary_tree_depth(f);
	depth_second = binary_tree_depth(s);
	if (depth_first > depth_second)
		f = move_up(f, depth_first - depth_second);
	else if (depth_second > depth_first)
		s = move_up(s, depth_second - depth_first);
	while (f && s)
	{
		if (f == s)
			return (f);
		f = f->parent;
		s = s->parent;
	}
	return (NULL);
}
