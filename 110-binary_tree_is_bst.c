#include "binary_trees.h"

/**
 * check_height - checks if height levels are equal
 *
 * @tree: Pointer to the node of a tree
 * @node: Pointer to the max value
 * @i: Pointer to an iterator value
 *
 * Return: 0 or 1
 */
int check_height(binary_tree_t *tree, binary_tree_t *node, int *i)
{
	int c = 1;

	if (tree == NULL)
		return (c);
	if (*i == 0 && tree != node)
	{
		if (node->n < tree->n)
			return (0);
	}
	if (*i == 1 && tree != node)
	{
		if (node->n > tree->n)
			return (0);
	}
	c = check_height(tree->left, node, i);
	if (c == 0)
		return (0);
	if (tree == node)
		*i = 1;
	c = check_height(tree->right, node, i);
	if (c == 0)
		return (0);
	return (c);
}
/**
 * check_node - Checks if every node of a tree is as bst
 *
 * @tree: Root of a tree
 * @node: Node to be compared
 *
 * Return: 0 or 1
 */
int check_node(binary_tree_t *tree, binary_tree_t *node)
{
	int i = 0, c = 1;

	if (tree == NULL)
		return (1);
	c = check_height(tree, node, &i);
	if (c == 1)
	{
		c = check_node(node->left, node->left);
		c = check_node(node->right, node->right);
	}
	i = 0;
	return (c);
}

/**
 * binary_tree_is_bst - Calculates the number of nodes with at least one child
 *
 * @tree: The root of a tree
 *
 * Return: 0 or 1
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);
	if (check_node((binary_tree_t *)tree, (binary_tree_t *)tree))
		return (1);
	return (0);
}
