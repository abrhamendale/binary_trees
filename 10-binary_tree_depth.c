#include "binary_trees.h"

/**
 * binary_tree_depth - Calculates the depth of a binary tree node
 *
 * @tree: The node of a tree
 *
 * Return: 1 or 0
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;
	binary_tree_t *parser;

	parser = (binary_tree_t *)tree;
	if (tree == NULL)
		return (0);
	else
	{
		while (parser->parent)
		{
			parser = parser->parent;
			depth++;
		}
		return (depth);
	}
}
