#include <iostream>
#include <string>
#include <vector>


//completed Vote problem
using namespace std;
int main() {
	//first amount of cases
	//second is the amt of candidates
	//third is non negative int votes
	
	unsigned int cases, candidates;

	cin >> cases;
	for (unsigned int x = 0; x < cases; x++) {
		cin >> candidates;
		unsigned int max = 0, indexOfWinner = 0, sum = 0;
		unsigned int* candidateVotes = new unsigned int[candidates];
		for (unsigned int y = 0; y < candidates; y++) {
			cin >> candidateVotes[y];
			sum += candidateVotes[y];
			if (max < candidateVotes[y]) {
				max = candidateVotes[y];
				indexOfWinner = y+1;
			}
		}
		bool flag = false;
		bool tie = false;
		for (unsigned int y = 0; y < candidates; y++) {
			if (max == candidateVotes[y] && flag) {
				tie = true;
			}
			if (max == candidateVotes[y]){
				flag = true;
			}
		}
		//handle a majority
		if (max > sum/2 && !tie) {
			cout << "majority winner " << indexOfWinner;
		}
		//handle tie
		else if (tie) {
			cout << "no winner";
		}
		//handle no majority
		else {
			cout << "minority winner " << indexOfWinner;
		}
		//make sure to clear your memory.
		delete[] candidateVotes;
		candidateVotes = NULL;
	}
	return 0;
}