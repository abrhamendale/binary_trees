#include "binary_trees.h"

/**
 * binary_tree_delete - Deletes a binary tree
 *
 * @tree: A pointer to a tree
 *
 * Return: Nothing
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return;
	binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);
	free(tree);
}
/*
	if (value < parent->n)
	{
		parse->n = value;
		if (parent->left)
		{
			parse->left = parent->left;
			parse->right = NULL;
			parent->left->parent = parse;
			parent->left = parse;
			parse->parent = parent;
			parse->n = value;
		}
		else
		{
			parse->n = value;
			parse->parent = parent;
			parent->left = parse;
			parse->right = NULL;
			parse->left = NULL;
		}
		return (parse);
	}
	else
		return (NULL);
}
*/
