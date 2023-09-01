#include "binary_trees.h"
/**
 *binary_tree_insert_left - insert a node as left child of another
 *@parent: A pointer to the node to start at the left
 *@value: Value to store in the new node
 *Return: NULL if parent is NULL or error, else pointer to nre node
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
		return (NULL);
	new_node = binary_tree_node(parent, value);

	if (new_node == NULL)
		return (NULL);
	if (parent->left != NULL)
	{
		new_node->left = parent->left;
		parent->left->parent = new_node;
	}
	parent->left = new_node;

	return (new_node);
}
