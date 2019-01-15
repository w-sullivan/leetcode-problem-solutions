//	William Sullivan
//	From:  https://leetcode.com/problems/move-zeroes/
//
//	Given an array nums, write a function to move all 0's to the end of it while
//	maintaining the relative order of the non-zero elements.
//
//	Example:
//	Input: [0, 1, 0, 3, 12]
//	Output : [1, 3, 12, 0, 0]
//
//	Note :
//	You must do this in - place without making a copy of the array.
//	Minimize the total number of operations.

#include <iostream>
#include <vector>

class Solution 
{
public:
	void moveZeroes(std::vector<int>& nums) 
	{
		if (nums.size() == 0 || nums.size() == 1)
			return;

		int i = 0;
		int j = 0;
		int temp;
		while (i < nums.size())
		{
			if (nums[i] != 0)
			{
				temp = nums[i];
				nums[i] = nums[j];
				nums[j] = temp;
				j++;
			}
			i++;
		}
	}
};

void showVector(std::vector<int> nums);

int main()
{
	Solution solution;
	std::vector<int> input = { 0, 1, 0, 3, 12 };

	std::cout << "Given array: " << std::flush;
	showVector(input);

	solution.moveZeroes(input);

	std::cout << "Result array: " << std::flush;
	showVector(input);
	return 0;
}

void showVector(std::vector<int> nums)
{
	std::cout << "{ " << std::flush;
	for (unsigned int i = 0; i < nums.size(); i++)
	{
		std::cout << nums[i] << " " << std::flush;
	}
	std::cout << "}" << std::endl;
}
