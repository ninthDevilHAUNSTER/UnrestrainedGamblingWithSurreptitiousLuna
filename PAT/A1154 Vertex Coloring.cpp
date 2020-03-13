//
// Created by shaob on 2020/3/13.
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
#define MaxSize 10010
int N, M, K;
vector<int> net[MaxSize]; // 点从0到N-1
vector<int> nodes;
unordered_set<int> colorCnt;

bool judge() {
    for (int i = 0; i < N; ++i) {
        int node_color = nodes[i];
        colorCnt.insert(node_color);
        for (auto &v:net[i]) {
            if (node_color != nodes[v]) continue;
            else return false;
        }
    }
    return true;
}

int pat_solver() {
    scanf("%d%d", &N, &M);
    int _v1, _v2;
    for (int i = 0; i < M; ++i) {
        cin >> _v1 >> _v2;
        net[_v1].push_back(_v2);
    }
    nodes.resize(N);
    scanf("%d", &K);
    for (int j = 0; j < K; ++j) {
        fill(nodes.begin(), nodes.end(), -1);
        colorCnt.clear();
        for (int i = 0; i < N; ++i) {
            cin >> nodes[i];
        }
        bool result = judge();
        if (!result) {
            printf("No\n");
        } else {
            printf("%zu-coloring\n", colorCnt.size());
        }
    }
    return 0;
}

/*
测试样例



*/