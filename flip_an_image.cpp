//	William Sullivan
//
// From: https://leetcode.com/problems/flipping-an-image/description/
// Given a binary matrix A, we want to flip the image horizontally, then invert it, and return the resulting image.
// To flip an image horizontally means that each row of the image is reversed.For example, flipping[1, 1, 0] horizontally results in[0, 1, 1].
// To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0. For example, inverting[0, 1, 1] results in[1, 0, 0].
//
// Example:
// Input: [[1,1,0],[1,0,1],[0,0,0]]
// Output: [[1, 0, 0], [0, 1, 0], [1, 1, 1]]
// Explanation : First reverse each row : [[0, 1, 1], [1, 0, 1], [0, 0, 0]].
// Then, invert the image : [[1, 0, 0], [0, 1, 0], [1, 1, 1]]
//
// Notes:
// 1 <= A.length = A[0].length <= 20
// 0 <= A[i][j] <= 1

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> flipImage(vector<vector<int>> image)
	{
		vector<vector<int>> flippedImage;
		vector<int> nullVector;
		vector<int> flippedVector;

		for (unsigned int i = 0; i < image.size(); i++)
		{

			flippedVector = nullVector;
			for (int j = (int)image[i].size() -1; j >= 0 ; j--)
			{
				flippedVector.push_back(image[i][j]);
			}
			flippedImage.push_back(flippedVector);
		}
		return flippedImage;
	}

	vector<vector<int>> invertImage(vector<vector<int>> image)
	{
		vector<vector<int>> invertedImage = image;

		for (unsigned int i = 0; i < image.size(); i++)
		{
			for (unsigned int j = 0; j < image[i].size(); j++)
			{
				if (image[i][j] == 0)
				{
					invertedImage[i][j] = 1;
				}
				else
				{
					invertedImage[i][j] = 0;
				}
			}
		}
		return invertedImage;
	}

	vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A)
	{
		return flipImage(invertImage(A));
	}
};


int main()
{
	Solution solution;
	vector<vector<int>> image = { {1,1,0}, {1,0,1}, {0,0,0} };

	for (unsigned int i = 0; i < image.size(); i++)
	{
		for (unsigned int j = 0; j < image[i].size(); j++)
		{
			cout << image[i][j] << " " << flush;
		}
		cout << endl;
	}

	image = solution.flipAndInvertImage(image);
	cout << endl << endl;

	for (unsigned int i = 0; i < image.size(); i++)
	{
		for (unsigned int j = 0; j < image[i].size(); j++)
		{
			cout << image[i][j] << " " << flush;
		}
		cout << endl;
	}

	return 0;
}