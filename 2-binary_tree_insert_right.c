#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a left node
 *
 * @parent: The parent to insert a left node
 * @value: The value of the left node
 *
 * Return: Pointer to the inserted node
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *parse;

	parse = malloc(sizeof(binary_tree_t));
	if (parse == NULL)
		return (NULL);
	if (parent == NULL)
		return (NULL);
	if (value > parent->n)
	{
		parse->n = value;
		if (parent->right)
		{
			parse->right = parent->right;
			parse->left = NULL;
			parent->right->parent = parse;
			parent->right = parse;
			parse->parent = parent;
			parse->n = value;
		}
		else
		{
			parse->n = value;
			parse->parent = parent;
			parent->right = parse;
			parse->left = NULL;
			parse->right = NULL;
		}
		return (parse);
	}
	else
		return (NULL);
}
