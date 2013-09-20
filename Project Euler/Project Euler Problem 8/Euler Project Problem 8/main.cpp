/*  James Clark

	Euler Project Problem #8
	Find the greatest product of five consecutive digits in the 1000-digit number.

		73167176531330624919225119674426574742355349194934
		96983520312774506326239578318016984801869478851843
		85861560789112949495459501737958331952853208805511
		12540698747158523863050715693290963295227443043557
		66896648950445244523161731856403098711121722383113
		62229893423380308135336276614282806444486645238749
		30358907296290491560440772390713810515859307960866
		70172427121883998797908792274921901699720888093776
		65727333001053367881220235421809751254540594752243
		52584907711670556013604839586446706324415722155397
		53697817977846174064955149290862569321978468622482
		83972241375657056057490261407972968652414535100474
		82166370484403199890008895243450658541227588666881
		16427171479924442928230863465674813919123162824586
		17866458359124566529476545682848912883142607690042
		24219022671055626321111109370544217506941658960408
		07198403850962455444362981230987879927244284909188
		84580156166097919133875499200524063689912560717606
		05886116467109405077541002256983155200055935729725
		71636269561882670428252483600823257530420752963450
*/

#include <iostream>
#include <fstream>
#include <string>
#include <deque>

using namespace std;

const string PROBLEM_DESCRIPTION =
	"Find the greatest product of five consecutive digits in the 1000-digit number.\n\n";

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
	int result = 0;
	int running_total = 1;
	deque<int> digit;
	ifstream file;

	file.open("number.txt");

	if (file.fail())
	{
		cout << "Error opening number.txt! " << endl;
		file.close();
		doPause();
		return -1;
	}
	else cout << "Opened number.txt successfully." << endl;
	
	cout << PROBLEM_DESCRIPTION << "\n" << endl;

	while (!file.eof())
	{
		char ch;
		ch = file.get();

		cout << ch;

		if (isdigit(ch))
		{
			int num = atoi(&ch);

			if (digit.size() < 5)
			{
				digit.push_front(num);
				running_total *= num;
			}
			else 
			{
				digit.push_front(num);
				int last = digit.back();
				digit.pop_back();

				if (last == 0)
				{
					running_total = 1;

					deque<int>::iterator iter;
					for (iter = digit.begin(); iter != digit.end(); iter++)
						running_total *= *iter;
				}
				else 
				{
					running_total /= last;
					running_total *= num;
				}
			}
		}

		if (running_total > result)
			result = running_total;
	}

	cout << "\n\n" << endl;
	if (digit.size() < 5)
		cout << "Not enough digits in number.txt! (Minimum of 5)" << endl;
	else
	{
		cout << "[SOLUTION] " << result << endl;
		file.close();
	}

	doPause();
}