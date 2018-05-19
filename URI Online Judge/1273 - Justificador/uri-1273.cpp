#include <bits/stdc++.h>
using namespace std;

void printWord(string word, int maxlength) {
    int space = (maxlength - word.length());
    cout << string(space, ' ') << word << endl;
}

int main(int argc, char *argv[]) {
    vector<string> v_words;
    string word;
    int wordsQntd, maxlength, newline = 0;

    while ( (cin >> wordsQntd) && (wordsQntd != 0) ) {
        v_words.clear();
        maxlength = 0;

        for (int i = 0; i < wordsQntd; ++i) {
            cin >> word;

            if (word.length() > maxlength)
                maxlength = word.length();

            v_words.push_back(word);
        }

        if (!newline) {
            newline = 1;
        } else {
            cout << endl;
        }

        for (int x = 0; x < v_words.size(); x++) {
            printWord(v_words[x], maxlength);
        }
    }

    return(0);
}
