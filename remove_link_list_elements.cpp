//	William Sullivan
//
// From: https://leetcode.com/explore/learn/card/linked-list/219/classic-problems/1207/
//	Remove all elements from a linked list of integers that have value val.
//
//	Example:
//
//	Input:  1->2->6->3->4->5->6, val = 6
//	Output : 1->2->3->4->5

#include <iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void showList(ListNode * head)
{
	if (head == NULL)
	{
		cout << "NULL" << endl;
	}
	else
	{
		cout << "[ " << flush;
		for (ListNode* p = head; p != NULL; p = p->next)
		{
			cout << p->val << " " << flush;
		}
		cout << "]" << endl;
	}
}

class Solution 
{
public:
	ListNode* removeElements(ListNode* head, int val) 
	{
		// If list is empty, return empty list
		if (head == NULL)
		{
			return head;
		}

		// Pointers
		ListNode * p_node;
		ListNode * p_previous = head;

		//Case: First Element
		// Check the first node.
		// Delete the first node, while it matches the val
		while (p_previous != NULL && p_previous->val == val)
		{
			// Move pointers
			p_previous = p_previous->next;
			delete head;
			head = p_previous;
		}
		// If we deleted everything return the empty list.
		if (p_previous == NULL)
		{
			return NULL;
		}

		// Otherwise go through the list and remove the element with matching val
		p_node = p_previous->next;
		while (p_node != NULL)
		{
			// If the list node value is equal to the val, delete it.
			if (p_node->val == val)
			{
				p_previous->next = p_node->next;
				delete p_node;
				p_node = p_previous->next;
			}
			// Otherwise, increment pointers
			else
			{
				p_previous = p_node;
				p_node = p_node->next;
			}
		}

		return head;
	}
};

ListNode* deleteList(ListNode * head)
{
	ListNode* p = head;
	ListNode* n = head->next;

	while (n != NULL)
	{
		delete p;
		p = n;
		n = n->next;
	}
	delete p;
	return NULL;
}

int main()
{
	Solution solution;
	ListNode * input = new ListNode(6);
	input->next = new ListNode(6);
	input->next->next = new ListNode(6);
	input->next->next->next = new ListNode(6);
	input->next->next->next->next = new ListNode(6);
	input->next->next->next->next->next = new ListNode(6);

	showList(input);
	cout << "------------" << endl;
	input = solution.removeElements(input, 6);
	showList(input);


	deleteList(input);
	return 0;
}