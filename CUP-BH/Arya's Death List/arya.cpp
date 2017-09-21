/* =======================================
~ TEAM Illusion ~

https://github.com/MarcoRhayden/Illusion
========================================== */
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <math.h>
#include <algorithm>
using namespace std;

int EnemyFind(vector<u_long> *EnemyList, u_long enemy) {
  int pos = -1;
  for(int j = 0; j < EnemyList->size(); j++) {
    if((*EnemyList)[j] == enemy) {
      pos = j;
      j = EnemyList->size();
    }
  }
  return(pos);
}

int main() {
  vector<u_long> EnemyList;
  u_long EnemyA, EnemyB;
  int StartEnemys, operations, pos, pos2;
  char op;

  cin >> StartEnemys;
  for(int i = 0; i < StartEnemys; i++) {
    cin >> EnemyA;
    EnemyList.push_back(EnemyA);
  }

  cin >> operations;
  for(int x = 1; x <= operations; x++) {
    cin >> op >> EnemyA;

    if(op == 'R') {
      pos = EnemyFind(&EnemyList, EnemyA);
      EnemyList.erase(EnemyList.begin()+pos);
    }
    else if(op == 'I') {
      cin >> EnemyB;
      pos = EnemyFind(&EnemyList, EnemyB);
      EnemyList.insert(EnemyList.begin()+(pos+1), EnemyA);
    }
    else if(op == 'Q') {
      cin >> EnemyB;
      pos = EnemyFind(&EnemyList, EnemyA);
      pos2 = EnemyFind(&EnemyList, EnemyB);
      cout << (max(pos, pos2) - min(pos, pos2) - 1) << endl;
    }
  }

  return(0);
}
