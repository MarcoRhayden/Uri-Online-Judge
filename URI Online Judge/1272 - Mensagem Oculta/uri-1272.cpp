#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    string word, hide;
    int cases, indexSpace, indexNext;

    cin >> cases;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    while (cases--) {
        indexSpace = 0;
        word.clear();
        hide.clear();

        getline(cin, word);

        for (indexNext = indexSpace; indexNext < word.length(); indexNext++) {
            if (word[indexNext] != ' ') {
                hide += word[indexNext];
            } else {
                continue;
            }

            for (indexSpace = indexNext; indexSpace < word.length(); indexSpace++) {
                if (word[indexSpace] == ' ') {
                    indexNext = indexSpace;
                    break;
                } else {
                    indexNext++;
                }
            }
        }

        cout << hide << endl;
    }

    return(0);
}
