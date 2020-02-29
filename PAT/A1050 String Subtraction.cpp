//
// Created by shaob on 2020/2/26.
//

#include <iostream>

using namespace std;
bool hashmap[128];

int pat_solver() {
    fill(hashmap, hashmap + 128, false);
    char _s1[10002];
    char _s2[10002];
    cin.getline(_s1, 10002);
    cin.getline(_s2, 10002);
    string s1 = _s1;
    string s2 = _s2;
    for (auto _s : s2) {
        hashmap[_s] = true;
    }
    for (auto _s : s1) {
        if (!hashmap[_s]) printf("%c", _s);
    }
    return 0;
}