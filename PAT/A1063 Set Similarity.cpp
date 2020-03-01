//
// Created by shaob on 2020/3/1.
//

#include <iostream>
#include <set>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef int LL;
set<LL> sets[52];

int SizeofSetsAnd(int s1, int s2) {
    set<LL> s3;
    int da = sets[s1].size() > sets[s2].size() ? s1 : s2;
    int xiao = sets[s1].size() > sets[s2].size() ? s2 : s1;
    for (auto s:sets[da]) {
        if (sets[xiao].find(s) != sets[xiao].end()) {
            // 查找成功
            s3.insert(s);
        }
    }
    return s3.size();
}


int SizeofSetsOr(int s1, int s2) {
    set<LL> s3;
    for (auto s:sets[s1]) {
        s3.insert(s);
    }
    for (auto s:sets[s2]) {
        s3.insert(s);
    }
    return s3.size();
}

double calSimilarity(int s2, int s1) {
    // 此处的s1与s2调换位置不影响结果
    int OrLen = sets[s2].size(), AndLen = 0;
    for (auto s:sets[s1]) {
        if (sets[s2].find(s) != sets[s2].end()) {
            AndLen++;            // 查找成功，交集长度++
        } else {
            OrLen++;            // 查找失败，并集长度++
        }
    }
    return AndLen * 1.00 / OrLen;
}

int pat_solver() {
    int N, K, __, ___;
    LL _;
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &___);
        for (int j = 0; j < ___; ++j) {
            scanf("%d", &_);
            sets[i].insert(_);
        }
    }
    scanf("%d", &K);
    for (int k = 0; k < K; ++k) {
        scanf("%d%d", &___, &__);
        printf("%.1lf%%\n", 100.00 * calSimilarity(___, __));
    }

}