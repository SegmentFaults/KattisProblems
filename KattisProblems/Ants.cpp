//accepted solution
/*#include <iostream>
#include <vector>
#include <cmath>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
using namespace std;
int main() {
	int testCases;
	int lengthOfPole;
	int numberOfAnts;

	vector<int> distances;

	cin >> testCases;

	for (int x = 0; x < testCases; x++) {
		int shortest = 0;
		int longest = 0;
		cin >> lengthOfPole;

		cin >> numberOfAnts;

		for (int y = 0; y < numberOfAnts; y++) {
			int a;
			cin >> a;
			shortest = max(shortest, min(a, lengthOfPole - a));
			longest = max(longest, max(a, lengthOfPole - a));
		}

		cout << shortest << " " << longest << endl;
	}

	
	return 0;
}
*/
