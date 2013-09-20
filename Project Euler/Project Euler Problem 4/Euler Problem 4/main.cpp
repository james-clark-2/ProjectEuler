/*  James Clark

	Euler Problem #4:
	A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91  99.
	Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include <iostream>
#include <vector>

using namespace std;

//==============================================================================

void doPause ()
{
	cout << "Press [ENTER] to exit." << endl;
	cin.clear();
	cin.ignore();
}

//==============================================================================
// bool isPalindrome (long num)
//		Returns true if the number is a palindrome
//

bool isPalindrome (long num)
{
	std::vector<int> digit_list;

	//Build a list of digits. This list will be the reverse of the digits in the actual number
	// but that doesn't matter.
	while (num > 0)
	{
		int digit = num%10;
		digit_list.push_back(digit);
		num /= 10;
	}

	int test_begin = 0;
	int test_end = digit_list.size()-1;
	bool palindrome_ok = true;

	//Check for "palindrome-ness"
	while (test_end > test_begin && palindrome_ok)
	{
		try
		{
			if (digit_list.at(test_begin) != digit_list.at(test_end))
				palindrome_ok = false;
			else
			{
				test_begin++;
				test_end--;
			}
		}
		catch (out_of_range& oor)
		{
			cerr << "Out of range error in isPalindrome(long num): " << oor.what() << endl;
		}
	}

	return palindrome_ok;
}

//==============================================================================
// bool solveNxNPalindrome (int low, int hi, long& result, int& result_m1, int& result_m2)
//		Solves for the highest palindrome made from the product of numbers between hi and low.
//		Saves the palindrome in result and it's multiples in result_m1 and result_m2
//		Returns TRUE if the solution is valid, FALSE if none was found

bool solveNxNPalindrome (int low, int hi, long& result, int& result_m1, int& result_m2)
{
	bool result_found = false;
	long largest_palindrome = 0;
	int mult1 = 0;
	int mult2 = 0;
	
	//Check for invalid hi and low. Return as no solution available.
	if (low > hi)
		return false;

	for (int i = hi; i >= low, i+i < mult1+mult2; i--)
		for (long res = i*i; res > largest_palindrome; res -= i)
			if (isPalindrome(res))
			{
				largest_palindrome = res;
				mult1 = i;
				mult2 = res/i;
				result_found = true;
			}

	//Save our solution
	result = largest_palindrome;
	result_m1 = mult1;
	result_m2 = mult2;

	//Let them know if the solution is valid
	return result_found;
}

//==============================================================================

const int LOWER_MULTIPLE = 100;
const int UPPER_MULTIPLE = 999;

int main (int argc, const char* argv[])
{
	long result;
	int mult1, mult2;

	cout << "Projet Euler Problem #4\n"
		 <<	"A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91  99.\n\n"
		 << "Find the largest palindrome made from the product of two 3-digit numbers.\n"
		 << endl;
	
	if (solveNxNPalindrome(LOWER_MULTIPLE,UPPER_MULTIPLE,result,mult1,mult2))
		cout << "\n[SOLUTION] " << mult1 << " * " << mult2 << " = " << result << endl;
	else
		cout << "\n[NO SOLUTION]" << endl;
	
	doPause();

	return 0;
}