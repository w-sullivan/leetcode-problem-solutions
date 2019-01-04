//	William Sullivan
//	From: https://leetcode.com/problems/sort-array-by-parity/
//
//	Given an array A of non - negative integers, return an array consisting of
//	all the even elements of A, followed by all the odd elements of A.
//
//	You may return any answer array that satisfies this condition.
//
//	Example 1:
//	Input: [3, 1, 2, 4]
//	Output : [2, 4, 3, 1]
//
//	The outputs [4, 2, 3, 1], [2, 4, 1, 3], and [4, 2, 1, 3] would also be accepted.
//
//	Note :
//	1 <= A.length <= 5000
//	0 <= A[i] <= 5000

#include <iostream>
#include <vector>

class Solution 
{
public:
	std::vector<int> sortArrayByParity(std::vector<int>& A) 
	{
		// If size of array is 0 or 1, return the array.
		if (A.size() == 0 || A.size() == 1)
			return A;

		// Move i (index) to first instance of an odd number.
		int i = 0;
		while (i != A.size() && A[i] % 2 == 0)
			i++;

		// Check if at end.  That means there are no odd numbers.
		if (i == A.size())
			return A;

		int j = i;
		int temp;
		while (i < A.size())
		{
			// If Even, then swap with j
			if (A[i] % 2 == 0)
			{
				temp = A[i];
				A[i] = A[j];
				A[j] = temp;
				j++;
			}
			i++;
		}
		return A;
	}
};

void showVector(std::vector<int> nums);

int main()
{
	Solution solution;
	std::vector<int> input = { 1,3,5};

	std::cout << "Given: " << std::flush;
	showVector(input);

	solution.sortArrayByParity(input);
	std::cout << "Result: " << std::flush;
	showVector(input);

	return 0;
}

void showVector(std::vector<int> nums)
{
	std::cout << "{ " << std::flush;
	for (unsigned int i = 0; i < nums.size(); i++)
	{
		std::cout << nums[i] << " " <<  std::flush;
	}
	std::cout << "}" << std::endl;
}