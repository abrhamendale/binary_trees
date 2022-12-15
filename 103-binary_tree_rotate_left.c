#include "binary_trees.h"
/**
 * binary_tree_rotate_left - Rotates a tree root to the left
 *
 * @tree: Root of the tree
 *
 * Return: Pointer to the node
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *parser;

	parser = tree->right;
	tree->parent = parser;
	tree->right = parser->left;
	if (parser->left)
		parser->left->parent = tree;
	parser->parent = NULL;
	parser->left = tree;
	tree = parser;
	return (parser);
}
