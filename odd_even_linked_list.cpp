//	William Sullivan
// From: https://leetcode.com/explore/learn/card/linked-list/219/classic-problems/1208/
//
//  Given a singly linked list, group all odd nodes together followed by the even nodes. 
//	Please note here we are talking about the node number and not the value in the nodes.
//
//	You should try to do it in place.The program should run in O(1) 
//  space complexity and O(nodes) time complexity.
//
//	Example:
//
//	Input: 2->1->3->5->6->4->7->NULL
//	Output : 2->3->6->7->1->5->4->NULL
//
//	Note:
//
//	The relative order inside both the even and odd groups should remain as it was in the input.
//	The first node is considered odd, the second node even and so on ..

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
	ListNode* oddEvenList(ListNode* head) 
	{
		// Case: List is zero or one item in length
		if (head == NULL || head->next == NULL)
		{
			return head;
		}

		// Case: More than one item.
		ListNode* p_odd = head;
		ListNode* p_even = head->next;
		ListNode* p_temp;

		// While not the end of the list
		while (p_even != NULL && p_even->next != NULL)
		{
			// Swap
			p_temp = p_even->next;
			p_even->next = p_even->next->next;

			p_temp->next = p_odd->next;
			p_odd->next = p_temp;

			// Increment pointers
			p_odd = p_odd->next;
			p_even = p_even->next;
		}

		return head;
	}
};

ListNode * createList(vector<int> nums)
{
	ListNode * newListHead = new ListNode(nums[0]);
	ListNode * p_node = newListHead;

	for (unsigned int i = 1; i < nums.size(); i++)
	{
		p_node->next = new ListNode(nums[i]);
		p_node = p_node->next;
	}
	return newListHead;
}

void showList(ListNode * list)
{
	cout << "[ " << flush;
	for (ListNode* i = list; i != NULL; i = i->next)
	{
		cout << i->val << " " << flush;
	}
	cout << "]" << endl;
}

int main()
{
	Solution solution;

	//	Input: 2->1->3->5->6->4->7->NULL
	vector<int> input = { 2,1,3,5,6,4,7 };
	ListNode * myList = createList(input);

	showList(myList);
	myList = solution.oddEvenList(myList);
	showList(myList);

	return 0;
}