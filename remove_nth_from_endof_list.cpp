//	William Sullivan
//
// From: https://leetcode.com/explore/learn/card/linked-list/214/two-pointer-technique/1296/
// Given a linked list, remove the n - th node from the end of list and return its head.

#include <iostream>
using namespace std;

//* Definition for singly-linked list.
struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
	ListNode* removeNthFromEnd(ListNode* head, int n)
	{
		// case: n is 0 or less; Do nothing.
		if (n <= 0)
		{
			return head;
		}

		ListNode * node_pointer;

		// find length
		int list_length = 0;
		for (node_pointer = head; node_pointer != NULL; node_pointer = node_pointer->next)
		{
			list_length++;
		}

		// case: n is > length; Do nothing.
		if (n > list_length)
		{
			return head;
		}

		// case: n is length; Remove first node.
		if (n == list_length)
		{
			node_pointer = head->next;
			delete head;
			return node_pointer;
		}
		// case: n > 0 AND n < length.
		else
		{
			ListNode* previous_node = head;
			node_pointer = head->next;

			// move the node pointer to the list item to be deleted. previous will follow
			for (int i = 1; i < list_length - n; i++)
			{
				previous_node = node_pointer;
				node_pointer = node_pointer->next;
			}
			// delete the node.
			previous_node->next = node_pointer->next;
			delete node_pointer;

			// return head
			return head;
		}
	}

	void show(ListNode* head)
	{
		cout << "[ " << flush;
		for (ListNode* point = head; head != NULL; head = head->next)
		{
			cout << head->val << " " << flush;
		}
		cout << "]" << endl;
	}
};

int main()
{
	Solution solution;
	ListNode* input_head = new ListNode(1);

	input_head->next = new ListNode(2);
	input_head->next->next = new ListNode(3);
	input_head->next->next->next = new ListNode(4);
	input_head->next->next->next->next = new ListNode(5);

	cout << "Starting List:" << endl;
	solution.show(input_head);

	cout << "Removing the 2nd from the end, results in: " << endl;
	input_head = solution.removeNthFromEnd(input_head, 1);
	solution.show(input_head);

	return 0;
}