//	William Sullivan
//
//	From: https://leetcode.com/problems/diagonal-traverse/description/
//
//	Given a matrix of M x N elements (M rows, N columns), return all elements
//	of the matrix in diagonal order as shown below.
//
//	Example:
//	Input:
//	[
//		[1, 2, 3],
//		[4, 5, 6],
//		[7, 8, 9]
//	]
//	Output : [1, 2, 4, 7, 5, 3, 6, 8, 9]
//
//	Note:
//	The total number of elements of the given matrix will not exceed 10, 000.

#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
private:
	// Returns a vector of ints that are a diagonal of matrix, starting at x, y and
	//	moving up and to the right.  If upRight is false, it returns the reverse of
	//	the vector, to simulate down and left traversal.
	vector<int> getDiagonal(vector<vector<int>>& matrix, int x, int y, bool upRight)
	{
		vector<int> result;

		do
		{
			// If traversal direction is up and right
			if (upRight)
			{
				result.push_back(matrix[y][x]);
			}
			//	Otherwise it traverses down and left. In other words,
			//	Up and right reversed.
			else
			{
				result.insert(result.begin(), matrix[y][x]);
			}

			x++;
			y--;

		} while (x < matrix[0].size() && y >= 0);

		return result;
	}

public:

	vector<int> findDiagonalOrder(vector<vector<int>>& matrix) 
	{
		vector<int> result;
		int x = 0;					// Starts at 0,0.
		int y = 0;
		bool up_right = true;		// Indicates direction of traversal
									// False is down and to the left.

		// If matrix is empty, return empty result
		if (matrix.size() == 0)
		{
			return result;
		}

		// Do while not at the end of the matrix.
		do
		{
			// Get diagonal with given direction.
			vector<int> diagonal = getDiagonal(matrix, x, y, up_right);

			// Append it to the result.
			result.insert(result.end(), diagonal.begin(), diagonal.end());

			// Move to start of next diagonal.
			if (y + 1 > matrix.size() - 1)
			{
				x++;
			}
			else
			{
				y++;
			}

			// toggle direction
			up_right = !up_right;

		} while (x < matrix[0].size() && y < matrix.size());

		return result;
	}
};

void showMatrix(vector<vector<int>>& matrix)
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

void showVector(vector<int> nums)
{
	cout << "[ " << flush;
	for (unsigned int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << " " << flush;
	}
	cout << "]" << endl;
}

int main()
{
	Solution solution;
	vector<vector<int>> input = {	{1, 2, 3},
									{4, 5, 6},
									{7, 8, 9} };
	vector<int> result;

	result = solution.findDiagonalOrder(input);

	cout << "Diagonal traversal of matrix: " << endl;
	showMatrix(input);

	cout << "\nResults in:" << endl;
	showVector(result);

	return 0;
}