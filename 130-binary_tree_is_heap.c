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
 * free_queue - frees a queue!
 * @head: ptr to head of queue
 *
 */
void free_queue(queue_t **head)
{
	queue_t *temp1, *temp2;

	if (!head || !(*head))
		return;
	temp1 = *head;
	while (temp1 != NULL)
	{
		temp2 = temp1;
		temp1 = temp1->next;
		free(temp2);
	}
	*head = NULL;
}
/**
 * binary_tree_is_heap - will traverse a binary tree in level order
 * checks each parent to see if it's > both children
 * @tree: ptr to node of binary tree
 * Return: 1 if b heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	queue_t *queue;
	binary_tree_t *temp;
	int no_more_kids;

	if (!tree)
		return (0);
	queue = NULL;
	enqueue(&queue, tree);
	no_more_kids = 0;
	while (queue)
	{
		temp = dequeue(&queue);
		if (temp->left)
		{
			if (no_more_kids || temp->n < temp->left->n)
			{
				free_queue(&queue); return (0);
			}
			else if (!(temp->right))
			{
				no_more_kids = 1;
			}
			if (temp->right && temp->n < temp->right->n)
			{
				free_queue(&queue); return (0);
			}
		}
		else
		{
			if (temp->right)
			{
				free_queue(&queue); return (0);
			}
		}
		enqueue(&queue, temp->left);
		enqueue(&queue, temp->right);
	}
	return (1);
}
