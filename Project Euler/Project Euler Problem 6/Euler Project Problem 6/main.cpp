/*  James Clark

	Project Euler Problem #6:
	The sum of the squares of the first ten natural numbers is,
			12 + 22 + ... + 102 = 385

	The square of the sum of the first ten natural numbers is,
			(1 + 2 + ... + 10)^2 = 552 = 3025

	Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025  385 = 2640.

	Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*/

#include <iostream>
#include <string>

using namespace std;

const string PROBLEM_DESCRIPTION =
	"The sum of the squares of the first ten natural numbers is,\n"
	"  12 + 22 + ... + 102 = 385\n\n"
	"The square of the sum of the first ten natural numbers is,\n"
	"  (1 + 2 + ... + 10)^2 = 552 = 3025\n\n"
	"Hence the difference between the sum of the squares of the first ten\nnatural numbers and the square of the sum is 3025  385 = 2640.\n\n"
	"Find the difference between the sum of the squares of the first\none hundred natural numbers and the square of the sum.";

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
	long square_sum = 0;
	long sum_squares = 0;
	long result = 0;

	for (int i = 1; i <=100; i++)
	{
		square_sum += i;
		sum_squares += i*i;
	}

	result = (square_sum * square_sum) - sum_squares;

	cout << PROBLEM_DESCRIPTION << "\n" << endl;
	cout << "[SOLUTION] " << result << endl;

	doPause();

	return 0;
}