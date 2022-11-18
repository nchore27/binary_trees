#include "binary_trees.h"
/**
 * enqueue2 - insert a node at the end
 * @head: head of queue
 * @node: node to insert
 * Return: pointer to newly created list element or NULL on failure
 */
queue_t *enqueue2(queue_t **head, const binary_tree_t *node)
{
	queue_t *new, *tmp;

	if (!node)
		return (NULL); /*do not insert a null value*/

	if (!head)
		return (NULL); /*edge case we should not meet here*/

	new = malloc(sizeof(queue_t));
	if (!new)
	{
		while (*head)
		{
			tmp = *head;
			*head = (*head)->next;
			free(tmp);
		}
		return (NULL);
	}

	new->node = (binary_tree_t *)node;
	new->next = NULL;
	if (!*head)
	{
		*head = new;
	}
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (new);
}

/**
 * dequeue2 - return a node from the beginning
 * @head: head of queue
 * Return: a pointer to a binary tree node
 */
binary_tree_t *dequeue2(queue_t **head)
{
	queue_t *tmp;
	binary_tree_t *node;

	if (!head || !*head)
		return (NULL);

	tmp = *head;
	*head = tmp->next;
	node = tmp->node;
	free(tmp);

	return (node);
}
/**
 * heapify_downward - basically performs a binary search downward
 * and swaps when parent < child
 * @tree: ptr to root
 */
void heapify_downward(heap_t *tree)
{
	int temp;

	if (!tree || !(tree->right || tree->left))
		return;
	else if (!(tree->right))
	{
		if (tree->left->n > tree->n)
		{
			temp = tree->n;
			tree->n = tree->left->n;
			tree->left->n = temp;
			heapify_downward(tree->left);
			return;
		}
	}
	else
	{
		if (tree->left->n > tree->right->n && tree->n < tree->left->n)
		{
			temp = tree->n;
			tree->n = tree->left->n;
			tree->left->n = temp;
			heapify_downward(tree->left);
			return;
		}
		if (tree->left->n < tree->right->n && tree->n < tree->right->n)
		{
			temp = tree->n;
			tree->n = tree->right->n;
			tree->right->n = temp;
			heapify_downward(tree->right);
			return;
		}
	}
}
/**
 * heap_extract - takes out "last" node and updates root
 * basically, removes root of a max binary heap
 * @root: ptr to root
 * Return: value of root
 */
int heap_extract(heap_t **root)
{
	queue_t *queue;
	binary_tree_t *temp;
	int value;

	if (!(*root))
		return (0);
	queue = NULL;
	enqueue2(&queue, *root);
	while (queue)
	{
		temp = dequeue2(&queue);
		enqueue2(&queue, temp->left);
		enqueue2(&queue, temp->right);
	}
	if (temp->parent)
	{
		if (temp->parent->left == temp)
			temp->parent->left = NULL;
		else
			temp->parent->right = NULL;
	}
	temp->parent = NULL;
	temp->right = (*root)->right;
	if (temp->right)
		temp->right->parent = temp;
	temp->left = (*root)->left;
	if (temp->left)
		temp->left->parent = temp;
	value = (*root)->n;
	if (*root == temp)
	{
		free(*root); *root = NULL;
	}
	else
	{
		free(*root);
		*root = temp;
		heapify_downward(temp);
	}
	return (value);
}
