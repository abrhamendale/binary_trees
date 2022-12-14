#include "binary_trees.h"
/**
 * tree_check - Helper function to calculate tree size
 *
 * @s: Size iterator
 *
 * Returns: Size
 */
int tree_check(const binary_tree_t *tree)
{
	int c = 0;

	if (tree == NULL)
		return (1);
	if ((tree->left != NULL && tree->right == NULL) || (tree->right != NULL && tree->left == NULL))
		return (0);
	c = tree_check(tree->left);
	c = tree_check(tree->right);
	return (c);
}

/**
 * binary_tree_is_full - calculates the size of a binary tree
 *
 * @tree: The tree
 *
 * Return: 1 or 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int c = 0;

	if (tree == NULL)
		return (1);
	if ((tree->left != NULL && tree->right == NULL) || (tree->right != NULL && tree->left == NULL))
		return (0);
	else
	{
		c = tree_check(tree->left);
		c = tree_check(tree->right);
	}
	return (c);
}
