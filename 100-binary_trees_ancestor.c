#include "binary_trees.h"

/**
 * binary_trees_ancestor - Searches for the lowest common ancestor
 *
 * @first: The first node
 * @second: The second node
 *
 * Return: Popinter to the lowest common ancestor
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first
		, const binary_tree_t *second)
{
	binary_tree_t *parser1, *parser2;

	if (first == NULL || second == NULL)
		return (NULL);
	parser1 = (binary_tree_t *)first;
	parser2 = (binary_tree_t *)second;
	while (parser1 != NULL)
	{
		while (parser2 != NULL)
		{
			if (parser1 == parser2)
				return (parser1);
			parser2 = parser2->parent;
		}
		parser2 = (binary_tree_t *)second;
		parser1 = parser1->parent;
	}
	return (NULL);
}
