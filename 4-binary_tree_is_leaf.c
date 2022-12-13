#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Inserts a left node
 *
 * @node: The node to be checked
 *
 * Return: 1 or 0
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node->left || node->right || node == NULL)
		return (0);
	else
		return (1);
}
