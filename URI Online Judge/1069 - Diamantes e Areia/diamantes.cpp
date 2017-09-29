/* =======================================
~ TEAM Illusion ~

https://github.com/MarcoRhayden/Illusion
========================================== */
#include <iostream>
using namespace std;

int main() {
	int diamonds, n, mid;
	string line;

	cin >> n;

	for(int x = 1; x <= n; ++x) {
		diamonds = 0;
		mid = 0;
		cin >> line;
		for(int j = 0; j < line.length(); ++j) {
			if(line[j] == '<') {
				++mid;
			}
			if(line[j] == '>' && mid > 0) {
				++diamonds;
				--mid;
			}
		}
		cout << diamonds << endl;
	}

	return(0);
}
