//	William Sullivan
//
//	From: https://leetcode.com/problems/toeplitz-matrix/description/
//
//	A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same element.
//	Now given an M x N matrix, return True if and only if the matrix is Toeplitz.
//
//	Example:
//	Input:
//	matrix = [
//			[1, 2, 3, 4],
//			[5, 1, 2, 3],
//			[9, 5, 1, 2]
//			]
//	Output : True
//	Explanation :
//	In the above grid, the diagonals are :
//	"[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]".
//	In each diagonal all elements are the same, so the answer is True.
//
//	Note:
//
//	matrix will be a 2D array of integers.
//	matrix will have a number of rows and columns in range[1, 20].
//	matrix[i][j] will be integers in range[0, 99].

#include <iostream>
#include <vector>
using namespace std;


class Solution 
{
private:
	bool diagonalTest(vector<vector<int>>& matrix, int start_x, int start_y)
	{
		unsigned int x = start_x;
		unsigned int y = start_y;
		int first_value = matrix[y][x];

		while (x < matrix[0].size() && y < matrix.size())
		{
			if (matrix[y][x] != first_value)
			{
				return false;
			}
			x++;
			y++;
		}

		return true;
	}

public:
	bool isToeplitzMatrix(vector<vector<int>>& matrix) 
	{
		int first_value;

		// check diagonals from x = 0 to max x
		for (unsigned int i = 0; i < matrix[0].size(); i++)
		{
			if (diagonalTest(matrix, i, 0) == false)
			{
				return false;
			}
		}

		// check diagonals from y = 1 to max y
		for (unsigned int i = 1; i < matrix.size(); i++)
		{
			if (diagonalTest(matrix, 0, i) == false)
			{
				return false;
			}
		}

		return true;
	}
};

int main()
{
	Solution solution;
	vector<vector<int>> input = {{1, 2, 3, 4},
								 {5, 1, 2, 3},
								 {9, 5, 1, 2}};
	bool output;

	output = solution.isToeplitzMatrix(input);

	if (output)
	{
		cout << "The matrix is a Toeplitz Matrix" << endl;
	}
	else
	{
		cout << "The matrix is NOT a Toeplitz Matrix" << endl;
	}

	return 0;
}