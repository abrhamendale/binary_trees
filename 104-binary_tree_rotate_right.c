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
	if (parser->right)
		parser->right->parent = tree;
	parser->parent = NULL;
	parser->right = tree;
	tree = parser;
	return (parser);
}
