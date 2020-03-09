//
// Created by shaob on 2020/3/9.
//

//  count the maximum number of trees in the forest, and for any pair of birds, tell if they are on the same tree.

#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <cassert>
#include <cmath>

using namespace std;
#define INF 0x3fffffff
#define inf 0x3fffffff
#define MaxSize 10010
int N;
int father[MaxSize];
bool isValid[MaxSize];


void Init() {
    fill(isValid, isValid + MaxSize, false);
    for (int i = 0; i < MaxSize; ++i) {
        father[i] = i;
    }
}

int findFather(int x) {
    if (x == father[x]) return x;
    else {
        int f = findFather(father[x]);
        father[x] = f;
        return f;
    }
}

bool Union(int x, int y) {
    int fx = findFather(x), fy = findFather(y);
    if (fx != fy) {
        father[fx] = fy;
    } else {
        return false;
    }
}

int Q;
set<int> fatherSet;
set<int> BirdSet;

int pat_solver() {
    Init();
    int _k, _b, _f;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &_k);
        assert(_k >= 1);
        scanf("%d", &_f);
        isValid[_f] = true;
        BirdSet.insert(_f);
        for (int j = 1; j < _k; ++j) {
            scanf("%d", &_b);
            Union(_f, _b);
            isValid[_b] = true;
            BirdSet.insert(_b);
        }
    }
    for (auto b :BirdSet) {
        fatherSet.insert(findFather(b));
    }

//    for (int l = 0; l < BirdSet.size(); ++l) { // 为啥是这个范围呢？ 魔法
//        if (isValid[l]) {
//            fatherSet.insert(findFather(l));
//        }
//    }
    printf("%zu %zu\n", fatherSet.size(), BirdSet.size());

    scanf("%d", &Q);
    for (int k = 0; k < Q; ++k) {
        scanf("%d %d", &_f, &_b);
        if (findFather(_f) == findFather(_b)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}

/*
测试样例



*/