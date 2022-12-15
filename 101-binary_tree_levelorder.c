#include "binary_trees.h"

/**
 * tree_height - Iterates to calculate the tree height
 *
 * @tree: The tree
 * @max: The maximum height
 * @i: Iteration variable
 *
 * Return:
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
	else
	{
		max = tree_height(tree->left, &max, i);
		max = tree_height(tree->right, &max, i);
	}
	return (max);
}

/**
 * check_height - checks if height levels are equal
 *
 * @tree: Pointer to the node of a tree
 * @max: Pointer to the max value
 * @i: Pointer to an iterator value
 *
 * Return: 0 or 1
 */
int check_height(binary_tree_t *tree, void (*func)(int), int *level, int *i)
{
        int c = 0;

	if (tree == NULL)
		return (0);
	(*i)++;
	if (*i == *level)
		func(tree->n);
	if (*i <= *level)
		c = check_height(tree->left, func, level, i);
	if (tree->left != NULL)
		(*i)--;
	if (*i <= *level)
		c = check_height(tree->right, func, level, i);
	if (tree->right != NULL)
		(*i)--;
	return (c);
}
/**
 * binary_tree_levelorder - Calculates the number of nodes with at least one child
 *
 * @tree: The root of a tree
 *
 * Return: The number of nodes with at least one child
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int level = 1, i = 0, j = 0;

	if (tree == NULL || func == NULL)
		return;
	func(tree->n);
	level = binary_tree_height(tree);
	for (j = 1 ; j <= level ; j++)
	{
		check_height(tree->left, func, &j, &i);
		if (tree->left != NULL)
			i--;
		check_height(tree->right, func, &j, &i);
		if (tree->right != NULL)
			i--;
	}
}
