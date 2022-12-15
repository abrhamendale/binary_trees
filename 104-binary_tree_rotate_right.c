#include "binary_trees.h"
/**
 * binary_tree_rotate_left - Rotates a tree root to the left
 *
 * @tree: Root of the tree
 *
 * RETURN 0
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *parser;
      
	parser = tree->left;
	tree->parent = parser;
	tree->left = parser->right;
	parser->parent = NULL;
	tree = parser;
	/*
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
	*/
	return (parser);
}
