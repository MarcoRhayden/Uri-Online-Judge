#include <bits/stdc++.h>
using namespace std;

void resultData(vector<string> identifier,
    vector<int> timeSbm,
    vector<string> result,
    int sbm)
{
    vector<string> crt, inctr;
    int s = 0;
    int p = 0;
    for (int i = 0; i < sbm; ++i) {
        if (result[i].compare("correct") == 0) {
            s++;
            p += timeSbm[i];
            crt.push_back(identifier[i]);
        } else {
            inctr.push_back(identifier[i]);
        }
    }
    for (int j = 0; j < inctr.size(); ++j) {
        if (find(crt.begin(), crt.end(), inctr[j]) != crt.end()) {
            p += 20;
        }
    }
    cout << s << " " << p << endl;
}

int main(int argc, char *argv[]) {
    int sbm, t;
    string str;
    vector<string> identifier;
    vector<int> timeSbm;
    vector<string> result;
    while ( (cin >> sbm) && (sbm != 0) ) {
        identifier.clear();
        timeSbm.clear();
        result.clear();
        for (int x = 0; x < sbm; ++x) {
            cin >> str;
            identifier.push_back(str);
            cin >> t;
            timeSbm.push_back(t);
            cin >> str;
            result.push_back(str);
        }
        resultData(identifier, timeSbm, result, sbm);
    }
    return(0);
}
