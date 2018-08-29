//	William Sullivan
//	From: https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
//
//	Given a binary tree, find its maximum depth.
//	The maximum depth is the number of nodes along the longest path from the root 
//	node down to the farthest leaf node.
//
//	Note: A leaf is a node with no children.
//
//	Example :
//
//	Given binary tree[3, 9, 20, null, null, 15, 7],
//
//		 3
//		/ \
//	   9  20
//	  / \
//	15   7
//
//	return its depth = 3.


#include <iostream>

//Definition for a binary tree node.
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution 
{
public:

	int maxDepth(TreeNode* root) 
	{
		_max_depth = 0;
		findDepth(root, 0);
		return _max_depth;

	}

private:

	int _max_depth;

	void findDepth(TreeNode* root, int depth)
	{
		if (root == nullptr)
			return;
		else
		{
			depth++;
			if (depth > _max_depth)
				_max_depth = depth;

		}

		findDepth(root->left, depth);
		findDepth(root->right, depth);
	}
};


void deleteTree(TreeNode* node);
void showTree(TreeNode* node);


int main()
{
	TreeNode* tree = new TreeNode(3);
	tree->left = new TreeNode(9);
	tree->right = new TreeNode(20);
	tree->left->left = new TreeNode(15);
	tree->left->right = new TreeNode(7);

	showTree(tree);

	Solution solution;
	int result = solution.maxDepth(tree);

	std::cout << "Max Depth: " << result << std::endl;

	deleteTree(tree);
	return 0;
}



void deleteTree(TreeNode* node)
{
	if (node == NULL)
		return;

	deleteTree(node->left);
	deleteTree(node->right);

	delete node;
}


void showTree(TreeNode* node)
{
	if (node == NULL)
		return;

	std::cout << node->val << std::endl;

	if (node->left)
		showTree(node->left);

	if (node->right)
		showTree(node->right);
}
