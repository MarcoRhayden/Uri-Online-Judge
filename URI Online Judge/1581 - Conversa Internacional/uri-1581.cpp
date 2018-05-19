#include <bits/stdc++.h>
using namespace std;

void which(vector<string> language) {
    vector<string> dif;

    for (int j = 0; j < language.size(); ++j) {
        if ( !(find(dif.begin(), dif.end(), language[j]) != dif.end()) ) {
            dif.push_back(language[j]);
        }
    }

    if (dif.size() > 1) {
        cout << "ingles" << endl;
    } else {
        cout << dif[0] << endl;
    }
}

int main(int argc, char *argv[]) {
    vector<string> language;
    string str;
    int cases, ppl;

    cin >> cases;

    while (cases--) {
        language.clear();
        cin >> ppl;

        for (int x = 0; x < ppl; ++x) {
            cin >> str;
            language.push_back(str);
        }

        which(language);
    }

    return(0);
}
