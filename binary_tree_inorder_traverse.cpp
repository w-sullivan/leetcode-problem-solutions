// William Sullivan
// From: https://leetcode.com/problems/binary-tree-inorder-traversal/
//
//	Given a binary tree, return the inorder traversal of its nodes' values.
//
//	Example:
//	Input: [1, null, 2, 3]
//		1
//		 \
//		  2
//		 /
//		3
//
//	Output: [1, 3, 2]
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
	std::vector<int> inorderTraversal(TreeNode* root) 
	{
		std::vector<int> result = {};

		if (root == nullptr)
			return result;

		std::stack<TreeNode*> myStack;
		TreeNode* current_node = root;

		while (!myStack.empty() || current_node != nullptr)
		{
			// Keep going left till you reach leftmost bottom.  Pushing nodes on the stack.
			while (current_node != nullptr)
			{
				myStack.push(current_node);
				current_node = current_node->left;
			}

			// Add node to result
			current_node = myStack.top();
			myStack.pop();
			result.push_back(current_node->val);

			// Try going right
			current_node = current_node->right;
		}

		return result;
	}

private:
	// Recursive Version
	void recursiveInorderTraversal(TreeNode* root, std::vector<int> *result)
	{
		if (root == nullptr)
			return;

		recursiveInorderTraversal(root->left, result);
		result->push_back(root->val);
		recursiveInorderTraversal(root->right, result);
	}
};

void print_vector(std::vector<int> values);

int main()
{
	Solution solution;

	TreeNode* input = new TreeNode(1);
	input->right = new TreeNode(2);
	input->right->left = new TreeNode(3);

	std::vector<int> result = solution.inorderTraversal(input);

	std::cout << "Inorder Traversal:" << std::endl;
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