#include "binary_trees.h"
/**
 * tree_size - Helper function to calculate tree size
 *
 * @s: Size iterator
 *
 * Returns: Size
 */
size_t tree_size(const binary_tree_t *tree, size_t s)
{
	if (tree == NULL)
		return (s);
	s++;
	s = tree_size(tree->left, s);
	s = tree_size(tree->right, s);
	return (s);
}

/**
 * binary_tree_size - calculates the size of a binary tree
 *
 * @tree: The tree
 *
 * Return: 1 or 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 1;

	if (tree == NULL)
		return (0);
	else
	{
		size = tree_size(tree->left, size);
		size = tree_size(tree->right, size);
	}
	return (size);
}
