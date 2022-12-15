#include "binary_trees.h"

/**
 * bst_ins - checks if height levels are equal
 *
 * @tree: Pointer to the node of a tree
 * @node: Pointer to the max value
 * @i: Pointer to an iterator value
 *
 * Return: 0 or 1
 */
bst_t *bst_ins(bst_t *tree, bst_t *node, int *i)
{
	bst_t *r;

	printf("-----------bst_ins\n");
	if (tree == NULL)
	{printf("insert:%d\n", node->n);
		node->parent = tree->parent;
		if (i == 0)
			tree->left = node;
		else
			tree->right = node;
		node->left = NULL;
		node->right = NULL;
		return (node);
	}
	else
	{
		if (tree->left && tree->n > node->n)
			r = bst_ins(tree->left, node, i);
		*i = 1;
		if (tree->right && tree->n < node->n)
			r = bst_ins(tree->right, node, i);
	}
	return (r);
}
/**
 * bst_insert - Calculates the number of nodes with at least one child
 *
 * @tree: The root of a tree
 * @value: A value to insert
 *
 * Return: Pointer to the inserted value
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *node, *t, *r;
	int i = 0;

	printf("-----------bst_insert\n");
	node = malloc(sizeof(bst_t));
	node->n = value;
	if (*tree == NULL)
	{printf("insert root:%d\n", node->n);
		tree = &node;
		return (*tree);
	}
	else
	{printf("ins\n");
		t = *tree;
		if (t->left && t->n > value)
			r = bst_ins(t->left, node, &i);
		i = 1;
		if (t->right && t->n < value)
			r = bst_ins(t->right, node, &i);
	}
	return (r);
}
