// William Sullivan
//
// From: https://leetcode.com/problems/array-partition-i/description/
// Given an array of 2n integers, your task is to group these integers into n pairs of integer, 
// say (a1, b1), (a2, b2), ..., (an, bn) which makes sum of min(ai, bi) for all i from 1 to n as large as possible.
//
//  Example:
//  Input: [1,4,3,2]
//
//  Output: 4
//	Explanation : n is 2, and the maximum sum of pairs is 4 = min(1, 2) + min(3, 4).


#include <iostream>
#include <vector>
using namespace std;

/*
			QUICK SORT
	----------------------------
	Using Hoare partition scheme


algorithm quicksort(A, lo, hi) is
	if lo < hi then
		p : = partition(A, lo, hi)
		quicksort(A, lo, p)
		quicksort(A, p + 1, hi)

algorithm partition(A, lo, hi) is
	pivot : = A[lo]
	i : = lo - 1
	j : = hi + 1
		loop forever
			do
				i : = i + 1
			while A[i] < pivot

			do
				j : = j - 1
			while A[j] > pivot

			if i >= j then
				return j

			swap A[i] with A[j]
*/

class Solution 
{
private:

public:
	Solution() {}


	int arrayPairSum(vector<int>& nums) 
	{
		int sum = 0;
		// Sort array
		quickSort(nums, 0, nums.size() - 1);
		// for every other element, starting at [0], sum the values.
		for (unsigned int i = 0; i < nums.size(); i += 2)
		{
			sum += nums[i];
		}
		solutionOutput(nums);
		return sum;
	}

	void quickSort(vector<int>& myArray, unsigned int low_index, unsigned int high_index)
	{
		if (low_index < high_index)
		{
			int p = partition(myArray, low_index, high_index);
			quickSort(myArray, low_index, p);
			quickSort(myArray, p + 1, high_index);
		}
	}

	int partition(vector<int>& myArray, unsigned int low_index, unsigned int high_index)
	{
		int pivot = myArray[low_index];

		int i = low_index - 1;
		int j = high_index + 1;

		while(true)
		{		
			do
			{
				i++;
			} while (myArray[i] < pivot);


			do
			{
				j--;
			} while (myArray[j] > pivot);
				
			if (i >= j)
			{
				return j;
			}

			int temp = myArray[i];
			myArray[i] = myArray[j];
			myArray[j] = temp;
		}
	}


	void solutionOutput(vector<int> intArray)
	{
		cout << "[ " << flush;
		for (int i = 0; i < intArray.size(); i++)
		{
			cout << intArray[i] << " " << flush;
		}
		cout << "]" << endl;
	}
};


int main()
{
	vector<int> input = { 1, 4, 3, 2 };
	Solution solution;

	
	cout << solution.arrayPairSum(input) << endl;

	return 0;
}