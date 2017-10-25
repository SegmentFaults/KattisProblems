#include <iostream>
using namespace std;

long long int findFactors(long long int value);
int main() {
	long long int input;
	cin >> input;
	long long int counter = findFactors(input);
	cout << counter;
	char z;
	cin >> z;
	return 0;
}
long long int findFactors(long long int X) {
	long long int n = X;
	long long int factors = 0;
	long long int current = 2;

	for (long long int i = 0; i*i <= X; i++) {
		if (n % current == 0) {
			n =n/current;
			factors++;
		}
		else
			current++;

	}
	if (n>1)
		factors++;
	return factors;
}