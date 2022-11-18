#include "binary_trees.h"


/**
 * tree_delete - delete a binary tree
 * @tree: pointer to binary tree
 */
void tree_delete(binary_tree_t *tree)
{
	if (!tree)
		return;
	if (tree->left)
		tree_delete(tree->left);
	if (tree->right)
		tree_delete(tree->right);
	free(tree);
}
/**
 * array_to_avl - create an avl tree from values passed as an array
 * @array: an array of ints
 * @size: size of array
 * Return: pointer to root or NULL
 */
avl_t *array_to_avl(int *array, size_t size)
{
	size_t i;
	avl_t *tree, *tmp;

	if (!array || !size)
		return (NULL);

	tree = NULL;
	for (i = 0; i < size; ++i)
	{
/*		printf("step %lu insert %d\n", i, array[i]);*/
		tmp = avl_insert(&tree, array[i]);
		if (tmp == NULL)
		{
			tree_delete(tree);
			return (NULL);
		}
	}
	return (tree);
}
