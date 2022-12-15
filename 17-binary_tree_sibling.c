#include "binary_trees.h"

/**
 * binary_tree_sibling - Inserts a left node
 *
 * @node: The node to be checked
 *
 * Return: 1 or 0
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);
	if (node->parent->left == node)
		return (node->parent->right);
	else
		return (node->parent->left);
}
