//
// Created by shaob on 2020/3/4.
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

using namespace std;
#define MaxSize 0x3fffffff

struct node {
    vector<int> child;
    bool is_root = true;
} family[110];
int depthNum[110] = {0};

int max_depth = -1;

void DFS(int root_id, int depth) {
    if (family[root_id].child.empty()) {
        depthNum[depth]++;
        max_depth = max(max_depth, depth);
        return;
    }
    for (auto c:family[root_id].child) {
        DFS(c, depth + 1);
    }
}


void BFS(int root_id) {
    queue<int> Q;
    Q.push(root_id);
    int layer = 0;
    depthNum[0] = 1;
    while (!Q.empty()) {
        root_id = Q.front();
        family[root_id].child.empty() ? depthNum[layer]++ : 0;
        Q.pop();
        if (!family[root_id].child.empty()) {
            for (auto a : family[root_id].child) {
                Q.push(a);
            }
        }
    }
}

int M, N;

int pat_solver() {
    scanf("%d %d", &N, &M);
    int _, __, ___;
    for (int i = 0; i < M; ++i) {
        scanf("%d %d", &_, &__);
        for (int j = 0; j < __; ++j) {
            scanf("%d", &___);
            family[_].child.push_back(___);
            family[___].is_root = false;
        }
    }
    int root_id = 1; // 注意了，这里root_id是从1开始的。
    while (!family[root_id].is_root) root_id++;
    DFS(root_id, 0); // 我不喜欢BFS
    for (int k = 0; k <= max_depth; ++k) {
        printf("%d", depthNum[k]);
        if (k < max_depth)printf(" ");
    }
//    BFS(root_id);
    return 0;
}

/*
测试样例



*/