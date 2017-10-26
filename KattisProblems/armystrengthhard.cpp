#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	long godzilla, mega, testcases, temp;
	vector<long> megaMonsters;
	vector<long> godMonsters;
	cin >> testcases;
	for (int x = 0; x < testcases; x++) {
		cin >> godzilla;
		cin >> mega;
		for (long y = 0; y < godzilla; y++) {
			cin >> temp;
			godMonsters.push_back(temp);
		}
		for (long y = 0; y < mega; y++) {
			cin >> temp;
			megaMonsters.push_back(temp);
		}
		sort(godMonsters.begin(), godMonsters.end());
		sort(megaMonsters.begin(), megaMonsters.end());
		//for (int y = 0; megaMonsters.size()!=0 && godMonsters.size()!=0; y++) {
		//	if (godMonsters.at(0) < megaMonsters.at(0)) {
		//		godMonsters.erase(godMonsters.begin());
		//	}
		//	else {
		//		megaMonsters.erase(megaMonsters.begin());
		//	}
		//}
		//cout << godMonsters.at(godMonsters.size() - 1) << " " << megaMonsters.at(megaMonsters.size() - 1);
		long godzillaMax = godMonsters.at(godMonsters.size() - 1);
		long megaMonsterMax = megaMonsters.at(megaMonsters.size() - 1);
		if (godzillaMax >= megaMonsterMax) {
			cout << "Godzilla" << endl;
		}
		else {
			cout << "MechaGodzilla" << endl;
		}
		godMonsters.clear();
		megaMonsters.clear();
		//cout << godstrength << " " << megastrength;
	}
	return 0;
}