/*  James Clark

	Euler Project Problem #7
		By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

		What is the 10 001st prime number?
*/

#include <iostream>
#include <string>

using namespace std;

const string PROBLEM_DESCRIPTION =
	"By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.\n\n"
	"What is the 10 001st prime number?";

//==============================================================================

void doPause ()
{
	cout << "Press [ENTER] to exit." << endl;
	cin.clear();
	cin.ignore();
}

//==============================================================================

bool isPrime (long long number)
{
	if (number == 0)
		return false;
	if (number == 2)
		return true;
	else number = abs(number);

	for (long long i = 3; i < sqrt((double)number); i+=2)
		if (number%i == 0)
			return false;
	
	return true;
}

//==============================================================================

int main (int argc, const char* argv[])
{
	long long result = 0;
	
	//Assuming 2 is the first prime number. Start the count at 1 and start testing from 3.
	long long test_number = 3;
	int prime_count = 1;

	while (prime_count < 10001)
	{
		if (isPrime(test_number))
		{
			prime_count++;
			result = test_number;
		}
		
		test_number+=2; //Even numbers beyond 2 are not prime!
	}

	cout << PROBLEM_DESCRIPTION << "\n" << endl;
	cout << "[SOLUTION] " << result << endl;

	doPause();
}