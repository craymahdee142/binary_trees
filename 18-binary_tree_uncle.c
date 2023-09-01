#include "binary_trees.h"
/**
 *binary_tree_uncle - Finds the sibling of a binary node
 *@node: Pointer to the node of the uncle
 *Return: NULL, if node is NULL or no uncle, else pointer to a sibling
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);
	if (node->parent == node->parent->parent->left)
		return (node->parent->parent->right);
	return (node->parent->parent->right);
}
