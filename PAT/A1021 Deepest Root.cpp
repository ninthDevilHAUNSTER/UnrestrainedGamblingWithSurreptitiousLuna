//
// Created by shaob on 2020/3/5.
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
#define MaxSize 10010

int N;
vector<int> G[MaxSize];
bool vis[MaxSize];
set<int> A;
set<int> result;
int treeHeight = -1;

void DFS1(int node) {
    vis[node] = true;
    for (auto n : G[node]) {
        if (!vis[n]) DFS1(n);
    }
}

void DFS2(int node, int height) {
    /*
     * 之前写的有些问题，没有考虑到最大高度
     */
    vis[node] = true;
    if (G[node].size() == 1) {
        if (height > treeHeight) {
            treeHeight = height;
            A.clear();
            A.insert(node);
        } else if (height == treeHeight) {
            A.insert(node);
        }
    }
    for (int i : G[node]) {
        if (!vis[i])
            DFS2(i, height + 1);
    }

    /*
    vis[node] = true;
    if (G[node].size() == 1) {
        A.insert(node);
    } else {
        for (auto n:G[node]) {
            if (!vis[n]) DFS2(n);
        }
    }
     */
}

void DFS3(int node, int height, int pre) {
    /*
     * 我感觉我自己的理解还是有问题，但是捕捉不到错在哪里，用答案给的DFS看看
     */
    if (height > treeHeight) {
        treeHeight = height;
        A.clear();
        A.insert(node);
    } else if (height == treeHeight) {
        A.insert(node);
    }
    for (int i = 0; i < G[node].size(); i++) {
        if (G[node][i] == pre) continue;
        DFS3(G[node][i], height + 1, node);
    }
}

int pat_solver() {
    scanf("%d", &N);
    int _, __;
    for (int i = 1; i < N; ++i) {
        scanf("%d%d", &_, &__);
        G[_].push_back(__);
        G[__].push_back(_);
    }
    /// special judgement
    if (N == 1) printf("1\n");

    /// components calculation;
    int components = 0;
    fill(vis, vis + MaxSize, false);
    for (int j = 1; j <= N; ++j) {
        if (!vis[j]) {
            DFS1(j);
            components++;
        }
    }
    if (components > 1) {
        printf("Error: %d components", components);
        return 0;
    }
    /// transfer graph
    fill(vis, vis + MaxSize, false);
    DFS2(1, 1);
    result = A;
    fill(vis, vis + MaxSize, false);
    DFS2(*A.begin(), 1); // 2 和 3 都是可以的，都是我的写法。
    // 之前对于并集的操作了解不透彻，实际上不能直接把A给传进去，因为在这个过程中A会被clear掉。
    // 应该找个东西来保存它。总之是很有意思的一道题目
    for (auto a:A) {
        result.insert(a);
    }
    /// printf result
    for (auto n : result) {
        printf("%d\n", n);
    }
    return 0;
}

/*
测试样例


6
1 6
6 3
6 2
3 4
2 5


*/