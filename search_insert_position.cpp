//	William Sullivan
//	From: https://leetcode.com/problems/search-insert-position/
//
//	Given a sorted array and a target value, return the index if the target is found.
//	If not, return the index where it would be if it were inserted in order.
//
//	You may assume no duplicates in the array.
//
//	Example 1:
//	Input: [1, 3, 5, 6], 5
//	Output : 2
//
//	Example 2 :
//	Input : [1, 3, 5, 6], 2
//	Output : 1
//
//	Example 3 :
//	Input : [1, 3, 5, 6], 7
//	Output : 4
//
//	Example 4 :
//	Input : [1, 3, 5, 6], 0
//	Output : 0

#include <iostream>
#include <vector>

class Solution 
{
public:
	int searchInsert(std::vector<int>& nums, int target) 
	{
		if(nums.size() == 0)
			return 0;

		int result = recurse_search(nums, target, 0, nums.size() - 1);
		return result;
	}

private:
	int recurse_search(std::vector<int>& nums, int target, int left, int right)
	{
		int mid = (left + right + 1) / 2;

		// If middle is equal to target num, return mid index.
		if (nums[mid] == target)
			return mid;

		// If target not found, find where it should be.
		if (left == right)
		{
			if (target < nums[left])
			{
				// Case: Beginning of the array
				if (left == 0)
				{
					// Target should be at the beginning
					return 0;
				}
				// Otherwise, index should be at in front.
				return left - 1;
			}

			if (target > nums[left])
			{
				// Target should be to the right
				return left + 1;
			}
		}

		// Otherwise search again in subset that may contain it.
		if (target > nums[mid])
			return recurse_search(nums, target, mid, right);
		else
			return recurse_search(nums, target, left, mid - 1);
	}
};

void show_vector(std::vector<int> nums);

int main()
{
	Solution solution;
	std::vector<int> input = { 1, 3 };
	int num = 4;

	int result = solution.searchInsert(input, num);
	
	show_vector(input);
	std::cout << "Index of value " << num << ": " << result << std::endl;

	return 0;
}

void show_vector(std::vector<int> nums)
{
	std::cout << "{ " << std::flush;
	for (unsigned int i = 0; i < nums.size(); i++)
	{
		std::cout << nums[i] << " " << std::flush;
	}
	std::cout << "}" << std::endl;
}