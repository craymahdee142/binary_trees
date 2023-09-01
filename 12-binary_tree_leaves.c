#include "binary_trees.h"

/**
 *binary_tree_leaves - Counts the leaves in the binary tree
 *@tree: A pointer to the root node of the tree to traverse.
 *Return: the number of leaves
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves = 0;

	if (tree != NULL)
	{
		leaves += (!tree->left && !tree->right) ? 1 : 0;
		leaves += binary_tree_leaves(tree->left);
		leaves += binary_tree_leaves(tree->right);
	}
	return (leaves);
}
