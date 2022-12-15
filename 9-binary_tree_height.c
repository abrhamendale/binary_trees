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
 * binary_tree_height - Calculates the height of a tree
 *
 * @tree: Pointer to a tree
 *
 * Return: 1 or 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	int max = 0, i = 0;

	if (tree == NULL)
		return (0);
	max = tree_height(tree->left, &max, i);
	max = tree_height(tree->right, &max, i);
	return (max);
}
