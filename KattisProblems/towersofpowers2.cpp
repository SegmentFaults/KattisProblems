#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <tuple>
using namespace std;
struct firstPair {
	unsigned long long int val;
	string str;
	unsigned long long int location;
	int overflows=0;
};

firstPair convertStringToLong(firstPair pair);
bool isNumber(char c);
bool sortByVal(const firstPair& lhs, const firstPair& rhs);
int main() {
	int size;
	cin >> size;
	cin.clear();
	cin.ignore(256, '\n');
	string temp;
	//take in the amount of values:Done
	//covert the value to pure integers:Done
	//record original array index
	//record ending array index. 
	//output based on the ending array index after transforming the array
	//output the original
	vector<firstPair> firstPairVector;

	//vector<secondPair> secondPairVector;//the first long is the value. The second is the index of when it was entered
	//vector<string, long> pairing;//the first string is the original string. The second is the index of when it was entered.
	for (unsigned long long x = 0; x < size; x++) {
		getline(cin, temp);
		firstPair pair;
		pair.str = temp;
		pair = convertStringToLong(pair);
		pair.location = x;
		//pair.str = temp;
		firstPairVector.push_back(pair);
	}
	sort(firstPairVector.begin(), firstPairVector.end(), sortByVal);
	cout << "Case 1:" << endl;
	for (long x = 0; x < size; x++) {
		cout << firstPairVector.at(x).str << endl;
	}
	return 0;
}

firstPair convertStringToLong(firstPair pair) {
	string s = pair.str;
	unsigned long long int result = 0;
	int count=0;
	vector<long> numbers;
	for (int x = 0; x < s.length(); x++) {
		if (s.at(x) == '^') {
			count++;
		}
	}
	bool prior = false;
	bool twoPrior = false;
	long temporaryInt = 0;
	for (unsigned long long int i = 0; i < s.size(); i++ ) {
		bool isNum = isNumber(s.at(i));
		if (!prior && isNum) {
			prior = true;
			temporaryInt = (int)s.at(i)-48;
		}
		else if(prior && !twoPrior && isNum){
			twoPrior = true;
			long holder = (int)s.at(i)-48;
			temporaryInt = (temporaryInt * 10) + holder;
		}
		else if (prior && twoPrior && isNum) {
			//cout << "found a hundred";
			numbers.push_back(100);
			prior = false;
			twoPrior = false;
		}
		else {
			prior = false;
			twoPrior = false;
			//cout << temporaryInt << endl;
			numbers.push_back(temporaryInt);
			temporaryInt = 0;
		}
	}
	//
	//cout << temporaryInt<<endl;
	numbers.push_back(temporaryInt);
	bool firstRun = true;
	for (int x = 0; x <= count; x++) {
		long long int previousNumber = result;
		if (count == 0 || firstRun) {
			result = numbers.back();
			numbers.pop_back();
			firstRun = false;
		}
		else {
			result = pow(numbers.back(), result);
			if (result < previousNumber) {
				pair.overflows++;
			}
			numbers.pop_back();
		}
	}
	pair.val = result;
	//cout << result << endl;
	return pair;
}
bool isNumber(char c) {
	int num = (int)c;
	if (num >= 48 && num < 58) {
		return true;
	}
	return false;
}
bool sortByVal(const firstPair& lhs, const firstPair& rhs)
{
	if (rhs.overflows != lhs.overflows) {
		return lhs.overflows<rhs.overflows;
	}
	if (lhs.val == rhs.val) {
		return lhs.location < rhs.location;
	}
	return lhs.val < rhs.val;
}