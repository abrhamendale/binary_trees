#include "binary_trees.h"

/**
 * binary_tree_preorder - Traverses a tree in pre-order
 *
 * @tree: The tree to be traversed
 * @func: The function to be used
 *
 * Return: 1 or 0
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	else
	{
		if (tree->parent == NULL)
			printf("%d\n", tree->n);
		if (tree->left)
			printf("%d\n", tree->left->n);
		binary_tree_preorder(tree->left, func);
		if (tree->right)
			printf("%d\n", tree->right->n);
		binary_tree_preorder(tree->right, func);
	}
}
