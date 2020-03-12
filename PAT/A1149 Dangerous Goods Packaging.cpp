//
// Created by shaob on 2020/3/12.
//

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
#include <unordered_map>
#include <unordered_set>

using namespace std;
#define INF 0x3fffffff
#define inf 0x3fffffff
/*
 * 2 pos number N (10000)& M (100)
 *
 *
 *
 */
unordered_map<int, vector<int>> bans;
int N, M;
vector<int> bags;
int a[100000];

int pat_solver() {
    scanf("%d%d", &N, &M);
    int K, _1, _2;
    for (int i = 0; i < N; ++i) {
        scanf("%d%d", &_1, &_2);
        bans[_1].push_back(_2);
        bans[_2].push_back(_1);
    }
    for (int k = 0; k < M; ++k) {
        scanf("%d", &K);
        fill(a, a + 100000, 0);
        bags.clear();
        for (int i = 0; i < K; ++i) {
            scanf("%d", &_1);
            bags.push_back(_1);
            a[_1] = 1;
        }
        bool flag = true;
        for (int &bag : bags) {
            for (int j : bans[bag]) {
                if (a[j] == 1) flag = false;
            }
        }
        flag ? printf("Yes\n") : printf("No\n");
    }
    return 0;
}

/*
测试样例



*/