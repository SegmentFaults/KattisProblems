//accepted solution
#include <iostream>
#include <cmath>

using namespace std;
void perfectTest(int testedNumber)
{
	int sq = (int)sqrt(testedNumber) + 1;
	int sum = 1;
	for (int i = 2; i < sq; i++)
	{
		if (testedNumber % i == 0)
		{
			int other = testedNumber / i;
			if (i != other) sum += other;
			sum += i;
		}
	}

	if (sum == testedNumber) {
		cout << testedNumber<< " Perfect" << endl;
	}
	else if (abs(sum - testedNumber) < 3) {
		cout << testedNumber<< " Almost perfect" << endl;
	}
	else {
		cout << testedNumber<< " Not perfect" << endl;
	}

}

int main()
{
	int n;
	while (cin >> n) {
		perfectTest(n);
	}
	return 0;
}