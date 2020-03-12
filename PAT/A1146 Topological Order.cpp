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

using namespace std;
#define INF 0x3fffffff
#define inf 0x3fffffff
#define MaxSize 1024
vector<int> net[MaxSize];
vector<int> _net[MaxSize];
int N, M; // N 点，M边
int K;
vector<int> path;
unordered_map<int, int> outDegree, _outDegree; // 入度集合，点:出度

bool isTopologicalOrder() {
    for (int i : path) {
        if (_outDegree[i] == 0) {
            for (auto v:net[i]) {  // 这边有个bug De了我半天....
                _outDegree[v]--;
            }
        } else {
            return false;
        }
    }
    return true;
}

vector<int> result;

int pat_solver() {
    scanf("%d%d", &N, &M);
    int _1, _2;
    for (int l = 1; l < N; ++l) {
        // 初始化入度
        outDegree[l] = 0;
    }
    for (int i = 0; i < M; ++i) {
        scanf("%d%d", &_1, &_2);
        net[_1].push_back(_2);
        outDegree[_2]++;
    }
    scanf("%d", &K);
    for (int j = 0; j < K; ++j) {
        path.clear();
        for (int i = 0; i < N; ++i) {
            scanf("%d", &_1);
            path.push_back(_1);
        }
        _outDegree = outDegree;
//        for (int k = 1; k <= N; ++k) {
//            // The vertices are numbered from 1 to N.
//            _net[k] = net[k];
//        }
        if (!isTopologicalOrder()) {
            result.push_back(j);
        }
    }
    for (int k = 0; k < result.size(); ++k) {
        printf("%d", result[k]);
        if (k < result.size() - 1)printf(" ");
    }

    return 0;
}

/*
测试样例

6 8
1 2
1 3
5 2
5 4
2 3
2 6
3 4
6 4
2
1 5 2 3 6 4
5 1 2 6 3 4

*/