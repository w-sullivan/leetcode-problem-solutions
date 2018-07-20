//	William Sullivan
//
//	From: https://leetcode.com/problems/reshape-the-matrix/description/
//
//	In MATLAB, there is a very useful function called 'reshape', which can reshape a matrix
//	into a new one with different size but keep its original data.
//
//	You're given a matrix represented by a two-dimensional array, 
//	and two positive integers r and c representing the row number and column number
//	of the wanted reshaped matrix, respectively.
//
//	The reshaped matrix need to be filled with all the elements of the original matrix 
//	in the same row - traversing order as they were.
//
//	If the 'reshape' operation with given parameters is possible and legal, 
//	output the new reshaped matrix; Otherwise, output the original matrix.
//
//	Example 1:
//	Input:
//	nums = [[1, 2],
//			[3, 4]]
//	r = 1, c = 4
//	Output :
//	[[1, 2, 3, 4]]
//	Explanation :
//	The row - traversing of nums is[1, 2, 3, 4].The new reshaped matrix is a 1 * 4 matrix, 
//	fill it row by row by using the previous list.
//
//	Note:
//	The height and width of the given matrix is in range[1, 100].
//	The given r and c are all positive.

#include <iostream>
#include <vector>
using namespace std;


class Solution 
{
public:
	vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c)
	{
		// Check if legal
		int size = nums.size() * nums[0].size();
		if (size != r*c)
		{
			return nums;
		}

		vector<vector<int>> result;
		vector<int> row;
		int current_r = 0;
		int current_c = 0;

		// For each number in nums matrix
		for (unsigned int i = 0; i < nums.size(); i++)
		{
			for (unsigned int j = 0; j < nums[i].size(); j++)
			{
				// if end of number of required columns is reached
				if (current_c == c)
				{
					// Move to next row
					result.push_back(row);
					row = {};
					current_r++;
					current_c = 0;
				}
				// Push the nums value to result
				row.push_back(nums[i][j]);
				current_c++;
			}
		}
		result.push_back(row);
		return result;
	}
};

void showMatrix(vector<vector<int>> matrix)
{
	for (unsigned int i = 0; i < matrix.size(); i++)
	{
		cout << "[ " << flush;
		for (unsigned int j = 0; j < matrix[i].size(); j++)
		{
			cout << matrix[i][j] << " " << flush;
		}
		cout << "]" << endl;
	}
}

int main()
{
	Solution solution;
	vector<vector<int>> input = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16 } };

	showMatrix(input);
	input = solution.matrixReshape(input, 8, 2);

	showMatrix(input);
	return 0;
}