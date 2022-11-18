#ifndef BINARY_TREES_H_
#define BINARY_TREES_H_

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <limits.h>

/* macros */
#define MAX(X, Y) ((X) >= (Y) ? (X) : (Y))
#define ABS(X) ((X) < 0 ? (-(X)) : (X))

/* data types, structs given to perform the tasks */

/*for the binary tree*/
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;

/*for the BST*/
typedef struct binary_tree_s bst_t;

/*for the AVL tree*/
typedef struct binary_tree_s avl_t;

/*for the max binary heap*/
typedef struct binary_tree_s heap_t;

/*struct for breadth first traversal*/
/**
 * struct queue_s - struct for a tree linked list
 * @node: a binary_tree_t *
 * @next: pointer to the next value
 */
typedef struct queue_s
{
	binary_tree_t *node;
	struct queue_s *next;
} queue_t;

/* basic functions for queue */
/*queue_t *enqueue(queue_t **head, const binary_tree_t *node);
  binary_tree_t *dequeue(queue_t **head);*/

/*for printing purposes*/
void binary_tree_print(const binary_tree_t *root);

/*question 0*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

/*question 1*/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);

/*question 2*/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);

/*question 3*/
void binary_tree_delete(binary_tree_t *tree);

/*question 4*/
int binary_tree_is_leaf(const binary_tree_t *node);

/*question 5*/
int binary_tree_is_root(const binary_tree_t *node);

/*question 6*/
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));

/*question 7*/
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));

/*question 8*/
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));

/*question 9*/
size_t binary_tree_height(const binary_tree_t *tree);

/*question 10*/
size_t binary_tree_depth(const binary_tree_t *node);

/*question 11*/
size_t binary_tree_size(const binary_tree_t *tree);

/*question 12*/
size_t binary_tree_leaves(const binary_tree_t *tree);

/*question 13*/
size_t binary_tree_nodes(const binary_tree_t *tree);

/*question 14*/
int binary_tree_balance(const binary_tree_t *tree);

/*question 15*/
int binary_tree_is_full(const binary_tree_t *tree);

/*question 16*/
int binary_tree_is_perfect(const binary_tree_t *tree);

/*question 17*/
binary_tree_t *binary_tree_sibling(binary_tree_t *node);

/*question 18*/
binary_tree_t *binary_tree_uncle(binary_tree_t *node);

/*question 19 or 100*/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second);

/*question 20, file 101*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));

/*question 21, file 102*/
int binary_tree_is_complete(const binary_tree_t *tree);

/*question 22, file 103 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);

/* question 23, file 104 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);

/*question 24, file 105*/
int binary_tree_is_bst(const binary_tree_t *tree);

/*question 25, file 111 */
bst_t *bst_insert(bst_t **tree, int value);

/*question 26, file 112 */
bst_t *array_to_bst(int *array, size_t size);

/*question 27, file 113 */
bst_t *bst_search(const bst_t *tree, int value);

/*question 28, file 114 */
bst_t *bst_remove(bst_t *root, int value);

/*question 30, file 120 */
int binary_tree_is_avl(const binary_tree_t *tree);

/*question 31, file 121 */
avl_t *avl_insert(avl_t **tree, int value);

/*question 32, file 122 */
avl_t *array_to_avl(int *array, size_t size);

/*question 33, file 123 */
avl_t *avl_remove(avl_t *root, int value);

/*question 34, file 124 */
avl_t *sorted_array_to_avl(int *array, size_t size);

/*question 36, file 130 */
int binary_tree_is_heap(const binary_tree_t *tree);

/*question 37, file 131 */
heap_t *heap_insert(heap_t **root, int value);

/*question 38, file 132 */
heap_t *array_to_heap(int *array, size_t size);

/*question 39, file 133 */
int heap_extract(heap_t **root);

/*question 40, file 134 */
int *heap_to_sorted_array(heap_t *heap, size_t *size);

#endif
