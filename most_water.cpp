//	William Sullivan
//	From: https://leetcode.com/problems/container-with-most-water/
//
//	Given n non - negative integers a1, a2, ..., an, where each represents a point at
//	coordinate(i, ai).n vertical lines are drawn such that the two endpoints of line i
//	is at(i, ai) and (i, 0).Find two lines, which together with x - axis forms a 
//	container, such that the container contains the most water.
//
//	Note: You may not slant the container and n is at least 2.
//
//	Example:
//	Input: [1, 8, 6, 2, 5, 4, 8, 3, 7]
//	Output : 49

#include <iostream>
#include <algorithm>
#include <vector>

class Solution 
{
public:
	int maxArea(std::vector<int>& height) 
	{
		int area = 0;
		int max_area = 0;
		int left_edge = 0;
		int right_edge = height.size() - 1;

		while (left_edge != right_edge)
		{
			// Get the area.
			area = std::min(height[left_edge], height[right_edge]) 
				* (right_edge - left_edge);

			// Check versus the max.
			max_area = std::max(max_area, area);
			
			// move an edge.
			if (height[left_edge] > height[right_edge])
				right_edge--;
			else
				left_edge++;
		}

		return max_area;
	}
};

int main()
{
	Solution solution;
	std::vector<int> input = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
	int output;

	output = solution.maxArea(input);
	std::cout << output << std::endl;

	return 0;
}