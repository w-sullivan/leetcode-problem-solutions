// William Sullivan
//
//	From: https://leetcode.com/problems/transpose-matrix/description/
//
//	Given a matrix A, return the transpose of A.
//	The transpose of a matrix is the matrix flipped over it's main diagonal, 
//	switching the row and column indices of the matrix.
//
//	Example 1:
//	Input: [[1,2,3],[4,5,6],[7,8,9]]
//	Output: [[1, 4, 7], [2, 5, 8], [3, 6, 9]]
//
//	Example 2:
//	Input: [[1,2,3],[4,5,6]]
//	Output: [[1, 4], [2, 5], [3, 6]]

#include <iostream>
#include <vector>
using namespace std;


class Solution 
{
public:
	vector<vector<int>> transpose(vector<vector<int>>& A) 
	{
		vector<vector<int>> result;

		for (unsigned int x = 0; x < A[0].size(); x++)
		{
			vector<int> row;
			for (unsigned int y = 0; y < A.size(); y++)
			{
				row.push_back(A[y][x]);
			}
			result.push_back(row);
		}

		return result;
	}
};

void showMatrix(vector<vector<int>> matrix)
{
	for (unsigned int y = 0; y < matrix.size(); y++)
	{
		for (unsigned int x = 0; x < matrix[y].size(); x++)
		{
			cout << matrix[y][x] << " " << flush;
		}
		cout << endl;
	}
}

int main()
{
	Solution solution;
	vector<vector<int>> input_matrix = { {1, 2, 3}, {4, 5, 6} };
	vector<vector<int>> output_matrix;

	cout << "---INPUT---" << endl;
	showMatrix(input_matrix);

	output_matrix = solution.transpose(input_matrix);

	cout << "\n---RESULT---" << endl;
	showMatrix(output_matrix);

	return 0;
}