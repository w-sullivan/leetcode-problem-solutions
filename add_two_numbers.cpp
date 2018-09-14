//	William Sullivan
//
//	From: https://leetcode.com/problems/add-two-numbers/description/
//
//	You are given two non - empty linked lists representing two non - negative integers.
//	The digits are stored in reverse order and each of their nodes contain a single digit.
//	Add the two numbers and return it as a linked list.
//
//	You may assume the two numbers do not contain any leading zero, except the number 0 
//	itself.
//
//	Example:
//
//	Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//	Output : 7 -> 0 -> 8
//	Explanation : 342 + 465 = 807.

#include <iostream>


 struct ListNode 
 {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
 };


class Solution 
{
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
	{
		ListNode* result = new ListNode(0);
		ListNode* index_r = result;
		ListNode* index_1 = l1;
		ListNode* index_2 = l2;

		int carry = 0;

		while (index_1 != nullptr || index_2 != nullptr)
		{

			// If list 1 reached the end
			if (index_1 == nullptr)
			{
				index_r->next = new ListNode((index_2->val + carry) % 10);
				carry = (index_2->val + carry) / 10;

				// Increment indices
				index_2 = index_2->next;
				index_r = index_r->next;
			}
			// If list 2 reached the end
			else if (index_2 == nullptr)
			{
				index_r->next = new ListNode((index_1->val + carry) % 10);
				carry = (index_1->val + carry) / 10;

				// Increment indices
				index_1 = index_1->next;
				index_r = index_r->next;
			}
			// Otherwise
			else
			{
				index_r->next = new ListNode((index_1->val + index_2->val + carry) % 10);
				carry = (index_1->val + index_2->val + carry) / 10;

				// Increment indices
				index_1 = index_1->next;
				index_2 = index_2->next;
				index_r = index_r->next;
			}
		}

		if (carry)
			index_r->next = new ListNode(carry);

		return result->next;
	}
};

void showList(ListNode* myList);
void deleteList(ListNode* myList);

int main()
{
	Solution solution;

	ListNode* num1 = new ListNode(2);
	num1->next = new ListNode(4);
	num1->next->next = new ListNode(3);

	ListNode* num2 = new ListNode(5);
	num2->next = new ListNode(6);
	num2->next->next = new ListNode(4);

	showList(num1);
	showList(num2);

	ListNode* result = solution.addTwoNumbers(num1, num2);

	showList(result);

	deleteList(num1);
	deleteList(num2);
	deleteList(result);

	return 0;
}


void showList(ListNode* myList)
{
	ListNode* i = myList;

	std::cout << "[ " << std::flush;
	while (i != nullptr)
	{
		std::cout << i->val << " " << std::flush;
		i = i->next;
	}
	std::cout << "]" << std::endl;
}

void deleteList(ListNode* myList)
{
	ListNode* i;

	while (myList != nullptr)
	{
		i = myList;
		myList = myList->next;
		delete i;
	}
}