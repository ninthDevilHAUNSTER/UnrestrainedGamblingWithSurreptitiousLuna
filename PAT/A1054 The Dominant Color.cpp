//
// Created by shaob on 2020/3/1.
//


#include <iostream>
#include <set>
#include <cstdio>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

map<int, int> colorCnt;
int M, N;
pair<int, int> MAX(-1, -1);

int pat_solver() {
    int __;
    scanf("%d%d", &M, &N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            scanf("%d", &__);
            (colorCnt.find(__) == colorCnt.end()) ? (colorCnt[__] = 1) : (colorCnt[__]++);
        }
    }
    for (auto i: colorCnt) {
        if (i.second > MAX.second) {
            MAX = i;
        }
    }
    printf("%d", MAX.first);
}