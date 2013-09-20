//==============================================================================
// James Clark
//
//	Euler Project Problem #1:
//	If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
//
//	Find the sum of all the multiples of 3 or 5 below 1000.


#include <iostream>

using namespace std;

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
	long result = 0L;

	for (int i = 1; i < 1000; i++)
		if (i%15==0)
			result+=i;
		else if (i%5==0)
				result+=i;
		else if (i%3==0)
				result+=i;

	cout << "Euler Project Problem #1:\n"
		 <<	"If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.\n\n"
		 << "Find the sum of all the multiples of 3 or 5 below 1000.\n"
		 << endl;

	cout << "[SOLUTION] " << result << endl;
	doPause();

	return 0;
}