// William Sullivan
//
// From: https://leetcode.com/problems/island-perimeter/description/
// You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water. 
// Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, 
// and there is exactly one island (i.e., one or more connected land cells). The island doesn't have "lakes" 
// (water inside that isn't connected to the water around the island). One cell is a square with side length 1. 
// The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.
// 
// Example: 
// [[0, 1, 0, 0],
//	[1, 1, 1, 0],
//	[0, 1, 0, 0],
//	[1, 1, 0, 0]]
//
// Answer: 16

#include <iostream>
#include <vector>
using namespace std;


class Solution
{
private:
	int x_size;
	int y_size;
public:
	int islandPerimeter(vector<vector<int>>& grid)
	{
		

		// Get grid dimensions, or return -1 if invalid size grid.
		if (grid.size() > 0 && grid[0].size() > 0)
		{
			x_size = grid[0].size();
			y_size = grid.size();
		}
		else
		{
			return -1;
		}

		int sum_of_edges = 0;

		// for each element in the grid check for borders
		for (int y = 0; y < y_size; y++)
		{
			for (int x = 0; x < x_size; x++)
			{
				// If the value is land. (ie. 1)
				if (grid[y][x] == 1)
				{
					//Check North
					if (y - 1 < 0 || grid[y - 1][x] == 0 )
					{
						sum_of_edges++;
					}

					//Check South
					if (y + 1 >= y_size || grid[y + 1][x] == 0)
					{
						sum_of_edges++;
					}

					//Check West
					if (x - 1 < 0 || grid[y][x - 1] == 0)
					{
						sum_of_edges++;
					}

					//Check East
					if (x + 1 >= x_size || grid[y][x + 1] == 0)
					{
						sum_of_edges++;
					}
				}
			}
		}

		return sum_of_edges;
	}
};

int main()
{
	Solution solution;
	vector<vector<int>> island = {	{0, 1, 0, 0},
									{1, 1, 1, 0},
									{0, 1, 0, 0},
									{1, 1, 0, 0} };
	int answer;

	answer = solution.islandPerimeter(island);

	cout << "ANSWER: " << answer << endl;

	return 0;
}