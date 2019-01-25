//	William Sullivan
//	From: https://leetcode.com/problems/next-greater-element-i/
//
//	You are given two arrays(without duplicates) nums1 and nums2 where nums1’s
//	elements are subset of nums2.Find all the next greater numbers for nums1's
//	elements in the corresponding places of nums2.
//
//	The Next Greater Number of a number x in nums1 is the first greater number
//	to its right in nums2.If it does not exist, output - 1 for this number.
//
//	Example 1:
//	Input: nums1 = [4, 1, 2], nums2 = [1, 3, 4, 2].
//	Output : [-1, 3, -1]
//
//	Explanation :
//	For number 4 in the first array, you cannot find the next greater number for
//	it in the second array, so output - 1.
//	For number 1 in the first array, the next greater number for it in the second
//	array is 3.
//	For number 2 in the first array, there is no next greater number for it in
//	the second array, so output - 1.
//
//	Example 2 :
//	Input : nums1 = [2, 4], nums2 = [1, 2, 3, 4].
//	Output : [3, -1]
//
//	Explanation :
//	For number 2 in the first array, the next greater number for it in the second
//	array is 3.
//	For number 4 in the first array, there is no next greater number for it in the
//	second array, so output - 1.

#include <iostream>
#include <vector>

class Solution 
{
public:
	std::vector<int> nextGreaterElement(std::vector<int>& findNums, std::vector<int>& nums) 
	{
		std::vector<int> result = {};

		// For each value in findNums vector
		for (unsigned int i = 0; i < findNums.size(); i++)
		{
			// Find the value in nums vector
			unsigned int j = 0;
			while (nums[j] != findNums[i])
			{
				j++;
			}

			// Increase iterator until a greater value is found.
			int greater_index = -1;
			while (j < nums.size() && greater_index < 0)
			{
				if (nums[j] > findNums[i])
				{
					greater_index = j;
				}
				j++;
			}
			// If greater value is found, 
			// place the value on the end of the results vector.
			if (greater_index >= 0)
			{
				result.emplace_back(nums[greater_index]);
			}
			// If no greater value is found, place -1
			else
			{
				result.emplace_back(-1);
			}
		}
		return result;
	}
};

void showVector(std::vector<int> nums);

int main()
{
	Solution solution;
	std::vector<int> nums1 = { 2, 4 };
	std::vector<int> nums2 = { 1, 2, 3, 4 };

	std::cout << "nums1 = " << std::flush;
	showVector(nums1);
	std::cout << ",  nums2 = " << std::flush;
	showVector(nums2);
	std::cout << std::endl;

	std::vector<int> result = solution.nextGreaterElement(nums1, nums2);

	std::cout << "result = " << std::flush;
	showVector(result);
	std::cout << std::endl;

	return 0;
}

void showVector(std::vector<int> nums)
{
	std::cout << "{ " << std::flush;
	for (unsigned int i = 0; i < nums.size(); i++)
	{
		std::cout << nums[i] << " " << std::flush;
	}
	std::cout << "}" << std::flush;
}