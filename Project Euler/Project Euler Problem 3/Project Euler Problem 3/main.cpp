/*  James Clark

	Project Euler Problem #3:
		The prime factors of 13195 are 5, 7, 13 and 29.

		What is the largest prime factor of the number 600851475143 ?
*/

#include <iostream>
#include <string>

using namespace std;

const string PROBLEM_DESCRIPTION =
	"The prime factors of 13195 are 5, 7, 13 and 29.\n\n"
	"What is the largest prime factor of the number 600851475143?";

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

	for (long long i = 3; i <= sqrt((double)number); i+=2)
		if (number%i == 0)
			return false;
	
	return true;
}

//==============================================================================

const long long NUMBER = 600851475143;

int main (int argc, const char* argv[])
{
	long long largest_prime_divisor = 1;

	for (long long d1 = 2, d2 = NUMBER/2; d1 <= d2; d1++, d2 = NUMBER/d1)
	{
		if (NUMBER%d1 == 0 && NUMBER%d2 == 0) //Make sure these are really divisors of NUMBER
		{
			if (isPrime(d2))
			{
				if (d2 > largest_prime_divisor)
					largest_prime_divisor = d2;
			}
			else if (isPrime(d1))
			{
				if (d1 > largest_prime_divisor)
					largest_prime_divisor = d1;
			}
		}		
	}

	if (largest_prime_divisor == 1)
		largest_prime_divisor = NUMBER;

	cout << PROBLEM_DESCRIPTION << "\n" << endl;
	cout << "[SOLUTION] " << largest_prime_divisor << endl;

	doPause();

	return 0;
}