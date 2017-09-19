/* =======================================
~ TEAM Illusion ~

https://github.com/MarcoRhayden/Illusion
========================================== */
#include <iostream>
#include <sstream>
#include <math.h>
using namespace std;

bool isPrime(int x) {
    int count = 0;
    for(int j = x; j > 0; j--) {
        if(x % j == 0) {
            count++;
        }
    }
    return((count == 2) ? true : false);
}

bool DcmpPrime(int nmb, int min) {
    bool response = true;
    int div = 2;

    while(nmb > 1) {
        if(nmb % div == 0) {
            nmb /= div;
            if( (!isPrime(div)) || (isPrime(div) && div >= min) ) {
                response = false;
                nmb = 0;
            }
            div = 2;
        } else {
            div++;
        }
    }

    return(response);
}

int MagicFactor(int DoloresNMB, int min) {
    int count = 0;

    for(int oz = DoloresNMB; oz > 0; oz--) {
        if(DoloresNMB % oz == 0) {
            if(DcmpPrime(oz, min)) {
                count++;
            }
        }
    }

    return(count);
}

int main() {
    int DoloresNMB, prime;
    string lines;
    cin >> DoloresNMB;

    if(DoloresNMB >= 2 && DoloresNMB <= pow(10, 12)) {
        while(getline(cin, lines)) {
            stringstream(lines) >> prime;
            if(prime >= 2 && prime <= pow(10,7)) {
                DoloresNMB *= prime;
                cout << MagicFactor(DoloresNMB, prime) << endl;
            }
        }
    }

    return(0);
}
