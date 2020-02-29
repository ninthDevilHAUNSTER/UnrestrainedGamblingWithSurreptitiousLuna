//
// Created by shaob on 2020/2/26.
//

#include <iostream>

using namespace std;

int pat_solver() {
    string s1, s2;
    int hash1[256];
    cin >> s1 >> s2;
    for (auto _s1: s1) hash1[_s1]++;
    int miss = 0;
    for (auto _s2: s2) {
        if (hash1[_s2] > 0) {
            hash1[_s2]--;
        } else {
            miss++;
        }
    }
    if (miss == 0)
        printf("Yes %d", int(s1.length() - s2.length()));
    else
        printf("No %d", miss);
    return 0;
}