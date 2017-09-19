/* =======================================
~ TEAM Illusion ~

https://github.com/MarcoRhayden/Illusion
========================================== */
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <math.h>
using namespace std;

vector<string> splitLine(string line) {
    vector<string> vet;
    string item;
    stringstream ss;
    ss.str(line);

    while(getline(ss, item, ' ')) {
        vet.push_back(item);
    }

    return(vet);
}

bool CheckDate(vector<string> date) {
    bool response = true;
    for(int x = 1; x < date.size(); x++) {
        if(date[x] != "1") {
            response = false;
            x = date.size();
        }
    }
    return(response);
}

void ReadDates(int persons, int dates) {
    string tmp;
    vector<string> VetDate;
    bool response = false;

    for(int x = 1; x <= dates; x++) {
        cin >> tmp;
        VetDate.push_back(tmp);

        for(int j = 1; j <= persons; j++) {
            cin >> tmp;
            VetDate.push_back(tmp);
        }

        if(CheckDate(VetDate)) {
            cout << VetDate[0] << endl;
            x = dates+1; response = true;
        }

        VetDate.clear();
    }

    if(!response) {
        cout << "Pizza antes de FdI" << endl;
    }
}

int main() {
    vector<string> LineManip;
    string line;
    int persons, dates;

    while(getline(cin, line)) {
        LineManip = splitLine(line);

        if(LineManip.size() == 2) {
            stringstream(LineManip[0]) >> persons;
            stringstream(LineManip[1]) >> dates;

            if( (persons >= 1 && persons <= 50)
            && (dates >= 1 && dates <= 50) ) {
                ReadDates(persons, dates);
            }
        }
    }

    return(0);
}
