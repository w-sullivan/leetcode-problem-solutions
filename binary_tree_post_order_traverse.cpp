//	William Sullivan
//	From: https://leetcode.com/problems/binary-tree-postorder-traversal/
//
//	Given a binary tree, return the postorder traversal of its nodes' values.
//
//	Example:
//	Input: [1, null, 2, 3]
//		1
//		 \
//		  2
//		 /
//		3
//
//	Output: [3, 2, 1]
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
	std::vector<int> postorderTraversal(TreeNode* root) 
	{
		std::vector<int> result = {};

		if (root == nullptr)
			return result;

		std::stack<TreeNode*> stack1;
		std::stack<TreeNode*> stack2;
		stack1.push(root);

		TreeNode* current_node = root;

		while (!stack1.empty())
		{
			// Push the top of stack1 to stack2, and pop stack1
			current_node = stack1.top();
			stack2.push(current_node);
			stack1.pop();

			// Add children of the popped node to stack1.
			if (current_node->left != nullptr)
				stack1.push(current_node->left);

			if (current_node->right != nullptr)
				stack1.push(current_node->right);
		}

		// Stack2 pop all values to result.
		while (!stack2.empty())
		{
			current_node = stack2.top();
			result.push_back(current_node->val);
			stack2.pop();
		}
		return result;
	}
private:
	// Recursive Version
	void recursivePostorderTraversal(TreeNode* root, std::vector<int> *result)
	{
		if (root == nullptr)
			return;

		recursivePostorderTraversal(root->left, result);
		recursivePostorderTraversal(root->right, result);
		result->push_back(root->val);
	}
};


void print_vector(std::vector<int> values);


int main()
{
	Solution solution;

	TreeNode* input = new TreeNode(1);
	input->right = new TreeNode(2);
	input->right->left = new TreeNode(3);

	std::vector<int> result = solution.postorderTraversal(input);

	std::cout << "Postorder Traversal:" << std::endl;
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