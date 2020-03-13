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
int M, N;

struct node {
    node *left = nullptr, *right = nullptr;
    int value = -1;

    explicit node(int v) : value(v) {};
};

vector<int> inOrder, preOrder;
unordered_set<int> pre, in;
map<int, int> query;
int father[10010];
bool vis[10010];


int findFather(int x) {
    if (father[x] == x) return x;
    else {
        int f = findFather(father[x]);
        father[x] = f;
        return f;
    }
}

void Union(int x, int y) {
    int fx = findFather(x), fy = findFather(y);
    if (fx != fy) {
        father[fx] = fy;
    }
}

void Init() {
    fill(vis, vis + 100010, false);
    for (int i = 1; i <= N; ++i) {
        father[i] = i;
    }
}

void Trojan(int x) {

}

node *PreInBuildTree(node *root, int preL, int preR, int inL, int inR) {
    if (preL > preR) {
        return nullptr;
    } else {
        root = new node(preOrder[preL]);
        int k = inL;
        while (inOrder[k] != root->value) k++;
        int LLen = k - inL;
        root->left = PreInBuildTree(root->left, preL + 1, preL + LLen, inL, k - 1);
        root->right = PreInBuildTree(root->right, preL + LLen + 1, preR, k + 1, inR);
        return root;
    }
}


int pat_solver() {
    int _1, _2;
    scanf("%d%d", &M, &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &_1);
        inOrder.push_back(_1);
    }
    for (int i = 0; i < N; ++i) {
        scanf("%d", &_1);
        preOrder.push_back(_1);
        pre.insert(_1);
    }
    node *root = nullptr;
    root = PreInBuildTree(root, 0, N - 1, 0, N - 1);
    for (int j = 0; j < M; ++j) {
        int u, v;
        scanf("%d%d", &u, &v);
        bool b1 = pre.find(u) == pre.end();
        bool b2 = pre.find(v) == pre.end();
        if (b1 && b2) {
            printf("ERROR: %d and %d are not found.\n", u, v);
        } else if (b1) {
            printf("ERROR: %d is not found.\n", u);
        } else if (b2) {
            printf("ERROR: %d is not found.\n", v);
        } else {
            query[u] = v;
            query[v] = u;
        }
    }
    return 0;
}

/*
测试样例

1 2 4 5 7 9 8 3 6
4 2 9 7 5 8 1 3 6

*/