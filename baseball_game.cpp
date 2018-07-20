//	William Sullivan
//
//	From: https://leetcode.com/problems/baseball-game/description/
//  You're now a baseball game point recorder.
//
//  Given a list of strings, each string can be one of the 4 following types :
//
//  Integer(one round's score): Directly represents the number of points you get in this round.
//	"+" (one round's score): Represents that the points you get in this round are the sum of the last two valid round's points.
//	"D" (one round's score): Represents that the points you get in this round are the doubled data of the last valid round's points.
//	"C" (an operation, which isn't a round's score) : Represents the last valid round's points you get were invalid and should be removed.
//	Each round's operation is permanent and could have an impact on the round before and the round after.
//
//	You need to return the sum of the points you could get in all the rounds.
//
//	Example:
//  Input: ["5","-2","4","C","D","9","+","+"]
//  Output: 27
//	Explanation :
//	Round 1 : You could get 5 points.The sum is : 5.
//	Round 2 : You could get - 2 points.The sum is : 3.
//	Round 3 : You could get 4 points.The sum is : 7.
//	Operation 1 : The round 3's data is invalid. The sum is: 3.  
//	Round 4 : You could get - 4 points(the round 3's data has been removed). The sum is: -1.
//	Round 5: You could get 9 points.The sum is : 8.
//	Round 6 : You could get - 4 + 9 = 5 points.The sum is 13.
//	Round 7 : You could get 9 + 5 = 14 points.The sum is 27.
//
//	Note:
//	The size of the input list will be between 1 and 1000.
//  Every integer represented in the list will be between - 30000 and 30000.

#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Solution 
{
public:
	int calPoints(vector<string>& ops) 
	{
		int sum = 0;
		vector<int> valid_points;

		// for every element in ops
		for (unsigned int i = 0; i < ops.size(); i++)
		{
			sum = 0;
			// get operation
			// get the first char, if it is a number or '-' (meaning the start of a negative number)
			if ( isdigit(ops[i].at(0)) || ops[i].at(0) == '-')
			{
				// Convert the string to a number then push it on the points array.
				int number = stoi(ops[i]);
				valid_points.push_back(number);
			}

			// "+" :  Sum of the last two valid round's points.
			else if (ops[i] == "+")
			{
				sum = (valid_points.back()) + (valid_points[valid_points.size() - 2]);
				valid_points.push_back(sum);
			}

			// "D" : Doubled data of the last valid round's points.
			else if (ops[i] == "D")
			{
				sum = valid_points.back() * 2;
				valid_points.push_back(sum);
			}

			// "C" : Last valid round's points were invalid and should be removed
			else if (ops[i] == "C")
			{
				valid_points.pop_back();
			}

			else
			{
				cout << "Error, input contains unrecognized operation." << endl;
			}
		}

		// Add up all the valid points to get the total sum.
		sum = 0;
		for (unsigned int i = 0; i < valid_points.size(); i++)
		{
			sum += valid_points[i];
		}

		return sum;
	}
};

int main()
{
	Solution solution;
	vector<string> input = { "5","2","C","D","+" };
	int output;

	output = solution.calPoints(input);
	cout << "ANSWER: " << output << endl;

	return 0;
}