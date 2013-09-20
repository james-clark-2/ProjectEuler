/*  James Clark

	Euler Problem #28:
	Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:

			21 22 23 24 25
			20  7  8  9 10
			19  6  1  2 11
			18  5  4  3 12
			17 16 15 14 13

	It can be verified that the sum of the numbers on the diagonals is 101.

	What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?
*/

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

const string PROBLEM_DESCRIPTION =
	"Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:\n"
	"\n"
	"  21 22 23 24 25\n"
	"  20  7  8  9 10\n"
	"  19  6  1  2 11\n"
	"  18  5  4  3 12\n"
	"  17 16 15 14 13\n\n"
	"It can be verified that the sum of the numbers on the diagonals is 101.\n\n"
	"What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?";

//==============================================================================

void doPause ()
{
	cout << "Press [ENTER] to exit." << endl;
	cin.clear();
	cin.ignore();
}

//==============================================================================

void getCorners (int ring, long& upper_left, long& upper_right, long& lower_left, long& lower_right)
{
	assert(ring >= 0);

	if (ring == 0)
	{
		upper_left = 1;
		upper_right = 0;
		lower_left = 0;
		lower_right = 0;
	}
	else
	{
		long ring_2 = ring+ring;
		upper_right = (ring_2+1)*(ring_2+1);
		lower_left = (ring_2*ring_2)+1;
		upper_left = upper_right - ring_2;
		lower_right = lower_left - ring_2;
	}
}

//==============================================================================

int main (int argc, const char* argv[])
{
	cout << PROBLEM_DESCRIPTION << "\n" << endl;

	long sum = 0;
	for (int i = 0; i <= 500; i++)  //500 rings in 1001x1001 spiral
	{
		long ur, ul, lr, ll;
		getCorners(i, ul, ur, ll, lr);
		sum = sum + ul + ur + ll + lr;
	}

	cout << "[SOLUTION]: " << sum << endl;
	
	doPause();

	return 0;
}