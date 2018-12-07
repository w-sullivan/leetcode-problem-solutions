//	William Sullivan
//	From: https://leetcode.com/problems/remove-element/
//
//	Given an array nums and a value val, remove all instances of that value in - place
//	and return the new length.
//
//	Do not allocate extra space for another array, you must do this by modifying the 
//	input array in - place with O(1) extra memory.
//
//	The order of elements can be changed. It doesn't matter what you leave beyond the 
//	new length.
//
//	Example 1:
//	Given nums = [3, 2, 2, 3], val = 3,
//	Your function should return length = 2, with the first two elements of nums being 2.
//	It doesn't matter what you leave beyond the returned length.
//
//	Example 2:
//	Given nums = [0, 1, 2, 2, 3, 0, 4, 2], val = 2,
//	Your function should return length = 5, with the first five elements of nums 
//	containing 0, 1, 3, 0, and 4.
//
//	Note that the order of those five elements can be arbitrary.
//	It doesn't matter what values are set beyond the returned length.

#include <iostream>
#include <vector>

class Solution 
{
public:
	int removeElement(std::vector<int>& nums, int val) 
	{
		// Edge case.
		if (nums.size() == 0)
			return 0;

		int index1 = 0;
		int index2 = 0;

		while (index2 < nums.size())
		{
			if (nums[index2] != val)
			{
				nums[index1] = nums[index2];
				index1++;
			}

			index2++;
		}

		return index1;
	}
};


void show_vector(std::vector<int> vector, int range);


int main()
{
	Solution solution;
	std::vector<int> input = { 0, 1, 2, 2, 3, 0, 4, 2 };
	int num_to_remove = 2;

	std::cout << "INPUT:" << std::endl;
	show_vector(input, input.size());

	std::cout << "Num removed = " << num_to_remove << std::endl;

	int result = solution.removeElement(input, num_to_remove);
	std::cout << "Resulting array has " << result << " elements." << std::endl;
	show_vector(input, result);

	return 0;
}


void show_vector(std::vector<int> vector, int range)
{
	std::cout << "{ " << std::flush;
	for (unsigned int i = 0; i < range; i++)
	{
		std::cout << vector[i] << " " << std::flush;
	}
	std::cout << "}" << std::endl;
}