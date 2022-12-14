#include "binary_trees.h"

/**
 * check_height - checks if height levels are equal
 *
 * @tree: Pointer to the node of a tree
 * @max: Pointer to the max value
 * @i: Pointer to an iterator value
 *
 * Return: 0 or 1
 */
int check_height(binary_tree_t *tree, int *max, int *i)
{
        int c = 0;

	if (tree == NULL)
	{
		if (*max == 0)
		{
			*max = *i;
		}
		if (*max != *i)
		{
			return (0);
		}
		return (1);
	}
	(*i)++;
	c = check_height(tree->left, max, i);
	if (c == 0)
		return (0);
	if (tree->left != NULL)
		(*i)--;
	c = check_height(tree->right, max, i);
	if (c == 0)
		return (0);
	if (tree->right != NULL)
		(*i)--;
	return (c);
}
/**
 * leaf_counter - Count the number of nodes with at least one child
 *
 * @tree: The root of a tree
 * @count: Counting variable
 *
 * Return: Count
 */
int leaf_counter(binary_tree_t *tree)
{
	int c = 0;

	if (tree == NULL)
	{
		return (1);
	}
	if ((tree->left == NULL && tree->right != NULL) || (tree->right == NULL && tree->left != NULL))
		return (0);
	c = leaf_counter(tree->left);
	if (c == 0)
		return (0);
	c = leaf_counter(tree->right);
	if (c == 0)
		return (0);
	return (c);
}
/**
 * binary_tree_is_perfect - Calculates the number of nodes with at least one child
 *
 * @tree: The root of a tree
 *
 * Return: The number of nodes with at least one child
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int c = 0, i = 0, max = 0;

	if (tree == NULL)
		return (1);
	if ((tree->left == NULL && tree->right != NULL) || (tree->right == NULL && tree->left != NULL))
		return (0);
	c = leaf_counter(tree->left);
	if (c == 0)
		return (0);
	c = leaf_counter(tree->right);
	if (c == 0)
		return (0);
	c = check_height(tree->left, &max, &i);
	if (c == 0)
		return (0);
	if (tree->left != NULL)
		i--;
	c = check_height(tree->right, &max, &i);
	if (tree->right != NULL)
		i--;
	if (c == 0)
		return (0);
	return (c);
}
