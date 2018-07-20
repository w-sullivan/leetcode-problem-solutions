//	William Sullivan
//
//	From: https://leetcode.com/explore/learn/card/linked-list/219/classic-problems/1205/
//	Reverse a singly linked list.
//
//	Example:
//
//	Input: 1->2->3->4->5->NULL
//	Output : 5->4->3->2->1->NULL
//
//	Follow up :
//	A linked list can be reversed either iteratively or recursively.Could you implement both ?

#include <iostream>
using namespace std;


//Definition for singly-linked list.
struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
public:
	ListNode* reverseList(ListNode* head)
	{
		// If 0 or 1 items in list.  Return list.
		if (head == NULL || head->next == NULL)
		{
			return head;
		}

		ListNode* node_pointer = head->next;
		ListNode* previous_pointer = head;
		
		while (node_pointer != NULL)
		{
			// Swap
			previous_pointer->next = node_pointer->next;
			node_pointer->next = head;
			head = node_pointer;

			// Move pointers
			node_pointer = previous_pointer->next;
		}
			return head;
	}
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
	ListNode * input_head = new ListNode(1);
	input_head->next = new ListNode(2);
	input_head->next->next = new ListNode(3);
	input_head->next->next->next = new ListNode(4);
	input_head->next->next->next->next = new ListNode(5);

	showList(input_head);

	input_head = solution.reverseList(input_head);
	showList(input_head);

	input_head = deleteList(input_head);

	return 0;
}