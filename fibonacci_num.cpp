//	William Sullivan
//	From: https://leetcode.com/problems/fibonacci-number/
//
//	The Fibonacci numbers, commonly denoted F(N) form a sequence, called the 
//	Fibonacci sequence, such that each number is the sum of the two preceding
//	ones, starting from 0 and 1. That is,
//
//	F(0) = 0, F(1) = 1
//	F(N) = F(N - 1) + F(N - 2), for N > 1.
//
//	Given N, calculate F(N).
//
//	Example 1:
//	Input: 2
//	Output : 1
//	Explanation : F(2) = F(1) + F(0) = 1 + 0 = 1.
//
//	Example 2 :
//	Input : 3
//	Output : 2
//	Explanation : F(3) = F(2) + F(1) = 1 + 1 = 2.
//
//	Example 3 :
//	Input : 4
//	Output : 3
//	Explanation : F(4) = F(3) + F(2) = 2 + 1 = 3.
//
//	Note :
//	0 <= N <= 30.

#include <iostream>
#include <vector>

class Solution
{
public:
	// Recursive solution. Runtime is O(2^N)
	int fib_recursive(int N)
	{
		if (N <= 1)
			return N;

		return fib_recursive(N - 1) + fib_recursive(N - 2);
	}

	// Dynamic Programming Solution.
	int fib(int N)
	{
		if (N <= 1)
			return N;

		std::vector<int> fib_nums = { 0, 1 };
		for (int i = 2; i <= N; i++)
		{
			fib_nums.emplace_back(fib_nums[i - 1] + fib_nums[i - 2]);
		}
		return fib_nums[N];
	}
};

int main()
{
	Solution solution;
	int input = 16;
	
	std::cout << "Input: " << input << std::endl;

	int output = solution.fib(input);

	std::cout << "Output: " << output << std::endl;

	return 0;
}