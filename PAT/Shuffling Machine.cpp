//
// Created by shaob on 2020/2/24.
//

#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <string>

using namespace std;

int shuffle_time = 0;
int pre[54];
int pro[54];
int shuffle_older[54];
unordered_map<int, string> card_map;

void init_map() {
    for (int i = 0; i < 54; ++i) {
        pre[i] = i;
        pro[i] = i;
    }
    int __t = 0;
    string a[4] = {"S", "H", "C", "D"};
    for (string &j : a) {
        for (int k = 1; k <= 13; ++k, ++__t) {
            card_map[__t] = j + to_string(k);
        }
    }
    card_map[__t] = "J1";
    __t++;
    card_map[__t] = "J2";
}

// 13*4 + 2
int pat_solver() {
    int __t = 0;
    scanf("%d", &shuffle_time);
    for (int &i : shuffle_older) {
        scanf("%d", &__t);
        i = __t - 1;
    } // C ++ 新特性 RANGE FOR
    init_map();
    for (int j = 0; j < shuffle_time; ++j) {
        for (int i = 0; i < 54; ++i) {
            pro[shuffle_older[i]] = pre[i];
        }
        for (int i = 0; i < 54; ++i) {
            pre[i] = pro[i];
        }
    }
    for (int k = 0; k < 54; ++k) {
        if (k == 53) {
            printf("%s", (card_map[pro[k]]).c_str());
        } else {
            printf("%s ", (card_map[pro[k]]).c_str());
        }
    }
    return 0;
}