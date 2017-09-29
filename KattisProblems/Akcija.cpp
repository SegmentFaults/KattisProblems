//accepted solution to akciijia.
/*#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;
int main() {
	int size;
	cin >> size;
	vector<int> ar;
	int temporary;
	for (int x = 0; x < size; x++) {
		cin >>temporary;
		ar.push_back(temporary);
	}
	sort(ar.begin(), ar.begin() + ar.size(), std::greater<int>());
	int counter = 0;
	int total = 0;
	for (int i = 0; i < size; i++) {
		if (counter != 2) {
			total += ar[i];
			//cout << total;
			counter++;
		}
		else {
			counter = 0;
		}
	}
	cout << total;
	char z;
	cin >> z;
	return 0;
}
*/