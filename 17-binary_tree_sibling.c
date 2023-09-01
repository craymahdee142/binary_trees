#include "binary_trees.h"
/**
 *binary_tree_sibling - Finds the sibling of a binary node
 *@node: Pointer to the node of the sibling
 *Return: NULL, if node is NULL or no sibling, else pointer to a sibling
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);
	if (node == node->parent->left)
		return (node->parent->right);
	return (node->parent->right);
}
