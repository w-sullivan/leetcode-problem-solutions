//	William Sullivan
//
//	From:  https://leetcode.com/problems/merge-two-binary-trees/description/
//
//	Given two binary trees and imagine that when you put one of them to cover the other, 
//	some nodes of the two trees are overlapped while the others are not.
//
//	You need to merge them into a new binary tree.The merge rule is that if two nodes
//	overlap, then sum node values up as the new value of the merged node.Otherwise, the 
//	NOT null node will be used as the node of new tree.


#include <iostream>
#include <iomanip>

//	Definition for a binary tree node.
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
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) 
	{
		// Base cases
		if (t1 == NULL && t2 == NULL)
		{
			return NULL;
		}
		else if (t1 == NULL && t2 != NULL)
		{
			return t2;
		}
		else if (t1 != NULL && t2 == NULL)
		{
			return t1;
		}
		//---------
		else
		{
			TreeNode* result = new TreeNode(t1->val + t2->val);

			result->left = mergeTrees(t1->left, t2->left);
			result->right = mergeTrees(t1->right, t2->right);

			return result;
		}
	}
};

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


int main()
{
//		Tree 1                     Tree 2
//			1                         2
//		   / \						 / \
//		  3   2                     1   3
//		 /							 \   \
//		5                             4   7

	TreeNode* tree1 = new TreeNode(1);
	tree1->left = new TreeNode(3);
	tree1->right = new TreeNode(2);
	tree1->left->left = new TreeNode(5);

	TreeNode* tree2 = new TreeNode(2);
	tree2->left = new TreeNode(1);
	tree2->right = new TreeNode(3);
	tree2->left->right = new TreeNode(4);
	tree2->right->right = new TreeNode(7);

	Solution solution;
	TreeNode* result;

	std::cout << "Tree 1:" << std::endl;
	showTree(tree1);

	std::cout << "Tree 2:" << std::endl;
	showTree(tree2);

	result = solution.mergeTrees(tree1, tree2);

	std::cout << "Result:" << std::endl;
	showTree(result);

	deleteTree(result);
	deleteTree(tree1);
	deleteTree(tree2);

	return 0;
}