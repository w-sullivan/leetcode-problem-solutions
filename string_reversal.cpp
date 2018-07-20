//	William Sullivan
//
//	From: https://leetcode.com/problems/reverse-string/description/
//
//  Write a function that takes a string as input and returns the string reversed.
//
//  Example:
//  Given s = "hello", return "olleh".

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:

	// One way
	string reverseString1(string s)
	{
		string reversed = "";

		for (int i = s.size() - 1; i >= 0; i--)
		{
			reversed += s[i];
		}

		return reversed;
	}

	string reverseString2(string s)
	{
		char temp_c;

		for (unsigned int i = 0; i < s.size()/2; i++)
		{
			temp_c = s[i];
			s[i] = s[(s.size() - 1) - i];
			s[(s.size() - 1) - i] = temp_c;
		}

		return s;
	}

};

int main()
{
	Solution solution;
	string input = "";
	int choice = 0; 

	cout << "Enter a string: " << flush;
	getline(cin, input);

	while (choice != 5)
	{
		cout << endl << endl;
		cout << "Choose a reversal method" << endl;
		cout << "1. Create a temp string, add characters backwards." << endl;
		cout << "2. Characters swapped without creating a new string." << endl;
		cout << endl;
		cout << "4. Enter a new string" << endl;
		cout << "5. Quit" << endl;
		cout << "---------------------------------------------------" << endl;
		cout << "> " << flush;
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << endl << solution.reverseString1(input) << endl;
			break;
		case 2:
			cout << endl << solution.reverseString2(input) << endl;
			break;
		case 4:
			cout << "Enter a string: " << flush;
			getline(cin, input);
			break;
		case 5:
			cout << "Quitting" << endl;
			break;
		default:
			cout << "Enter a number between 1 -5: " << flush;
			cin >> choice;

		}

	}
	return 0;
}