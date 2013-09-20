/*  James Clark

	Euler Project Problem #10
		The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

		Find the sum of all the primes below two million.
*/

#include <iostream>
#include <string>

using namespace std;

const string PROBLEM_DESCRIPTION =
	"The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.\n\n"
	"Find the sum of all the primes below two million.";

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
	if (number == 0 || number == 1)
		return false;
	else if (number == 2)
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
	//Assume the first prime number
	long long result = 2;
	
	cout << PROBLEM_DESCRIPTION << "\n" << endl;
		
	//Assuming 2 is the first prime number. Start testing at 3
	// Even numbers > 2 are not prime! Test odds!
	for (long i = 3; i < 2000000; i+=2)
		if (isPrime(i))
			cout << i << endl;

	cout << "[SOLUTION] " << result << endl;

	doPause();
}