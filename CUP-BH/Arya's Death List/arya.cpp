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

int EnemyBetween(vector<int> *EnemyList, int a, int b) {
    int start, end, result;

    for(int x = 0; x < EnemyList->size(); x++) {
        if((*EnemyList)[x] == a) {
            start = (x+1);
        } else if((*EnemyList)[x] == b) {
            end = (x+1);
        }
    }

    result = (end - start) - 1;
    return((result == 0) ? 1 : result);
}

void InsertEnemy(std::vector<int> *EnemyList, int a, int b) {
    for(int x = 0; x < EnemyList->size(); x++) {
        if((*EnemyList)[x] == b) {
            EnemyList->insert(EnemyList->begin()+(x+1), a);
            x = EnemyList->size();
        }
    }
}

void RemoveEnemy(std::vector<int> *EnemyList, int a) {
    for(int x = 0; x < EnemyList->size(); x++) {
        if((*EnemyList)[x] == a) {
            EnemyList->erase(EnemyList->begin()+x);
        }
    }
}

vector<string> LineOperating(string buf, char delim) {
    stringstream ss; ss.str(buf);
    string item;
    vector<string> vet;

    while(getline(ss, item, delim)) {
        vet.push_back(item);
    }

    return(vet);
}

void AryaOperating(vector<int> *EnemyList, int op) {
    int a, b;
    string buf;
    vector<string> vet_op;

    for(int x = 1; x <= op; x++) {
        getline(cin, buf);

        vet_op = LineOperating(buf, ' ');

        if(vet_op.size() >= 2) {
            stringstream(vet_op[1]) >> a;
        }

        if(vet_op.size() >= 3) {
            stringstream(vet_op[2]) >> b;
        }

        if(vet_op[0] == "Q") {
            cout << EnemyBetween(EnemyList, a, b) << endl;
        }
        else if(vet_op[0] == "I") {
            InsertEnemy(EnemyList, a, b);
        }
        else if(vet_op[0] == "R") {
            RemoveEnemy(EnemyList, a);
        }
    }
}

int main() {
    vector<int> EnemyList;
    int StartEnemys, tmp;

    cin >> StartEnemys;

    if(StartEnemys >= 1 && StartEnemys <= (5*pow(10,4))) {
        for(int x = 0; x < StartEnemys; x++) {
            cin >> tmp;
            if(tmp >= 1 && tmp <= pow(10,9)) {
                EnemyList.push_back(tmp);
            }
        }

        cin >> tmp;
        if(tmp >= 1 && tmp <= (5*pow(10,4))) {
            cin.ignore(256, '\n');
            AryaOperating(&EnemyList, tmp);
        }
    }

    return(0);
}
