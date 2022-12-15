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
 * power - Calculates the power of to numbers
 *
 * @a: First number
 * @b: Second number
 *
 * Return: The power of a raised to b
 */
int power(int a, int b)
{
	int power = 1, i;  
	
	for (i = 1 ; i <= b ; ++i)
	{  
		power = power * a;
	}  
	return (power);  
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
int check_height(binary_tree_t *tree, int *count, int *level, int *i, int *c)
{
	if (tree == NULL)
	{
		if (*i + 1 == *level && *c != 2)
			*c = 1;
		return (*count);
	}
	(*i)++;
	if (*i == *level)
	{
		printf("Count:%dLevel:%di:%dc:%dn:%d\n", *count, *level, *i, *c, tree->n);
		if (*c == 1)
			*c = 2;
		(*count)++;
	}
	if (*i < *level)
	{
		*count = check_height(tree->left, count, level, i, c);
		if (tree->left != NULL)
			(*i)--;
		*count = check_height(tree->right, count, level, i, c);
		if (tree->right != NULL)
			(*i)--;
	}
	return (*count);
}
/**
 * binary_tree_is_complete - Calculates the number of nodes with at least one child
 *
 * @tree: The root of a tree
 *
 * Return: 0 or 1
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int level = 1, i = 0, j = 0, count = 0, c = 0;

	if (tree == NULL)
		return (1);
	level = binary_tree_height(tree);
	printf("Height:%d\n", level);
	for (j = 1 ; j <= level ; j++)
	{
		count = check_height(tree->left, &count, &j, &i, &c);
		if (tree->left != NULL)
			i--;
		count = check_height(tree->right, &count, &j, &i, &c);
		if (tree->right != NULL)
			i--;
		printf("Count:%dc:%d\n", count, c);
		if (count != power(2, j) && c == 2)
			return (0);
		count = 0;
		c = 0;
		i = 0;
	}
	return (1);
}
