//	William Sullivan
//
//	From: https://leetcode.com/problems/middle-of-the-linked-list/description/
//
//	Given a non-empty, singly linked list with head node head, return a 
//	middle node of linked list.
//
//	If there are two middle nodes, return the second middle node.
//
//	Example:
//
//	Input: [1, 2, 3, 4, 5]
//	Output : Node 3 from this list(Serialization : [3, 4, 5])
//	The returned node has value 3.  (The judge's serialization of this node is [3,4,5]).
//	Note that we returned a ListNode object ans, such that :
//	ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, and ans.next.next.next = NULL.
//
//	Note:
//	The number of nodes in the given list will be between 1 and 100

#include <iostream>
#include <vector>
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
	ListNode* middleNode(ListNode* head) 
	{
		// Create two pointers.
		ListNode* p_fast = head;
		ListNode* p_slow = head;

		// Starting from the head, move the fast pointer through
		// the list twice as fast as the slow pointer.
		while (true)
		{
			// Check if fast pointer is at the end of the list
			if (p_fast == NULL || p_fast->next == NULL)
			{
				// Return the slow pointer
				return p_slow;
			}

			// Increment slow pointer by one
			p_slow = p_slow->next;

			// Increment fast pointer by two
			p_fast = p_fast->next->next;
		}
	}
};

ListNode* createList(vector<int> vals)
{
	// check if the vector of vals is empty
	if (vals.size() == 0)
	{
		return NULL;
	}

	ListNode* p_head = new ListNode(vals[0]);
	ListNode* p_node = p_head;

	for (unsigned int i = 1; i < vals.size(); i++)
	{
		p_node->next = new ListNode(vals[i]);
		p_node = p_node->next;
	}

	return p_head;
}


// Deletes a singly linked list
void deleteList(ListNode* head)
{
	ListNode* p_node = head->next;

	// Delete all the nodes except head.
	while (p_node != NULL)
	{
		head->next = p_node->next;
		delete p_node;
		p_node = head->next;
	}
	// Delete head
	delete head;
}


// Uses std::cout to output the values of a singly linked list of integers
void showList(ListNode* head)
{
	cout << "[ " << flush;
	for (ListNode* p_node = head; p_node != NULL; p_node = p_node->next)
	{
		cout << p_node->val << " " << flush;
	}
	cout << "]" << flush;
}

int main()
{
	Solution solution;
	vector<int> input = {1, 2, 3, 4, 5, 6};
	ListNode* input_list = createList(input);

	cout << "Input: " << flush;
	showList(input_list);
	cout << endl;
	
	ListNode* middle_point = solution.middleNode(input_list);

	cout << "Output: Node " << middle_point->val << " from this list(Serialization : " << flush;
	showList(middle_point);
	cout << ")" << endl;

	deleteList(input_list);
	return 0;
}