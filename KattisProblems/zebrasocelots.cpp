#include <iostream>
using namespace std;
int main() {
	int length;
	int count=0;
	char temp;
	long long result=0;
	cin >> length;
	for (int x = 0; x < length; x++) {
		cin >> temp;
		if (temp == 'O') {
			result++;
		}
		result = result << 1;
	}
	result = result >> 1;
	cout << result;

}