#include "binary_trees.h"


/**
 * enqueue - insert a node at the end
 * @head: head of queue
 * @node: node to insert
 * Return: pointer to newly created list element or NULL on failure
 */
queue_t *enqueue(queue_t **head, const binary_tree_t *node)
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
 * dequeue - return a node from the beginning
 * @head: head of queue
 * Return: a pointer to a binary tree node
 */
binary_tree_t *dequeue(queue_t **head)
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
 * binary_tree_levelorder - will traverse a binary tree in level order
 * once I get it together after a good night's sleep
 * @tree: ptr to node of binary tree
 * @func: pointer to Alex's function
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue_t *queue;
	binary_tree_t *temp;

	if (!tree || !func)
		return;

	queue = NULL;
	enqueue(&queue, tree);

	while (queue)
	{
		temp = dequeue(&queue);
		func(temp->n);
		enqueue(&queue, temp->left);
		enqueue(&queue, temp->right);
	}
}
