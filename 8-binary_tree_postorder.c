#include "binary_trees.h"

/**
 *binary_tree_postorder - Use postorder to go through
 *			a binary tree
 *@tree: A pointer to the root node of the tree to traverse.
 *@func: A pointer to a function to call for each node.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree != NULL && func != NULL)
	{
		binary_tree_inorder(tree->left, func);
		binary_tree_inorder(tree->right, func);
		func(tree->n);
	}
}
