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
 * heapify_tree - heapifies our tree!
 * travels up tree from parent to parent
 * swaps when root > parent
 * @root: ptr to new node from heap_insert
 * Return: a pointer to the final node bearing the value inserted
 */
heap_t *heapify_tree(heap_t *root)
{
	int temp;
	heap_t *to_return;

	to_return = root;
	while (root->parent)
	{
		if (root->parent->n < root->n)
		{
			temp = root->n;
			root->n = root->parent->n;
			root->parent->n = temp;
			to_return = root->parent;
		}
		root = root->parent;
	}
	return (to_return);
}
/**
 * heap_insert - inserts into a heap
 * insertion must not break max binary heap
 * so after inserting the node, we traverse up the tree,
 * swapping nodes until all properties of max binary heaps
 * are satisfied
 * @root: double ptr to root of max bin heap
 * @value: int value to be included in new node
 * Return: ptr to created node or NULL if not possible
 */
heap_t *heap_insert(heap_t **root, int value)
{
	queue_t *queue;
	binary_tree_t *temp;
	heap_t *new, *to_return;

	if (!root)
		return (NULL);
	if (!(*root))
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}
	queue = NULL;
	enqueue(&queue, *root);

	while (queue)
	{
		temp = dequeue(&queue);
		if (!temp->left || !temp->right)
		{
			free_queue(&queue);
			break;
		}
		enqueue(&queue, temp->left);
		enqueue(&queue, temp->right);
	}
	new = binary_tree_node(temp, value);
	if (!new)
		return (NULL);
	if (!temp->left)
		temp->left = new;
	else
		temp->right = new;
	to_return = heapify_tree(new);
	return (to_return);
}
