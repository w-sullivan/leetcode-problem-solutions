//	William Sullivan
//
// From: https://leetcode.com/problems/judge-route-circle/description/
// Initially, there is a Robot at position(0, 0).Given a sequence of its moves, judge if this robot makes a circle, which means it moves back to the original place.
//
// The move sequence is represented by a string.And each move is represent by a character.
// The valid robot moves are R(Right), L(Left), U(Up) and D(down).
// The output should be true or false representing whether the robot makes a circle.

#include <iostream>
using namespace std;

class Solution 
{
private:
	int x;
	int y;
public:
	Solution() { x = 0; y = 0; };
	bool judgeCircle(string moves) 
	{
		for (int i = 0; i < moves.size(); i++)
		{
			switch (moves.at(i))
			{
			case 'U':
				y += 1;
				break;
			case 'D':
				y -= 1;
				break;
			case 'L':
				x -= 1;
				break;
			case 'R':
				x += 1;
				break;
			default:
				cout << "ERROR: Invalid Move" << endl;
			}
		}

		cout << "X = " << x << "Y = " << y << endl;
		if (x == 0 && y == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

int main()
{
	string moves = "UD";
	Solution solution;

	cout << solution.judgeCircle(moves) << endl;

	return 0;
}
