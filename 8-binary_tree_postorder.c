#include "binary_trees.h"

/**
 * binary_tree_postorder - Traverses a tree in postorder
 *
 * @tree: The tree to be traversed
 * @func: The function to be used
 *
 * Return: 1 or 0
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	printf("%d\n", tree->n);
}
