//	William Sullivan
//	From: https://leetcode.com/problems/remove-duplicates-from-sorted-array
//
//
//	Given a sorted array nums, remove the duplicates in - place such that each element
//	appear only once and return the new length.
//
//	Do not allocate extra space for another array, you must do this by modifying the 
//	input array in - place with O(1) extra memory.
//
//	Example 1:
//	Given nums = [1, 1, 2],
//	Your function should return length = 2, with the first two elements of nums being
//	1 and 2 respectively
//
//	Example 2 :
//	Given nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4],
//	Your function should return length = 5, with the first five elements of nums being 
//	modified to 0, 1, 2, 3, and 4 respectively.

#include <iostream>
#include <vector>

class Solution 
{
public:
	int removeDuplicates(std::vector<int>& nums) 
	{
		int list_size = nums.size();

		if (list_size == 0 || list_size == 1)
			return list_size;

		int num1 = 0;
		int num2 = 1;

		while (num2 < list_size)
		{
			if (nums[num1] != nums[num2])
			{
				num1++;
				nums[num1] = nums[num2];
			}

			num2++;
		}

		return num1 + 1;
	}
};

void show_list(std::vector<int> nums, int size);

int main()
{
	Solution solution;
	std::vector<int> input = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
	int result;

	show_list(input, input.size());
	result = solution.removeDuplicates(input);
	std::cout << "Length of unique num list: " << result << std::endl;
	show_list(input, result);

	return 0;
}

void show_list(std::vector<int> nums, int size)
{
	std::cout << "[ " << std::flush;
	for (unsigned int i = 0; i < size; i++)
	{
		std::cout << nums[i] << " " << std::flush;
	}
	std::cout << "]" << std::endl;
}