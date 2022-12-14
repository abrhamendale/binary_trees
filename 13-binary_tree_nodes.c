#include "binary_trees.h"
/**
 * leaf_counter - Count the number of nodes with at least one child
 *
 * @tree: The root of a tree
 * @count: Counting variable
 *
 * Return: Count
 */
size_t leaf_counter(binary_tree_t *tree, size_t count)
{
	if (tree == NULL)
		return (count);
	if (tree->left != NULL || tree->right != NULL)
		count++;
	count = leaf_counter(tree->left, count);
	count = leaf_counter(tree->right, count);
	return (count);
}
/**
 * binary_tree_nodes - Calculates the number of nodes with at least one child
 *
 * @tree: The root of a tree
 *
 * Return: The number of nodes with at least one child
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t count = 0;

	if (tree == NULL)
		return (0);
	if (tree->left != NULL || tree->right != NULL)
		count++;
	count = leaf_counter(tree->left, count);
	count = leaf_counter(tree->right, count);
	return (count);
}
