#include "binary_trees.h"

/**
 * binary_tree_inorder - Traverses a tree inorder
 *
 * @tree: The tree to be traversed
 * @func: The function to be used
 *
 * Return: 1 or 0
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	binary_tree_inorder(tree->left, func);
	printf("%d\n", tree->n);
	binary_tree_inorder(tree->right, func);
}
