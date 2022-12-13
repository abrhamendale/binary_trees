#include "binary_trees.h"

/**
 * binary_tree_is_root - Checks if node is root
 *
 * @node: The node to be checked
 *
 * Return: 1 or 0
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node->parent || node == NULL)
		return (0);
	else
		return (1);
}
