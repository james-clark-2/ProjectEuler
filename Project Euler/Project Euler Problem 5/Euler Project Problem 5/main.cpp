/*  James Clark

	Project Euler Problem #5:
		2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

		What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

#include <iostream>
#include <string>

using namespace std;

const string PROBLEM_DESCRIPTION =
	"2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.\n\n"
	"What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?";

//==============================================================================

void doPause ()
{
	cout << "Press [ENTER] to exit." << endl;
	cin.clear();
	cin.ignore();
}

//==============================================================================

int main (int argc, const char* argv[])
{
	int result = 1;

	for (int i = 1; i < 10; i++)
	{
		
		
	}


	cout << PROBLEM_DESCRIPTION << "\n" << endl;
	cout << "[SOLUTION] " << result << endl;

	doPause();

	return 0;
}