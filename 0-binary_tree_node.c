#include "binary_trees.h"
/**
 * binary_tree_node - Creates a binary tree node
 *
 * @parent: The parent of the node to be created
 * @value: The value to be added
 *
 * Return: 0
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *parse;

	parse = malloc(sizeof(binary_tree_t));
	if (parse == NULL)
		return (NULL);
	if (parent == NULL)
	{
		parse->n = value;
		parse->left = NULL;
		parse->right = NULL;
		parse->parent = NULL;
		parent = parse;
		return (parse);
	}
	if (parent->n > value)
	{
		parent->left = parse;
		parse->n = value;
		parse->left = NULL;
		parse->right = NULL;
		parse->parent = parent;
	}
	else
	{
		parent->right = parse;
		parse->n = value;
		parse->left = NULL;
		parse->right = NULL;
		parse->parent = parent;
	}
	return (parse);
}
