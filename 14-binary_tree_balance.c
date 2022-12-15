#include "binary_trees.h"

/**
 * tree_height - Iterates to calculate the tree height
 *
 * @tree: The tree
 * @max: The maximum height
 * @i: Iteration variable
 *
 * Return: 0 or 1
 */
int tree_height(const binary_tree_t *tree, int *max, int i)
{
	if (tree == NULL)
		return (*max);
	i++;
	*max = tree_height(tree->left, max, i);
	*max = tree_height(tree->right, max, i);
	if (i > *max)
		*max = i;
	return (*max);
}
/**
 * binary_tree_balance - Calculates the height of a tree
 *
 * @tree: Pointer to a tree
 *
 * Return: 0 or 1
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int right_height = 0, left_height = 0, max = 0, i = 0;

	if (tree == NULL)
		return (0);
	left_height = tree_height(tree->left, &max, i);
	max = 0;
	right_height = tree_height(tree->right, &max, i);
	return (left_height - right_height);
}
