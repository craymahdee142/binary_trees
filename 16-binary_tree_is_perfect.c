#include "binary_trees.h"

unsigned char is_leaf(const binary_tree_t *node);
const binary_tree_t *get_leat(const binary_tree_t *tree);
size_t depth(const binary_tree_t *tree);
int is_perfact_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level);
int binary_tree_is_perfect(const binary_tree_t *tree);

/**
 *is_leaf - checks if node is leaf
 *@node: A pointer to a node
 *Return: if node is leaf 1, else 0
 */
unsigned char is_leaf(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}

/**
 *get_leaf - Gets a leaf of binary tree
 *@tree: A pointer to a node of the tree to find a leaf in
 *Return: returns first encountered leaf
 */
const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
	if (is_leaf(tree) == 1)
		return (tree);
	return (tree->left ? get_leaf(tree->left) : get_leaf(tree->right));
}

/**
 *depth - Returns the depth of binary tree
 *@tree: A pointer to a node of the tree to measure its depth
 *Return: depth of a node
 */
size_t depth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + depth(tree->parent) : 0);
}

/**
 *is_perfect_recursive - checks if binary tree is recursively perfect
 *@tree: A pointer to the root node of tree to check
 *@leaf_depth: binary tree of the depth of 1 leaf
 *@level: current level
 *Description: recurse through left and right leaf
 *Return: 1 if tree is perfect, else 0
 */
int is_perfact_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level)
{
	if (is_leaf(tree))
		return (level == leaf_depth ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (is_perfect_recursive(tree->left, leaf_depth, level + 1) &&
		is_perfect_recursive(tree->right, leaf_depth, level + 1));
}

/**
 *binary_tree_is_perfect - checks if binary is perfect
 *@tree: A pointer to the root node of the tree
 *Return: 0 if tree is NULL or not perfect, else 1
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_perfect_recursive(tree, depth(get_leaf(tree)), 0));
}
