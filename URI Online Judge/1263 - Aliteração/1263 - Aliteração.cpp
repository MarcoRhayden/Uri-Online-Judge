#include <bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]) {
    string altr;
    while(getline(cin, altr)) {
        transform(altr.begin(), altr.end(), altr.begin(), ::tolower);
        int result = 0;
        char c = altr[0], blk = '0';
        for(int i = 0; i < altr.length(); ++i) {
            if(altr[i] == ' ') {
                if(c == altr[i+1]) {
                    if(c != blk) {
                        ++result;
                    }
                }
                blk = c;
                c = altr[i+1];
            }
        }
        cout << result << endl;
    }
    return(0);
}
