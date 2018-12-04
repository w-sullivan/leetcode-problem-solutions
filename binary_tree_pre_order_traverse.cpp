//  William Sullivan
//	From: https://leetcode.com/problems/binary-tree-preorder-traversal/
//
//	Given a binary tree, return the preorder traversal of its nodes' values.
//
//	Example:
//	Input: [1, null, 2, 3]
//		1
//		 \
//		  2
//		 /
//		3
//
//	Output: [1, 2, 3]
//	Follow up : Recursive solution is trivial, could you do it iteratively ?


#include <iostream>
#include <vector>
#include <stack>


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
	std::vector<int> preorderTraversal(TreeNode* root) 
	{
		std::vector<int> result = {};

		if (root == nullptr)
			return result;

		std::stack<TreeNode*> myStack;
		myStack.push(root);

		TreeNode* current_node;

		while (!myStack.empty())
		{
			// Add top of stack to result.
			current_node = myStack.top();
			myStack.pop();
			result.push_back(current_node->val);

			// Push the child nodes (if they exist). Right first.
			if (current_node->right != nullptr)
				myStack.push(current_node->right);
			if (current_node->left != nullptr)
				myStack.push(current_node->left);
		}

		return result;
	}

private:
	// Recursive Version
	void recursivePreorderTraversal(TreeNode* root, std::vector<int> *result)
	{
		if (root == nullptr)
			return;

		result->push_back(root->val);
		recursivePreorderTraversal(root->left, result);
		recursivePreorderTraversal(root->right, result);
	}

};


void print_vector(std::vector<int> values);


int main()
{
	Solution solution;

	TreeNode* input = new TreeNode(1);
	input->right = new TreeNode(2);
	input->right->left = new TreeNode(3);

	std::vector<int> result = solution.preorderTraversal(input);

	std::cout << "PreOrder Traversal:" << std::endl;
	print_vector(result);

	return 0;
}


void print_vector(std::vector<int> values)
{
	std::cout << "[ " << std::flush;
	for (unsigned int i = 0; i < values.size(); i++)
	{
		std::cout << values[i] << " " << std::flush;
	}
	std::cout << "]" << std::endl;
}