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
#include <unordered_set>

using namespace std;
#define INF 0x3fffffff
#define inf 0x3fffffff
#define MaxSize 256
/*
 * 无向图顶点的子集，且两个不同顶点必然相邻，将这样的集合称为 clique
 * 最大 clique 是说，无法通过包含一个以上相邻顶点来扩展的情况。
 *
 */
vector<int> net[MaxSize];  // 无向图

int Nv, Ne;
int M, K;
unordered_set<int> subset;
bool vis[MaxSize];

int judge() {
    /*
     * 先判断是不是clique （遍历给定集合的所有出边）
     * 再判断是不是max (遍历给定集合外的点的所有出边，若能把当前集合内的点都访问到，那就不是最小
     */
    for (int i: subset) { // 第一步
        if (net[i].size()+1< subset.size()) {
            return 0;
        } else {
            int able_time = 0;
            for (int v:net[i]) {
                if (subset.find(v) != subset.end()) {
                    able_time++;
                }
            }
            if (able_time == subset.size()-1) {
                continue;
            } else {
                return 0;
            }
        }
    }
    // 第二步
    for (int i = 1; i <= Nv; i++) {
        if (subset.find(i) != subset.end()) continue;
        else {
            int able_time = 0;
            for (int v:net[i]) {
                if (subset.find(v) != subset.end()) {
                    able_time++;
                }
            }
            if (able_time == subset.size()) {
                return 1;
            }
        }
    }
    return 2;
}

int pat_solver() {
//    fill(net[0], net[0] + MaxSize * MaxSize, INF);
    scanf("%d%d", &Nv, &Ne);
    int _v1, _v2;
    for (int i = 1; i <= Ne; ++i) {
        scanf("%d%d", &_v1, &_v2);
        net[_v1].push_back(_v2);
        net[_v2].push_back(_v1);
    }
    scanf("%d", &M);
    for (int j = 0; j < M; ++j) {
        subset.clear();
        scanf("%d", &K);
        for (int i = 0; i < K; ++i) {
            scanf("%d", &_v1);
            subset.insert(_v1);
        }
        int flag = judge();
        if (flag == 2) {
            printf("Yes\n");
        } else if (flag == 1) {
            printf("Not Maximal\n");
        } else {
            printf("Not a Clique\n");
        }
    }

    return 0;
}

/*
测试样例



*/